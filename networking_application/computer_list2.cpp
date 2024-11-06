// From list2.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "computer_list2.h"
#include "document.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/handler/item.h"
#include "acme/handler/topic.h"
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


   computer_list2::computer_list2()
   {

      //payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);

      m_bDefaultClickHandling = true;

   }


   computer_list2::~computer_list2()
   {

   }


#ifdef _DEBUG


   int64_t computer_list2::increment_reference_count()
   {

      return  ::user::list2::increment_reference_count();

   }


   int64_t computer_list2::decrement_reference_count()
   {

      return  ::user::list2::decrement_reference_count();

   }


#endif


   void computer_list2::install_message_routing(::channel * psender)
   {

      ::user::show < ::user::list2>::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&computer_list2::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &computer_list2::on_message_destroy);

   }


   void computer_list2::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }



      

      //initialize_application_composer();

      get_app()->create_networking_application("");

      //{

      //   auto psignal = get_app()->get_signal("simple_checkbox");

      //   psignal->add_handler(this);

      //}

      //{

      //   auto psignal = get_app()->get_signal("no_client_frame");

      //   psignal->add_handler(this);

      //}


      string strId = get_document()->m_pimpactsystem->m_atom;

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


   void computer_list2::on_message_destroy(::message::message * pmessage)
   {

   }


   void computer_list2::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->m_atom == "simple_checkbox"
         || ptopic->m_atom == "no_client_frame")
      {

         set_need_redraw();

      }

      ::user::list2::handle(ptopic, pcontext);

   }


   document * computer_list2::get_document()
   {

      return dynamic_cast < document * > (::user::show < ::user::list2 >::get_document());

   }


   bool computer_list2::on_impact_update()
   {

      if (!::user::show < ::user::list2>::on_impact_update())
      {

         return false;

      }

      main_content().m_pitema = get_document()->m_pitemaComputer;

      return true;

   }

   void computer_list2::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      pgraphics->fill_rectangle(rectangleX, color::white);

      pgraphics->set_text_color(color::black);

      pgraphics->set_text_rendering_hint(::write_text::e_rendering_anti_alias);

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      int iHeight = 25;

      int iMaxX1 = 0;

      int iMaxX2 = 0;

      int y = 10;

      pgraphics->text_out(iMaxX1 + 20, y, "Selected Network Interface");

      y += iHeight;

      pgraphics->text_out(iMaxX1 + 20, y, get_document()->m_strNetworkInterfaceAddress.is_empty() ? ::string("(None) (Please click address at column to the left to select a network interface...)") :get_document()->m_strNetworkInterfaceAddress);

      y += iHeight;

      pgraphics->text_out(iMaxX1 + 20, y, "Other Computers found in this Network");

      if(get_document()->m_paddressNetworkInterface)
      {

         y += iHeight;

         ::int_rectangle r;

         //int iMaxX1 = 0;
         auto paddressMask = system()->networking()->create_ip4_address("255.255.255.0");

         for (auto & pitem : *get_document()->m_pitemaComputer)
         {

            ::pointer < ::networking::address > paddress = pitem;
            //if (pitem->m_item.m_eelement == e_element_item)
            {

               // auto paddress = m_mapaddress[pitem->m_item.m_iItem];

               if (paddress->is_in_same_net(get_document()->m_paddressNetworkInterface, paddressMask))
               {

                  ::string strAddress = paddress->get_display_number();

                  auto size = pgraphics->get_text_extent(strAddress);

                  pgraphics->text_out(iMaxX1 + 20, y, strAddress);

                  r.left() = iMaxX1 + 20;
                  r.top() = y;
                  r.bottom() = y + iHeight;
                  r.right() = r.left() + (int) (size.cx());

                  if (r.right() > iMaxX1)
                  {

                     iMaxX2 = r.right();

                  }

                  y += iHeight;

                  //pitem->m_rectangle = r;

               }


            }

         }

      }

   }


   void computer_list2::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      if(rectangleX.is_empty())
      {

         return;

      }

   }


   bool computer_list2::on_click(::item * pitem)
   {

      if (pitem->m_item.m_eelement == e_element_item)
      {

         auto phyperlink = __create_new <::hyperlink >();

         phyperlink->m_strLink.formatf("http://127.0.0.1:%d/", get_app()->networking_application()->wait_get_current_port(1_min));

         phyperlink->run();

      }

      return true;

   }


   //void computer_list2::network_interface_discovery(::collection::index iItem)
   //{

   //   m_paddressNetworkInterface.release();
   //   
   //   m_strNetworkInterfaceAddress.empty();

   //   for (auto & pitem : m_itema)
   //   {

   //      if (pitem->m_item.m_eelement == e_element_item)
   //      {

   //         if (pitem->m_item.m_iItem == iItem)
   //         {

   //            m_paddressNetworkInterface = m_mapaddress[pitem->m_item.m_iItem];

   //            break;

   //         }

   //      }

   //   }

   //   if (!m_paddressNetworkInterface)
   //   {

   //      return;

   //   }

   //   m_strNetworkInterfaceAddress = m_paddressNetworkInterface->get_display_number();



   //}


} // namespace app_simple_networking_application



