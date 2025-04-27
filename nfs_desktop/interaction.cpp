// Created by camilo on 2025-04-12 23:30 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "interaction.h"
#include "document.h"
#include "edit_impact.h"
#include "main_impact.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/constant/timer.h"
#include "acme/handler/item.h"
#include "acme/handler/topic.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/hyperlink.h"
#include "acme/platform/timer.h"
#include "acme/user/user/content.h"
#include "apex/database/_binary_stream.h"
#include "apex/networking/http/context.h"
#include "apex/platform/system.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/message/user.h"
#include "base/user/user/impact_system.h"
#include "base/user/user/split_impact.h"
#include "winnfsd/src/nfs.h"


namespace app_simple_nfs_desktop
{


   interaction::interaction()
   {

      //payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);

      m_bDefaultClickHandling = true;

   }


   interaction::~interaction()
   {

   }


#ifdef _DEBUG


   long long interaction::increment_reference_count()
   {

      return  ::user::interaction::increment_reference_count();

   }


   long long interaction::decrement_reference_count()
   {

      return  ::user::interaction::decrement_reference_count();

   }


#endif


   void interaction::install_message_routing(::channel * psender)
   {

      ::user::interaction::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &interaction::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &interaction::on_message_destroy);

   }


   void interaction::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      set_timer(e_timer_redraw, 1_s);

      __construct_new(m_papp->m_pnfs);


      m_papp->m_pnfs->netnode_from_ini_configuration();

      //std::vector<std::vector<::string>> paths;

      //paths.push_back({ "C:\\Users\\camilo\\nfs", "/nfs" });
      //paths.push_back({ "C:\\Dropbox", "/dropbox" });

      //m_papp->m_pnfs->simple_server(1001, 1001, "192.168.0.89", paths);


   }


   void interaction::on_message_destroy(::message::message * pmessage)
   {

   }


   void interaction::open_url(const ::scoped_string & scopedstrUrl)
   {

      ::string strUrl(scopedstrUrl);

      fork([this, strUrl]()
      {

         property_set set;

         ::cast < ::database::client > pdatabaseclient = application();

         pdatabaseclient->datastream()->set("url", strUrl);

         ::string str = http()->get(strUrl, set);

         {

            synchronous_lock synchronouslock(this->synchronization());

            m_strRequestResult = str;

         }

         set_need_redraw();

         post_redraw();

      });

   }


   void interaction::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == id_enter_key)
      {

         ::string strText;

         m_pmainimpact->m_peditimpact->get_text(strText);

         get_app()->datastream()->set("folder", strText);

         get_app()->m_pathFolder = strText;

      }

      ::user::interaction::handle(ptopic, phandlercontext);

   }


   //document * interaction::get_document()
   //{

   //   return dynamic_cast <document *> (::user::interaction::get_document());

   //}


   bool interaction::on_impact_update()
   {

      if (!::user::interaction::on_impact_update())
      {

         return false;

      }

      //      main_content().m_pitema = get_document()->m_pitemaComputer;

      return true;

   }


   void interaction::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      /*auto rectangleX = this->rectangle();

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->fill_rectangle(rectangleX, color::blue);

      pgraphics->set_text_color(color::white);

      ::string str = m_strRequestResult;

      pgraphics->draw_text(str, rectangleX);*/

      auto rectangleX = this->rectangle();

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->fill_rectangle(rectangleX, argb(127, 100, 180, 255));

      pgraphics->set_text_color(color::white);

      //::string str = m_strRequestResult;
      _synchronous_lock synchronouslock(m_papp->m_pnfs->synchronization());
      auto & stra = m_papp->m_pnfs->m_straLog;
      int x = 10;
      int y = rectangleX.height() - 25;
      for (::collection::index i = 0; i < 40; i++)
      {
         auto iIndex = stra.size() - 1 - i;

         if (iIndex < 0)
         {
            break;
         }
         auto & strLine = stra[iIndex];
         pgraphics->text_out(x, y, strLine);
         y -= 25;
      }


      //::double_size size(1920.0, (y+1) * 25.0);


      //if (get_total_size() != size)
      //{
      //   set_total_size(size);
      //}

   }
   void interaction::on_timer(::timer *ptimer)
   {
    //if(ptimer->m_etimer == e_timer_redraw)
    //  {
    //   //set_need_redraw();
    //   //post_redraw();
    //  }
   }

   void interaction::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      if (rectangleX.is_empty())
      {

         return;

      }

   }


   bool interaction::on_click(::item * pitem, ::user::mouse * pmouse)
   {

      if (pitem->m_item.m_eelement == e_element_item)
      {

         //auto phyperlink = __create_new <::hyperlink >();

         //phyperlink->m_strLink.formatf("http://127.0.0.1:%d/", get_app()->http()->wait_get_current_port(1_min));

         //phyperlink->run();

      }

      return true;

   }


   //void interaction::network_interface_discovery(::collection::index iItem)
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


} // namespace app_simple_nfs_desktop



