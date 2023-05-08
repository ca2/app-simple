#include "framework.h"
#include "impact.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/handler/item.h"
#include "acme/platform/hyperlink.h"
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


//   void impact::assert_ok() const
//   {
//
//      user::box::assert_ok();
//
//   }
//
//
//   void impact::dump(dump_context & dumpcontext) const
//   {
//
//      user::box::dump(dumpcontext);
//
//   }


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

      MESSAGE_LINK(MESSAGE_CREATE,psender,this,&impact::on_message_create);
      MESSAGE_LINK(MESSAGE_DESTROY, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }


      auto addressa = acmesystem()->m_papexsystem->networking()->list_network_interfaces();

      for (::index iItem = 0; iItem < addressa.size(); iItem++)
      {

         auto pitem = __new(item(e_element_item, iItem));

         add_user_item(pitem);

         m_mapaddress[iItem] = addressa[iItem];

      }

      auto addressa2 = acmesystem()->m_papexsystem->networking()->list_computers();

      for (::index iItem = 0; iItem < addressa2.size(); iItem++)
      {

         m_mapaddress2[iItem] = addressa2[iItem];

      }

      

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

      client_rectangle(rectangleClient);

      pgraphics->fill_rectangle(rectangleClient, color::white);

      pgraphics->set_text_color(color::black);

      pgraphics->set_text_rendering_hint(::write_text::e_rendering_anti_alias);

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->text_out(25, 10, "Network Interfaces");

      int iHeight = 25;

      int iMaxX1 = 0;

      int iMaxX2 = 0;

      {

         int y = 10 + iHeight;

         ::rectangle_i32 r;

         for (auto & pitem : *m_pitema)
         {

            if (pitem->m_eelement == e_element_item)
            {

               auto paddress = m_mapaddress[pitem->m_iItem];

               ::string strAddress = paddress->get_display_number();

               auto size = pgraphics->get_text_extent(strAddress);

               pgraphics->text_out(25, y, strAddress);

               r.left = 25;
               r.top = y;
               r.bottom = y + iHeight;
               r.right = r.left + (::i32) (size.cx);

               if (r.right > iMaxX1)
               {

                  iMaxX1 = r.right;

               }

               y += iHeight;

               pitem->m_rectangle = r;


            }

         }

      }

      {

      int y = 10;

      pgraphics->text_out(iMaxX1 + 20, y, "Selected Network Interface");

      y += iHeight;

      pgraphics->text_out(iMaxX1 + 20, y, m_strNetworkInterfaceAddress.is_empty() ? ::string("(None) (Please click address at column to the left to select a network interface...)") : m_strNetworkInterfaceAddress);

      if (m_paddressNetworkInterface)
      {

         y += iHeight;

         ::rectangle_i32 r;

         //int iMaxX1 = 0;
         auto paddressMask = acmesystem()->m_papexsystem->networking()->create_ip4_address("255.255.255.0");

         for (auto & pair : m_mapaddress2)
         {

            //if (pitem->m_eelement == e_element_item)
            {

               // auto paddress = m_mapaddress[pitem->m_iItem];

               if (pair.element2()->is_in_same_net(m_paddressNetworkInterface, paddressMask))
               {

                  ::string strAddress = pair.element2()->get_display_number();

                  auto size = pgraphics->get_text_extent(strAddress);

                  pgraphics->text_out(iMaxX1 + 20, y, strAddress);

                  r.left = iMaxX1 + 20;
                  r.top = y;
                  r.bottom = y + iHeight;
                  r.right = r.left + (::i32) (size.cx);

                  if (r.right > iMaxX1)
                  {

                     iMaxX2 = r.right;

                  }

                  y += iHeight;

                  //pitem->m_rectangle = r;

               }


            }

         }

      }

      }

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = client_rectangle();

      if(rectangleClient.is_empty())
      {

         return;

      }

   }


   bool impact::on_click(::item * pitem)
   {

      if (pitem->m_eelement == e_element_item)
      {

         network_interface_discovery(pitem->m_iItem);

         return true;

      }

      auto phyperlink = __create_new <::hyperlink >();

      phyperlink->m_strLink.format("http://127.0.0.1:%d/", get_app()->networking_application()->wait_get_current_port(1_min));

      phyperlink->run();

      return true;

   }


   void impact::network_interface_discovery(::index iItem)
   {

      m_paddressNetworkInterface.release();
      
      m_strNetworkInterfaceAddress.empty();

      for (auto & pitem : *m_pitema)
      {

         if (pitem->m_eelement == e_element_item)
         {

            if (pitem->m_iItem == iItem)
            {

               m_paddressNetworkInterface = m_mapaddress[pitem->m_iItem];

               break;

            }

         }

      }

      if (!m_paddressNetworkInterface)
      {

         return;

      }

      m_strNetworkInterfaceAddress = m_paddressNetworkInterface->get_display_number();



   }


} // namespace app_simple_networking_application



