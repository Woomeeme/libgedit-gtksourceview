/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; coding: utf-8 -*-
 *
 * This file is part of GtkSourceView
 *
 * Copyright (C) 2003  Gustavo Giráldez
 * Copyright (C) 2007-2008  Paolo Maggi, Paolo Borelli and Yevgen Muntyan
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

#ifndef GTK_SOURCE_PRINT_COMPOSITOR_H
#define GTK_SOURCE_PRINT_COMPOSITOR_H

#if !defined (GTK_SOURCE_H_INSIDE) && !defined (GTK_SOURCE_COMPILATION)
#error "Only <gtksourceview/gtksource.h> can be included directly."
#endif

#include <gtk/gtk.h>
#include <gtksourceview/gtksourcetypes.h>

G_BEGIN_DECLS

#define GTK_SOURCE_TYPE_PRINT_COMPOSITOR            (gtk_source_print_compositor_get_type ())
#define GTK_SOURCE_PRINT_COMPOSITOR(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_SOURCE_TYPE_PRINT_COMPOSITOR, GtkSourcePrintCompositor))
#define GTK_SOURCE_PRINT_COMPOSITOR_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_SOURCE_TYPE_PRINT_COMPOSITOR, GtkSourcePrintCompositorClass))
#define GTK_SOURCE_IS_PRINT_COMPOSITOR(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_SOURCE_TYPE_PRINT_COMPOSITOR))
#define GTK_SOURCE_IS_PRINT_COMPOSITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_SOURCE_TYPE_PRINT_COMPOSITOR))
#define GTK_SOURCE_PRINT_COMPOSITOR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_SOURCE_TYPE_PRINT_COMPOSITOR, GtkSourcePrintCompositorClass))

typedef struct _GtkSourcePrintCompositorClass    GtkSourcePrintCompositorClass;
typedef struct _GtkSourcePrintCompositorPrivate  GtkSourcePrintCompositorPrivate;

struct _GtkSourcePrintCompositor
{
	GObject parent_instance;

	GtkSourcePrintCompositorPrivate *priv;
};

struct _GtkSourcePrintCompositorClass
{
	GObjectClass parent_class;

	/* Padding for future expansion */
	gpointer padding[10];
};

G_MODULE_EXPORT
GType			  gtk_source_print_compositor_get_type		(void) G_GNUC_CONST;


G_MODULE_EXPORT
GtkSourcePrintCompositor *gtk_source_print_compositor_new		(GtkSourceBuffer          *buffer);

G_MODULE_EXPORT
GtkSourcePrintCompositor *gtk_source_print_compositor_new_from_view	(GtkSourceView            *view);


G_MODULE_EXPORT
GtkSourceBuffer   	 *gtk_source_print_compositor_get_buffer	(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_tab_width	(GtkSourcePrintCompositor *compositor,
									 guint                     width);

G_MODULE_EXPORT
guint			  gtk_source_print_compositor_get_tab_width	(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_wrap_mode	(GtkSourcePrintCompositor *compositor,
									 GtkWrapMode               wrap_mode);

G_MODULE_EXPORT
GtkWrapMode		  gtk_source_print_compositor_get_wrap_mode	(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_highlight_syntax
									(GtkSourcePrintCompositor *compositor,
									 gboolean                  highlight);

G_MODULE_EXPORT
gboolean		  gtk_source_print_compositor_get_highlight_syntax
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_print_line_numbers
									(GtkSourcePrintCompositor *compositor,
									 guint                     interval);

G_MODULE_EXPORT
guint			  gtk_source_print_compositor_get_print_line_numbers
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_body_font_name
									(GtkSourcePrintCompositor *compositor,
									 const gchar              *font_name);

G_MODULE_EXPORT
gchar			 *gtk_source_print_compositor_get_body_font_name
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_line_numbers_font_name
									(GtkSourcePrintCompositor *compositor,
									 const gchar              *font_name);

G_MODULE_EXPORT
gchar			 *gtk_source_print_compositor_get_line_numbers_font_name
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_header_font_name
									(GtkSourcePrintCompositor *compositor,
									 const gchar              *font_name);

G_MODULE_EXPORT
gchar			 *gtk_source_print_compositor_get_header_font_name
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_footer_font_name
									(GtkSourcePrintCompositor *compositor,
									 const gchar              *font_name);

G_MODULE_EXPORT
gchar			 *gtk_source_print_compositor_get_footer_font_name
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
gdouble			  gtk_source_print_compositor_get_top_margin	(GtkSourcePrintCompositor *compositor,
									 GtkUnit                   unit);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_top_margin	(GtkSourcePrintCompositor *compositor,
									 gdouble                   margin,
									 GtkUnit                   unit);

G_MODULE_EXPORT
gdouble			  gtk_source_print_compositor_get_bottom_margin	(GtkSourcePrintCompositor *compositor,
									 GtkUnit                   unit);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_bottom_margin	(GtkSourcePrintCompositor *compositor,
									 gdouble                   margin,
									 GtkUnit                   unit);

G_MODULE_EXPORT
gdouble			  gtk_source_print_compositor_get_left_margin	(GtkSourcePrintCompositor *compositor,
									 GtkUnit                   unit);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_left_margin	(GtkSourcePrintCompositor *compositor,
									 gdouble                   margin,
									 GtkUnit                   unit);

G_MODULE_EXPORT
gdouble			  gtk_source_print_compositor_get_right_margin	(GtkSourcePrintCompositor *compositor,
									 GtkUnit                   unit);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_right_margin	(GtkSourcePrintCompositor *compositor,
									 gdouble                   margin,
									 GtkUnit                   unit);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_print_header	(GtkSourcePrintCompositor *compositor,
									 gboolean                  print);

G_MODULE_EXPORT
gboolean		  gtk_source_print_compositor_get_print_header	(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_print_footer	(GtkSourcePrintCompositor *compositor,
									 gboolean                  print);

G_MODULE_EXPORT
gboolean		  gtk_source_print_compositor_get_print_footer	(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_header_format	(GtkSourcePrintCompositor *compositor,
									 gboolean                  separator,
									 const gchar              *left,
									 const gchar              *center,
									 const gchar              *right);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_set_footer_format	(GtkSourcePrintCompositor *compositor,
									 gboolean                  separator,
									 const gchar              *left,
									 const gchar              *center,
									 const gchar              *right);

G_MODULE_EXPORT
gint			  gtk_source_print_compositor_get_n_pages	(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
gboolean		  gtk_source_print_compositor_paginate		(GtkSourcePrintCompositor *compositor,
									 GtkPrintContext          *context);

G_MODULE_EXPORT
gdouble			  gtk_source_print_compositor_get_pagination_progress
									(GtkSourcePrintCompositor *compositor);

G_MODULE_EXPORT
void			  gtk_source_print_compositor_draw_page		(GtkSourcePrintCompositor *compositor,
									 GtkPrintContext          *context,
									 gint                      page_nr);

G_END_DECLS

#endif /* GTK_SOURCE_PRINT_COMPOSITOR_H */
