#include "framework.h"
#include "aura/message/user.h"
#include "berg/user/user/impact_system.h"


namespace app_simple_os_drag_and_drop
{


   impact::impact()
   {

      payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);


   }


   impact::~impact()
   {

   }


   //void impact::assert_ok() const
   //{

   //   user::box::assert_ok();

   //}


   //void impact::dump(dump_context & dumpcontext) const
   //{

   //   user::box::dump(dumpcontext);

   //}


#ifdef _DEBUG


   long long impact::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long impact::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void impact::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(::user::e_message_create,psender,this,&impact::on_message_create);
      MESSAGE_LINK(::user::e_message_destroy, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      //auto estatus = 
      
      øconstruct_new(m_psimpleosdraganddrop);

      //if (!estatus)
      //{

      //   pcreate->set_fail();

      //   return;

      //}

      m_psimpleosdraganddrop->m_pimpact = this;

      string strId = get_document()->m_pimpactsystem->id();

      string strText;

      if(get_typed_parent<::user::split_impact>() != nullptr)
      {

         if(get_typed_parent<::user::split_impact>()->get_child_by_id("top_edit_impact") != nullptr)
         {

            auto pinteraction = get_typed_parent<::user::split_impact>()->get_child_by_id("top_edit_impact");

            pinteraction->set_text(strText,::e_source_initialize);

         }

      }

   }


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      ::user::impact::handle(ptopic, phandlercontext);
   }


   ::user::document * impact::get_document()
   {

      return ::user::impact::get_document();

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      m_psimpleosdraganddrop->_001OnDraw(pgraphics);

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      if(rectangleX.is_empty())
      {

         return;

      }

      m_psimpleosdraganddrop->m_rectangle = rectangleX;

   }


} // namespace app_simple_os_drag_and_drop



