/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; coding: utf-8 -*-
 *
 * This file is part of GtkSourceView
 *
 * Copyright (C) 2001 - Mikael Hermansson <tyan@linux.se> and
 *                       Chris Phelps <chicane@reninet.com>
 * Copyright (C) 2003 - Gustavo Giráldez and Paolo Maggi
 *
 * GtkSourceView is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * GtkSourceView is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GTK_SOURCE_VIEW_H
#define GTK_SOURCE_VIEW_H

#if !defined (GTK_SOURCE_H_INSIDE) && !defined (GTK_SOURCE_COMPILATION)
#error "Only <gtksourceview/gtksource.h> can be included directly."
#endif

#include <gtk/gtk.h>
#include <gtksourceview/gtksourcetypes.h>

G_BEGIN_DECLS

#define GTK_SOURCE_TYPE_VIEW             (gtk_source_view_get_type ())
#define GTK_SOURCE_VIEW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_SOURCE_TYPE_VIEW, GtkSourceView))
#define GTK_SOURCE_VIEW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_SOURCE_TYPE_VIEW, GtkSourceViewClass))
#define GTK_SOURCE_IS_VIEW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_SOURCE_TYPE_VIEW))
#define GTK_SOURCE_IS_VIEW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_SOURCE_TYPE_VIEW))
#define GTK_SOURCE_VIEW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_SOURCE_TYPE_VIEW, GtkSourceViewClass))

typedef struct _GtkSourceViewClass GtkSourceViewClass;
typedef struct _GtkSourceViewPrivate GtkSourceViewPrivate;

/**
 * GtkSourceViewGutterPosition:
 * @GTK_SOURCE_VIEW_GUTTER_POSITION_LINES: the gutter position of the lines
 * renderer
 * @GTK_SOURCE_VIEW_GUTTER_POSITION_MARKS: the gutter position of the marks
 * renderer
 */
typedef enum _GtkSourceViewGutterPosition
{
	GTK_SOURCE_VIEW_GUTTER_POSITION_LINES = -30,
	GTK_SOURCE_VIEW_GUTTER_POSITION_MARKS = -20
} GtkSourceViewGutterPosition;

/**
 * GtkSourceSmartHomeEndType:
 * @GTK_SOURCE_SMART_HOME_END_DISABLED: smart-home-end disabled.
 * @GTK_SOURCE_SMART_HOME_END_BEFORE: move to the first/last
 * non-whitespace character on the first press of the HOME/END keys and
 * to the beginning/end of the line on the second press.
 * @GTK_SOURCE_SMART_HOME_END_AFTER: move to the beginning/end of the
 * line on the first press of the HOME/END keys and to the first/last
 * non-whitespace character on the second press.
 * @GTK_SOURCE_SMART_HOME_END_ALWAYS: always move to the first/last
 * non-whitespace character when the HOME/END keys are pressed.
 */
typedef enum _GtkSourceSmartHomeEndType
{
	GTK_SOURCE_SMART_HOME_END_DISABLED,
	GTK_SOURCE_SMART_HOME_END_BEFORE,
	GTK_SOURCE_SMART_HOME_END_AFTER,
	GTK_SOURCE_SMART_HOME_END_ALWAYS
} GtkSourceSmartHomeEndType;

struct _GtkSourceView
{
	GtkTextView parent;

	GtkSourceViewPrivate *priv;
};

struct _GtkSourceViewClass
{
	GtkTextViewClass parent_class;

	void (*undo) (GtkSourceView *view);
	void (*redo) (GtkSourceView *view);
	void (*line_mark_activated) (GtkSourceView *view,
	                             GtkTextIter   *iter,
	                             GdkEvent      *event);
	void (*show_completion) (GtkSourceView *view);
	void (*move_lines) (GtkSourceView *view,
			    gboolean       down);

	void (*move_words) (GtkSourceView *view,
	                    gint           step);

	/* Padding for future expansion */
	gpointer padding[20];
};

G_MODULE_EXPORT
GType		 gtk_source_view_get_type		(void) G_GNUC_CONST;

G_MODULE_EXPORT
GtkWidget	*gtk_source_view_new			(void);

