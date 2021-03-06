/**
    gTox a GTK-based tox-client - https://github.com/KoKuToru/gTox.git

    Copyright (C) 2015  Luca Béla Palkovics

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
**/
#ifndef WIDGETCHATTEXTVIEW_H
#define WIDGETCHATTEXTVIEW_H

#include <gtkmm.h>
#include "utils/builder.h"
#include "utils/debug.h"

namespace widget {
    class chat_input: public Gtk::TextView, public utils::debug::track_obj<chat_input> {
        private:
            Glib::RefPtr<Gtk::TextBuffer::Tag> m_bold_tag;
            Glib::RefPtr<Gtk::TextBuffer::Tag> m_italic_tag;
            Glib::RefPtr<Gtk::TextBuffer::Tag> m_underline_tag;

            Glib::RefPtr<Gtk::TextBuffer> m_buffer;

        public:
            chat_input(BaseObjectType* cobject, utils::builder);
            virtual ~chat_input();

            Glib::ustring get_serialized_text();
    };
}

#endif
