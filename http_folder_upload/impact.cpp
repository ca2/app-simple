// From list2.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "impact.h"
#include "document.h"
#include "impact_folder_path.h"
#include "impact_path.h"
#include "main_impact.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/handler/item.h"
#include "acme/handler/topic.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/hyperlink.h"
#include "acme/user/user/content.h"
#include "apex/database/_binary_stream.h"
#include "apex/networking/http/context.h"
#include "apex/platform/system.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/message/user.h"
#include "berg/user/user/impact_system.h"
#include "berg/user/user/split_impact.h"


namespace app_simple_http_folder_upload
{


   impact::impact()
   {
      m_bRunningSynchronization = false;
 
      //payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(e_non_client_background);

      m_flagNonClient.erase(e_non_client_focus_rect);

      m_bDefaultClickHandling = true;

   }


   impact::~impact()
   {

   }


#ifdef _DEBUG


   long long impact::increment_reference_count()
   {

      return  ::user::impact::increment_reference_count();

   }


   long long impact::decrement_reference_count()
   {

      return  ::user::impact::decrement_reference_count();

   }


#endif


   void impact::install_message_routing(::channel * psender)
   {

      ::user::scroll_impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&impact::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }



   }


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::open_url(const ::scoped_string & scopedstrUrl)
   {

      ::string strUrl(scopedstrUrl);

      fork([this, strUrl]()
      {

         ::property_set set;

         auto & http = application()->http();

         application()->datastream()->set("url", strUrl);

         ::string str =
            http.get(strUrl, set);

         {

            synchronous_lock synchronouslock(this->synchronization());

            m_strRequestResult = str;

         }

         set_need_redraw();

         post_redraw();

      });

   }


   void impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == id_enter_key)
      {

         ::string strText;

         m_pmainimpact->m_pimpactpath->m_pimpactfolderpath->get_text(strText);

         get_app()->datastream()->set("folder", strText);

         get_app()->m_pathFolder = strText;

      }

      ::user::impact::handle(ptopic, phandlercontext);

   }


   document * impact::get_document()
   {

      return dynamic_cast < document * > (::user::impact::get_document());

   }


   bool impact::on_impact_update()
   {

      if (!::user::impact::on_impact_update())
      {

         return false;

      }

//      main_content().m_pitema = get_document()->m_pitemaComputer;

      return true;

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->fill_rectangle(rectangleX, color::blue);

      pgraphics->set_text_color(color::white);

      ::string str = m_strRequestResult;

      
      int y = 10;

      int iHeight = 20;

      for (::collection::index i = 0; i < m_listing.size(); i++)
      {

         rectangleX.top() = y;
         rectangleX.bottom() = y + iHeight;

         pgraphics->draw_text(m_listing[i], rectangleX);

         y += iHeight;

      }

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      if(rectangleX.is_empty())
      {

         return;

      }

   }


   bool impact::on_click(::item * pitem)
   {

      if (pitem->m_item.m_eelement == e_element_item)
      {

         //auto phyperlink = øcreate_new <::hyperlink >();

         //phyperlink->m_strLink.formatf("http://127.0.0.1:%d/", get_app()->http()->wait_get_current_port(1_min));

         //phyperlink->run();

      }

      return true;

   }


   //void impact::network_interface_discovery(::collection::index iItem)
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
   void impact::start_synchronization()
   {

      if (m_bRunningSynchronization)
      {

         return;

      }

      m_bRunningSynchronization = true;

      get_app()->fork([this]()
         {

            try
            {

               do_synchronization();

            }
            catch (...)
            {


            }

            m_bRunningSynchronization = false;

});

   }

   void impact::do_synchronization()
   {

      m_listing.set_file_listing(get_app()->m_pathFolder, e_depth_recursively);

      directory_system()->enumerate(m_listing);

      set_total_size(::int_size(800, 20 * m_listing.size()+ 50));

      set_need_redraw();

      post_redraw();

   }



} // namespace app_simple_http_folder_upload



