/* SPDX-License-Identifier: Zlib */

#include "plugin.h"

ZATHURA_PLUGIN_REGISTER_WITH_FUNCTIONS("jpg", VERSION_MAJOR, VERSION_MINOR, VERSION_REV,
                                       ZATHURA_PLUGIN_FUNCTIONS({
                                           .document_open            = jpg_document_open,
                                           .document_free            = jpg_document_free,
                                           .page_init                = jpg_page_init,
                                           .page_clear               = jpg_page_clear,
                                           .page_render_cairo        = jpg_page_render_cairo,
                                       }),
                                       ZATHURA_PLUGIN_MIMETYPES({
                                           "image/jpeg",
                                       }))
