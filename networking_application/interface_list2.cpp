// From impact.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "document.h"
#include "interface_list2.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/handler/item.h"
#include "acme/platform/hyperlink.h"
#include "acme/user/user/content.h"
#include "apex/networking/application/application.h"
#include "apex/networking/address.h"
#include "apex/networking/networking.h"
#include "apex/platform/system.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/message/user.h"
#include "base/user/user/impact_system.h"
#include "base/user/user/split_impact.h"


namespace app_simple_networking_application
{


   interface_list2::interface_list2()
   {

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);

      m_bDefaultClickHandling = true;
      m_bDefaultParentMouseMessageHandling = true;

   }


   interface_list2::~interface_list2()
   {

   }


#ifdef _DEBUG


   int64_t interface_list2::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t interface_list2::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void interface_list2::install_message_routing(::channel * psender)
   {

      ::user::show < ::user::list2>::install_message_routing(psender);

      MESSAGE_LINK(MESSAGE_CREATE,psender,this,&interface_list2::on_message_create);
      MESSAGE_LINK(MESSAGE_DESTROY, psender, this, &interface_list2::on_message_destroy);

   }


   void interface_list2::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }


      //auto addressa = acmesystem()->m_papexsystem->networking()->list_network_interfaces();

      //for (::index iItem = 0; iItem < addressa.size(); iItem++)
      //{

      //   auto pitem = __new(::item(e_element_item, iItem));

      //   add_item(pitem);

      //   //m_mapaddress[iItem] = addressa[iItem];

      //}

      //auto addressa2 = acmesystem()->m_papexsystem->networking()->list_computers();

      //for (::index iItem = 0; iItem < addressa2.size(); iItem++)
      //{

      //   m_mapaddress2[iItem] = addressa2[iItem];

      //}

      //

      //initialize_application_composer();

      get_app()->create_networking_application();

      {

         auto psignal = get_app()->get_signal("simple_checkbox");

         psignal->add_handler(this);

      }

      {

         auto psignal = get_app()->get_signal("no_client_frame");

         psignal->add_handler(this);

      }


      string strId = get_document()->m_pimpactsystem->m_atom;

      string strText;

      if(get_typed_parent<::user::split_impact>() != nullptr)
      {

         if(get_typed_parent<::user::split_impact>()->get_child_by_id("top_edit_impact") != nullptr)
         {

            auto pinteraction = get_typed_parent<::user::split_impact>()->get_child_by_id("top_edit_impact");

            pinteraction->_001SetText(strText,::e_source_initialize);

         }

      }

   }


   void interface_list2::on_message_destroy(::message::message * pmessage)
   {

   }


   void interface_list2::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->m_atom == "simple_checkbox"
         || ptopic->m_atom == "no_client_frame")
      {

         set_need_redraw();

      }

      ::user::impact::handle(ptopic, pcontext);

   }


   document * interface_list2::get_document()
   {

      return dynamic_cast <document *> (::user::show < ::user::list2 >::get_document());

   }


   bool interface_list2::on_impact_update()
   {

      if (!::user::show < ::user::list2>::on_impact_update())
      {

         return false;

      }

      main_content().m_pitema = get_document()->m_pitemaInterface;

      return true;

   }



   void interface_list2::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      pgraphics->fill_rectangle(rectangleX, color::white);

      pgraphics->set_text_color(color::black);

      pgraphics->set_text_rendering_hint(::write_text::e_rendering_anti_alias);

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->text_out(25, 10, "Network Interfaces");

      if(!main_content().m_pitema)
      {
         
         return;
         
      }
      
      int iHeight = 25;

      int iMaxX1 = 0;

      int iMaxX2 = 0;

      {

         int y = 10 + iHeight;

         ::rectangle_i32 r;

         for (auto & pitem : *main_content().m_pitema)
         {

            ::pointer < ::networking::address > paddress = pitem;

            ::string strAddress = paddress->get_display_number();

            auto size = pgraphics->get_text_extent(strAddress);

            pgraphics->text_out(25, y, strAddress);

            r.left() = 25;
            r.top() = y;
            r.bottom() = y + iHeight;
            r.right() = r.left() + (::i32) (size.cx());

            if (r.right() > iMaxX1)
            {

               iMaxX1 = r.right();

            }

            y += iHeight;

            auto puseritem = user_item(pitem);

            puseritem->m_rectangle = r;

         }

      }

   }


   void interface_list2::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      if(rectangleX.is_empty())
      {

         return;

      }

   }


   bool interface_list2::on_click(::item * pitem)
   {

      get_document()->network_interface_discovery(pitem->m_item.m_iItem);

      return true;

   }




} // namespace app_simple_networking_application


