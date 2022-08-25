#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif
#include <math.h>
#include "acme/id.h"
#include "aura/graphics/draw2d/_component.h"
#include "acme/platform/hyperlink.h"


namespace app_simple_networking_application
{


   impact::impact()
   {

      //payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);

      m_bClickDefaultMouseHandling = true;

   }


   impact::~impact()
   {

   }


   void impact::assert_ok() const
   {

      user::box::assert_ok();

   }


   void impact::dump(dump_context & dumpcontext) const
   {

      user::box::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void impact::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&impact::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      //initialize_application_composer();

      m_papp->create_networking_application();

      {

         auto psignal = m_papp->get_signal("simple_checkbox");

         psignal->add_handler(this);

      }

      {

         auto psignal = m_papp->get_signal("no_client_frame");

         psignal->add_handler(this);

      }


      string strId = get_document()->m_pimpactsystem->m_atom;

      string strText;

      if(GetTypedParent<::user::split_impact>() != nullptr)
      {

         if(GetTypedParent<::user::split_impact>()->get_child_by_id("top_edit_impact") != nullptr)
         {

            auto pinteraction = GetTypedParent<::user::split_impact>()->get_child_by_id("top_edit_impact");

            pinteraction->_001SetText(strText,::e_source_initialize);

         }

      }

   }


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->m_atom == "simple_checkbox"
         || ptopic->m_atom == "no_client_frame")
      {

         set_need_redraw();

      }

      ::user::impact::handle(ptopic, pcontext);

   }


   ::user::document * impact::get_document()
   {

      return ::user::impact::get_document();

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::rectangle_i32 rectangleClient;


      get_client_rect(rectangleClient);


      pgraphics->fill_rectangle(rectangleClient, color::white);

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = get_client_rect();

      if(rectangleClient.is_empty())
      {

         return;

      }

   }


   bool impact::on_click(::item * pitem)
   {

      auto phyperlink = __create_new <::hyperlink >();

      phyperlink->m_strLink.format("http://localhost.ca2.software:%d/", get_app()->networking_application()->wait_get_current_port(1_min));

      phyperlink->run();

      return true;

   }


} // namespace app_simple_networking_application



