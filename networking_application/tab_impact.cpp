#include "framework.h"
#include "tab_impact.h"
#include "impact.h"
#include "application.h"
#include "acme/constant/message.h"
#include "base/user/menu/list_impact.h"
#include "base/user/user/tab_pane.h"


namespace app_simple_networking_application
{


   tab_impact::tab_impact()
   {

   }


   tab_impact::~tab_impact()
   {

   }


//   void tab_impact::assert_ok() const
//   {
//
//      ::user::impact::assert_ok();
//
//   }
//
//
//   void tab_impact::dump(dump_context & dumpcontext) const
//   {
//
//      ::user::impact::dump(dumpcontext);
//
//   }


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

      //papp->m_ptabimpact = this;

      set_tab("Menu", MENU_IMPACT);
      set_tab("001", "drawing1");

      set_current_tab_by_id("drawing1");

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

      string strImpactId = get_impact_id();

      if(::str().begins(strImpactId, "drawing"))
      {

         auto ptabpaneFileManager = get_tab_by_id(FILEMANAGER_IMPACT);

         if(ptabpaneFileManager != nullptr && ptabpaneFileManager->m_pplaceholder != nullptr)
         {

            ptabpaneFileManager->m_pplaceholder->hide();

         }

         auto ptabpaneFontSel = get_tab_by_id(FONTSEL_IMPACT);

         if (ptabpaneFontSel != nullptr && ptabpaneFontSel->m_pplaceholder != nullptr)
         {

            ptabpaneFontSel->m_pplaceholder->hide();

         }

         m_pviewTopic = m_pimpactdata->m_pplaceholder->get_hold();

      }
      //else if (get_impact_id() == MENU_IMPACT)
      //{

      //   m_pdocMenu->open_document("matter://menu.html");

      //}

   }


   void tab_impact::on_create_impact(::user::impact_data * pimpactdata)
   {

      //initialize_application_consumer();

      auto papp = get_app();

      if (papp->has_property("notabs"))
      {

         return;

      }

      switch(pimpactdata->m_atom.i64())
      {
      case MENU_IMPACT:
      {

         ::user::impact::create_impact < ::user::menu_list_impact >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->m_atom;

      if(::str().begins_eat_ci(strId, "drawing"))
      {

         auto pimpact = papp->create_simple_drawing_impact(this, pimpactdata);

         pimpact->m_atom = pimpactdata->m_atom;

         pimpactdata->m_eflag.add(::user::e_flag_hidid_on_show);

      }

      ::user::tab_impact::on_create_impact(pimpactdata);

   }




   void tab_impact::handle(::topic * ptopic, ::context * pcontext)
   {


   }


   //void tab_impact::handle(::topic * ptopic, ::context * pcontext)
   //{


   //   ::user::tab_impact::handle(ptopic, pcontext);

   //}


} // namespace app_simple_networking_application



