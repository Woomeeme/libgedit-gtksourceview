/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; coding: utf-8 -*-
 *
 * This file is part of GtkSourceView
 *
 * Copyright (C) 2013 - Sébastien Wilmet <swilmet@gnome.org>
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

#ifndef GTK_SOURCE_UTILS_H
#define GTK_SOURCE_UTILS_H

#if !defined (GTK_SOURCE_H_INSIDE) && !defined (GTK_SOURCE_COMPILATION)
#error "Only <gtksourceview/gtksource.h> can be included directly."
#endif

#include <gtksourceview/gtksourcebuffer.h>

G_BEGIN_DECLS

G_MODULE_EXPORT
gchar *		gtk_source_utils_unescape_search_text		(const gchar *text);

G_MODULE_EXPORT
gchar *		gtk_source_utils_escape_search_text		(const gchar *text);

G_MODULE_EXPORT
gchar *		gtk_source_utils_get_bracket_matched_message	(GtkTextIter               *iter,
								 GtkSourceBracketMatchType  state);

G_END_DECLS

#endif /* GTK_SOURCE_UTILS_H */
