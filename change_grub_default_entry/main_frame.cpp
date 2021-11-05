#include "framework.h"


namespace app_simple_change_grub_default_entry
{


   main_frame::main_frame()
   {

      m_bDefaultCreateToolbar = false;

      m_bDefaultNotifyIcon = true;

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

      auto pframe = get_frame_experience(nullptr, "008", "LightBlue");

      return pframe;

   }


} // namespace app_simple_change_grub_default_entry



