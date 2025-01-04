#include "framework.h"
#include "main_frame.h"


namespace app_simple_change_grub_default_entry
{


   main_frame::main_frame()
   {

      //m_bDefaultCreateToolbar = false;

      enable_default_notification_icon();

   }


   main_frame::~main_frame()
   {

   }


   //void main_frame::assert_ok() const
   //{

   //   simple_frame_window::assert_ok();

   //}


   //void main_frame::dump(dump_context & dumpcontext) const
   //{

   //   simple_frame_window::dump(dumpcontext);

   //}


   ::pointer < ::experience::frame > main_frame::frame_experience()
   {

      auto pframe = ::simple_main_frame::frame_experience(nullptr, "008", "LightBlue");

      return pframe;

   }


} // namespace app_simple_change_grub_default_entry



