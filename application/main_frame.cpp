#include "framework.h"
#include "main_frame.h"
#include "acme/constant/message.h"


namespace app_simple_application
{


   main_frame::main_frame()
   {

      //m_bFramePayloadFlags = true;

      //m_bDefaultCreateToolbar = false;

      window_enable_full_screen();

      m_etranslucencyFrame = ::user::e_translucency_present;

   }


   main_frame::~main_frame()
   {

   }


//   void main_frame::assert_ok() const
//   {
//
//      simple_frame_window::assert_ok();
//
//   }
//
//
//   void main_frame::dump(dump_context & dumpcontext) const
//   {
//
//      simple_frame_window::dump(dumpcontext);
//
//   }


   ::experience::frame * main_frame::frame_experience()
   {

      auto pframe = ::simple_main_frame::frame_experience("", "013", "LightBlue");

      return pframe;

   }


   bool main_frame::has_pending_graphical_update()
   {

      return ::simple_main_frame::has_pending_graphical_update();

   }


   void main_frame::install_message_routing(::channel * pchannel)
   {

      simple_main_frame::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &simple_main_frame::on_message_create);

   }


   void main_frame::on_message_create(::message::message * pmessage)
   {

      set_bitmap_source("Simple papp!!");

   }


} // namespace simple_application



