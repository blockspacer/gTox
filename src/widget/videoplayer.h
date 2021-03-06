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
#ifndef GTOX_VIDEO_PLAYER_H
#define GTOX_VIDEO_PLAYER_H

#include "utils/gstreamer.h"
#include "utils/builder.h"
#include "widget/imagescaled.h"
#include "utils/debug.h"

namespace widget {
    class videoplayer: public Gtk::Box, public utils::debug::track_obj<videoplayer> {
        private:
            utils::gstreamer m_streamer;

            Gtk::EventBox*       m_eventbox;
            widget::imagescaled* m_video;
            Gtk::Box*            m_control;
            Gtk::Scale*          m_seek;
            Gtk::ToggleButton*   m_play_btn;
            Gtk::ToggleButton*   m_pause_btn;
            Gtk::ToggleButton*   m_stop_btn;
            Gtk::Label*          m_position;
            Gtk::Label*          m_duration;
            Gtk::VolumeButton*   m_volume;

            sigc::connection m_leave_timer;

            std::vector<Glib::RefPtr<Glib::Binding>> m_bindings;

            // no idea why I can't do this directly in videoplayer
            class property_helper: public Glib::Object {
                public:
                    Glib::Property<Glib::RefPtr<Gdk::Pixbuf>> m_property_preview_pixbuf;
                    property_helper():
                        Glib::ObjectBase(typeid(property_helper)),
                        m_property_preview_pixbuf(*this, "videoplayer-preview-image") {}
            } m_property_helper;

        public:
            videoplayer(BaseObjectType* cobject,
                        utils::builder builder);
            ~videoplayer();

            auto property_uri() {
                return m_streamer.property_uri();
            }

            Glib::PropertyProxy<Glib::RefPtr<Gdk::Pixbuf>> property_preview_pixbuf();

            static utils::builder::ref<videoplayer> create();
    };
}

#endif
