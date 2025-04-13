#include "framework.h"
#include "tab_impact.h"
#include "impact.h"
#include "main_impact.h"
#include "application.h"
#include "acme/constant/message.h"
#include "base/user/menu/list_impact.h"
#include "base/user/user/tab_pane.h"
#include "base/user/user/multiple_document_template.h"


namespace app_simple_winnfsd_desktop
{


   tab_impact::tab_impact()
   {

   }


   tab_impact::~tab_impact()
   {

   }


   void tab_impact::install_message_routing(::channel * pchannel)
   {

      ::user::tab_impact::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &tab_impact::on_message_create);

   }


   void tab_impact::on_message_create(::message::message * pmessage)
   {

      if(pmessage->previous())
      {

         return;

      }

      m_papp->m_ptabimpact = this;

      set_tab("Menu", MENU_IMPACT);
      set_tab("app_simple_winnfsd_desktop", MAIN_IMPACT);

      set_current_tab_by_id(MAIN_IMPACT);

   }


   void tab_impact::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::tab_impact::_001OnNcDraw(pgraphics);

   }


   void tab_impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::tab_impact::_001OnDraw(pgraphics);

   }


   void tab_impact::on_change_cur_sel()
   {

      ::user::tab_impact::on_change_cur_sel();

      string strId = get_impact_id();

      string_array stra;

      stra.explode("->:<-",strId);

      if (get_impact_id() == MENU_IMPACT)
      {

         ::pointer<::user::menu_list_impact> pmenuview = get_impact_uie();

         pmenuview->destroy();

         if (pmenuview->load_xml_menu("matter://simple_menu.xml"))
         {

            pmenuview->create_inline_menu(this, m_pimpactdata->m_pplaceholder);

         }

      }


   }


   void tab_impact::on_create_impact(::user::impact_data * pimpactdata)
   {

      //initialize_application_consumer();

      auto papp = get_app();

      if (papp->has_property("notabs"))
      {

         return;

      }

      auto str = pimpactdata->id().as_string();

      if (str.case_insensitive_ends(".simple_http_file_server"))
      {

         m_papp->impact_system("impact")->open_document_file(m_papp, str, true, pimpactdata->m_pplaceholder);

         return;

      }


      switch(pimpactdata->id().as_long_long())
      {
      case MENU_IMPACT:
      {

         ::user::impact::create_impact < ::user::menu_list_impact >(pimpactdata);

      }
      break;
      case MAIN_IMPACT:
      {

         ::user::impact::create_impact < app_simple_winnfsd_desktop::main_impact >(pimpactdata);

      }
      break;
      }



      ::user::tab_impact::on_create_impact(pimpactdata);

   }




   void tab_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {


   }


   //void tab_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   //{


   //   ::user::tab_impact::handle(ptopic, phandlercontext);

   //}


} // namespace app_simple_winnfsd_desktop



