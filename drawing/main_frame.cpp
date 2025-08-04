#include "framework.h"
#include "main_frame.h"
#include "acme/constant/message.h"


namespace app_simple_drawing
{


   main_frame::main_frame()
   {

#if REFERENCING_DEBUGGING

      //m_bIncludeCallStackTrace = true;

#endif

      //m_ewindowflag += window_flag_miniaturizable;

      //m_bDefaultCreateToolbar = false;

      window_enable_full_screen();

   }


   main_frame::~main_frame()
   {

   }


   ::pointer < ::experience::frame > main_frame::frame_experience()
   {

      auto pframe = ::simple_main_frame::frame_experience(nullptr, "022", "LightBlue");

      return pframe;

   }


#ifdef DEBUG


   long long main_frame::increment_reference_count()
   {

      //~ if(m_preferenceitema->m_iStep == 211)
      //~ {

         //~ ::output_debug_string("211");

      //~ }

      return ::simple_main_frame::increment_reference_count();

   }



   long long main_frame::decrement_reference_count()
   {

      return ::simple_main_frame::decrement_reference_count();

   }


#endif


//   bool main_frame::has_pending_graphical_update()
//   {
//
//      return ::simple_frame_window::has_pending_graphical_update();
//
//   }


   //bool main_frame::get_translucency(::user::enum_translucency & etranslucency, ::enum_element eelement, ::user::style_context * pcontext)
   //{

   //   if (m_bExplicitTranslucency)
   //   {

   //      etranslucency = m_etranslucency;

   //      return true;

   //   }

   //   //if (userstyle() != NULL)
   //   //{

   //   //   if (m_puserstyle->_001GetMainFrameTranslucency(etranslucency))
   //   //      return true;

   //   //}
   //   //etranslucency = ::user::e_translucency_present;

   //   ////      etranslucency = ::user::e_translucency_none;

   //   //return true;

   //   return ::user::style::get_translucency(etranslucency, eelement, pcontext);

   //}


   void main_frame::install_message_routing(::channel * pchannel)
   {

      simple_frame_window::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &simple_main_frame::on_message_create);

   }


   void main_frame::on_message_create(::message::message * pmessage)
   {

      set_bitmap_source("Simple Drawing!!");

   }


} // namespace simple_drawing







