// From command_list2.cpp by camilo on 2023-08-16 17:07 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "command.h"
#include "command_document.h"
#include "command_list2.h"
#include "document.h"
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


namespace app_simple_http_file_server
{


   command_list2::command_list2()
   {

      //payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);

      m_bDefaultClickHandling = true;

   }


   command_list2::~command_list2()
   {

   }


#ifdef _DEBUG


   long long command_list2::increment_reference_count()
   {

      return  ::user::list2::increment_reference_count();

   }


   long long command_list2::decrement_reference_count()
   {

      return  ::user::list2::decrement_reference_count();

   }


#endif


   void command_list2::install_message_routing(::channel * psender)
   {

      ::user::show < ::user::list2>::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &command_list2::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &command_list2::on_message_destroy);

   }


   void command_list2::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }



   }


   void command_list2::on_message_destroy(::message::message * pmessage)
   {

   }


   void command_list2::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      ::user::list2::handle(ptopic, phandlercontext);

   }


   command_document * command_list2::get_document()
   {

      return dynamic_cast <command_document *> (::user::show < ::user::list2 >::get_document());

   }


   bool command_list2::on_impact_update()
   {

      if (!::user::show < ::user::list2>::on_impact_update())
      {

         return false;

      }

      main_content().m_pitema = get_document()->m_pitemaCommand;

      set_need_layout();

      set_need_redraw();

      post_redraw();

      return true;

   }


   void command_list2::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (!main_content().m_pitema)
      {

         return;

      }

      auto rectangleX = this->rectangle();

      pgraphics->fill_rectangle(rectangleX, color::white);

      pgraphics->set_text_color(color::black);

      pgraphics->set_text_rendering_hint(::write_text::e_rendering_anti_alias);

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      int iHeight = 25;

      int iMaxX1 = 0;

      int iMaxX2 = 0;

      int y = 10;


      auto iCurrentCommand = get_document()->m_iCurrentCommand;

      ::pointer < command > pcommandCurrent;

      ::string strPrefix;

      if (iCurrentCommand < 0)
      {

         __construct_new(pcommandCurrent);

         pcommandCurrent->m_strCommand = "(No Command)";

      }
      else if (iCurrentCommand >= main_content().m_pitema->size())
      {

         __construct_new(pcommandCurrent);

         pcommandCurrent->m_strCommand = "Done!!";

      }
      else
      {

         pcommandCurrent = main_content().m_pitema->element_at(iCurrentCommand);

         __defer_construct_new(pcommandCurrent);

         strPrefix = "Running command: ";

      }

      pgraphics->text_out(iMaxX1 + 20, y, strPrefix + pcommandCurrent->get_text(command::e_subitem_command));

      y += iHeight;

      pgraphics->text_out(iMaxX1 + 20, y, "Current Adapter: \"" + get_document()->m_strCurrentAdapter + "\"");




      y += iHeight;

      //pgraphics->text_out(iMaxX1 + 20, y, "Other Computers found in this Network");

      //if (get_document()->m_strCommand)
      {

         y += iHeight;

         ::int_rectangle r;

         //int iMaxX1 = 0;
//         auto paddressMask = system()->networking()->create_ip4_address("255.255.255.0");

         for (auto & pitem : *main_content().m_pitema)
         {

            ::pointer < command > pcommand = pitem;
            //if (pitem->m_item.m_eelement == e_element_item)
            {

               // auto paddress = m_mapaddress[pitem->m_item.m_iItem];

               ::string strText = pcommand->m_strCommand;

               if (pcommand == pcommandCurrent)

               {

                  strText = "--> \"" + strText + "\" <--";

               }

               if (pcommand->m_strResult.has_character())
               {

                  strText += " - Result : " + pcommand->m_strResult;

               }

               auto size = pgraphics->get_text_extent(strText);

               pgraphics->text_out(iMaxX1 + 20, y, strText);

               r.left() = iMaxX1 + 20;
               r.top() = y;
               r.bottom() = y + iHeight;
               r.right() = r.left() + (int)(size.cx());

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


   void command_list2::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      if (rectangleX.is_empty())
      {

         return;

      }

   }


   bool command_list2::on_click(::item * pitem)
   {

      if (pitem->m_item.m_eelement == e_element_item)
      {

         auto phyperlink = __create_new <::hyperlink >();

         phyperlink->m_strLink.formatf("http://127.0.0.1:%d/", get_app()->networking_application()->wait_get_current_port(1_min));

         phyperlink->run();

      }

      return true;

   }


   //void command_list2::network_interface_discovery(::collection::index iItem)
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


} // namespace app_simple_http_file_server