G_MODULE_EXPORT
GtkWidget 	*gtk_source_view_new_with_buffer	(GtkSourceBuffer *buffer);

G_MODULE_EXPORT
void		 gtk_source_view_set_show_line_numbers 	(GtkSourceView   *view,
							 gboolean         show);

G_MODULE_EXPORT
gboolean 	 gtk_source_view_get_show_line_numbers 	(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_tab_width          (GtkSourceView   *view,
							 guint            width);

G_MODULE_EXPORT
guint            gtk_source_view_get_tab_width          (GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_indent_width 	(GtkSourceView   *view,
							 gint             width);

G_MODULE_EXPORT
gint		 gtk_source_view_get_indent_width	(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_auto_indent 	(GtkSourceView   *view,
							 gboolean         enable);

G_MODULE_EXPORT
gboolean	 gtk_source_view_get_auto_indent 	(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_insert_spaces_instead_of_tabs
							(GtkSourceView   *view,
							 gboolean         enable);

G_MODULE_EXPORT
gboolean	 gtk_source_view_get_insert_spaces_instead_of_tabs
							(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_indent_on_tab 	(GtkSourceView   *view,
							 gboolean         enable);

G_MODULE_EXPORT
gboolean	 gtk_source_view_get_indent_on_tab 	(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_indent_lines		(GtkSourceView   *view,
							 GtkTextIter     *start,
							 GtkTextIter     *end);

G_MODULE_EXPORT
void		 gtk_source_view_unindent_lines		(GtkSourceView   *view,
							 GtkTextIter     *start,
							 GtkTextIter     *end);

G_MODULE_EXPORT
void		 gtk_source_view_set_highlight_current_line
							(GtkSourceView   *view,
							 gboolean         highlight);

G_MODULE_EXPORT
gboolean 	 gtk_source_view_get_highlight_current_line
							(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_show_right_margin 	(GtkSourceView   *view,
							 gboolean         show);

G_MODULE_EXPORT
gboolean 	 gtk_source_view_get_show_right_margin 	(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_right_margin_position
					 		(GtkSourceView   *view,
							 guint            pos);

G_MODULE_EXPORT
guint		 gtk_source_view_get_right_margin_position
					 		(GtkSourceView   *view);

G_MODULE_EXPORT
void 		 gtk_source_view_set_show_line_marks    (GtkSourceView   *view,
							 gboolean         show);

G_MODULE_EXPORT
gboolean	 gtk_source_view_get_show_line_marks    (GtkSourceView   *view);

G_MODULE_EXPORT
void             gtk_source_view_set_mark_attributes    (GtkSourceView           *view,
                                                         const gchar             *category,
                                                         GtkSourceMarkAttributes *attributes,
                                                         gint                     priority);

G_MODULE_EXPORT
GtkSourceMarkAttributes *
                 gtk_source_view_get_mark_attributes    (GtkSourceView           *view,
                                                         const gchar             *category,
                                                         gint                    *priority);

G_MODULE_EXPORT
void		 gtk_source_view_set_smart_backspace	(GtkSourceView   *view,
							 gboolean        smart_backspace);

G_MODULE_EXPORT
gboolean	 gtk_source_view_get_smart_backspace	(GtkSourceView   *view);

G_MODULE_EXPORT
void		 gtk_source_view_set_smart_home_end	(GtkSourceView             *view,
							 GtkSourceSmartHomeEndType  smart_home_end);

G_MODULE_EXPORT
GtkSourceSmartHomeEndType
		 gtk_source_view_get_smart_home_end	(GtkSourceView   *view);

G_MODULE_EXPORT
guint		 gtk_source_view_get_visual_column	(GtkSourceView     *view,
							 const GtkTextIter *iter);

G_MODULE_EXPORT
GtkSourceCompletion *
		 gtk_source_view_get_completion		(GtkSourceView   *view);

G_MODULE_EXPORT
GtkSourceGutter *gtk_source_view_get_gutter		(GtkSourceView     *view,
                                                         GtkTextWindowType  window_type);

G_MODULE_EXPORT
GtkSourceSpaceDrawer *
		 gtk_source_view_get_space_drawer	(GtkSourceView   *view);

G_END_DECLS

#endif /* end of GTK_SOURCE_VIEW_H */
