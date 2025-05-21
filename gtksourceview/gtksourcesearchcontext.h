/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; coding: utf-8 -*-
 *
 * This file is part of GtkSourceView
 *
 * Copyright (C) 2013, 2016 - Sébastien Wilmet <swilmet@gnome.org>
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

#ifndef GTK_SOURCE_SEARCH_CONTEXT_H
#define GTK_SOURCE_SEARCH_CONTEXT_H

#if !defined (GTK_SOURCE_H_INSIDE) && !defined (GTK_SOURCE_COMPILATION)
#error "Only <gtksourceview/gtksource.h> can be included directly."
#endif

#include <gtk/gtk.h>
#include <gtksourceview/gtksourcetypes.h>
#include <gtksourceview/gtksourcestyle.h>

G_BEGIN_DECLS

#define GTK_SOURCE_TYPE_SEARCH_CONTEXT             (gtk_source_search_context_get_type ())
#define GTK_SOURCE_SEARCH_CONTEXT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_SOURCE_TYPE_SEARCH_CONTEXT, GtkSourceSearchContext))
#define GTK_SOURCE_SEARCH_CONTEXT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_SOURCE_TYPE_SEARCH_CONTEXT, GtkSourceSearchContextClass))
#define GTK_SOURCE_IS_SEARCH_CONTEXT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_SOURCE_TYPE_SEARCH_CONTEXT))
#define GTK_SOURCE_IS_SEARCH_CONTEXT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_SOURCE_TYPE_SEARCH_CONTEXT))
#define GTK_SOURCE_SEARCH_CONTEXT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_SOURCE_TYPE_SEARCH_CONTEXT, GtkSourceSearchContextClass))

typedef struct _GtkSourceSearchContextClass    GtkSourceSearchContextClass;
typedef struct _GtkSourceSearchContextPrivate  GtkSourceSearchContextPrivate;

struct _GtkSourceSearchContext
{
	GObject parent;

	GtkSourceSearchContextPrivate *priv;
};

struct _GtkSourceSearchContextClass
{
	GObjectClass parent_class;

	gpointer padding[10];
};

G_MODULE_EXPORT
GType			 gtk_source_search_context_get_type			(void) G_GNUC_CONST;

G_MODULE_EXPORT
GtkSourceSearchContext	*gtk_source_search_context_new				(GtkSourceBuffer	 *buffer,
										 GtkSourceSearchSettings *settings);

G_MODULE_EXPORT
GtkSourceBuffer		*gtk_source_search_context_get_buffer			(GtkSourceSearchContext  *search);

G_MODULE_EXPORT
GtkSourceSearchSettings	*gtk_source_search_context_get_settings			(GtkSourceSearchContext	 *search);

G_MODULE_EXPORT
gboolean		 gtk_source_search_context_get_highlight		(GtkSourceSearchContext  *search);

G_MODULE_EXPORT
void			 gtk_source_search_context_set_highlight		(GtkSourceSearchContext  *search,
										 gboolean                 highlight);

G_MODULE_EXPORT
GtkSourceStyle		*gtk_source_search_context_get_match_style		(GtkSourceSearchContext  *search);

G_MODULE_EXPORT
void			 gtk_source_search_context_set_match_style		(GtkSourceSearchContext  *search,
										 GtkSourceStyle          *match_style);

G_MODULE_EXPORT
GError			*gtk_source_search_context_get_regex_error		(GtkSourceSearchContext	 *search);

G_MODULE_EXPORT
gint			 gtk_source_search_context_get_occurrences_count	(GtkSourceSearchContext	 *search);

G_MODULE_EXPORT
gint			 gtk_source_search_context_get_occurrence_position	(GtkSourceSearchContext	 *search,
										 const GtkTextIter	 *match_start,
										 const GtkTextIter	 *match_end);

G_MODULE_EXPORT
gboolean		 gtk_source_search_context_forward			(GtkSourceSearchContext *search,
										 const GtkTextIter      *iter,
										 GtkTextIter            *match_start,
										 GtkTextIter            *match_end,
										 gboolean               *has_wrapped_around);

G_MODULE_EXPORT
void			 gtk_source_search_context_forward_async		(GtkSourceSearchContext	 *search,
										 const GtkTextIter	 *iter,
										 GCancellable		 *cancellable,
										 GAsyncReadyCallback	  callback,
										 gpointer		  user_data);

G_MODULE_EXPORT
gboolean		 gtk_source_search_context_forward_finish		(GtkSourceSearchContext  *search,
										 GAsyncResult            *result,
										 GtkTextIter             *match_start,
										 GtkTextIter             *match_end,
										 gboolean                *has_wrapped_around,
										 GError                 **error);

G_MODULE_EXPORT
gboolean		 gtk_source_search_context_backward			(GtkSourceSearchContext *search,
										 const GtkTextIter      *iter,
										 GtkTextIter            *match_start,
										 GtkTextIter            *match_end,
										 gboolean               *has_wrapped_around);

G_MODULE_EXPORT
void			 gtk_source_search_context_backward_async		(GtkSourceSearchContext	 *search,
										 const GtkTextIter	 *iter,
										 GCancellable		 *cancellable,
										 GAsyncReadyCallback	  callback,
										 gpointer		  user_data);

G_MODULE_EXPORT
gboolean		 gtk_source_search_context_backward_finish		(GtkSourceSearchContext  *search,
										 GAsyncResult            *result,
										 GtkTextIter             *match_start,
										 GtkTextIter             *match_end,
										 gboolean                *has_wrapped_around,
										 GError                 **error);

G_MODULE_EXPORT
gboolean		 gtk_source_search_context_replace			(GtkSourceSearchContext  *search,
										 GtkTextIter             *match_start,
										 GtkTextIter             *match_end,
										 const gchar             *replace,
										 gint                     replace_length,
										 GError                 **error);

G_MODULE_EXPORT
guint			 gtk_source_search_context_replace_all			(GtkSourceSearchContext	 *search,
										 const gchar		 *replace,
										 gint			  replace_length,
										 GError			**error);

G_GNUC_INTERNAL
void			 _gtk_source_search_context_update_highlight		(GtkSourceSearchContext	 *search,
										 const GtkTextIter	 *start,
										 const GtkTextIter	 *end,
										 gboolean		  synchronous);

G_END_DECLS

#endif /* GTK_SOURCE_SEARCH_CONTEXT_H */
