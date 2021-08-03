#include "framework.h"


namespace simple_application
{


   main_frame::main_frame()
   {

      //m_bFramePayloadFlags = true;

      set_bitmap_source("Simple papplication!!");

      m_bDefaultCreateToolbar = false;

      window_enable_full_screen();

      m_etranslucencyFrame = ::user::e_translucency_present;

   }


   main_frame::~main_frame()
   {

   }


   void main_frame::assert_valid() const
   {

      simple_frame_window::assert_valid();

   }


   void main_frame::dump(dump_context & dumpcontext) const
   {

      simple_frame_window::dump(dumpcontext);

   }


   ::experience::frame * main_frame::experience_get_frame()
   {

      auto pframe = get_frame_experience("", "013", "LightBlue");

      return pframe;

   }


   bool main_frame::has_pending_graphical_update()
   {

      return ::simple_frame_window::has_pending_graphical_update();

   }



} // namespace simple_application



