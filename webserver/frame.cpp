﻿#include "framework.h"


namespace simple_webserver
{


   frame::frame()
   {

      m_bDefaultCreateToolbar = false;

   }


   frame::~frame()
   {

   }


   void frame::assert_valid() const
   {

      simple_frame_window::assert_valid();

   }


   void frame::dump(dump_context & dumpcontext) const
   {

      simple_frame_window::dump(dumpcontext);

   }


   /*bool frame::get_translucency(::user::enum_translucency & etranslucency, ::user::enum_element eelement, ::user::style_context * pinteraction)
   {

      etranslucency = ::user::e_translucency_present;

      return true;

   }*/


} // namespace simple_webserver







