#include "framework.h"
#include "aura/update.h"
#include "base/user/user/tab_pane.h"


namespace app_simple_networking_application
{


   tab_view::tab_view()
   {

   }


   tab_view::~tab_view()
   {

   }


   void tab_view::assert_ok() const
   {

      ::user::impact::assert_ok();

   }


   void tab_view::dump(dump_context & dumpcontext) const
   {

      ::user::impact::dump(dumpcontext);

   }


   void tab_view::install_message_routing(::channel * pchannel)
   {

      ::user::tab_view::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &tab_view::on_message_create);

   }


   void tab_view::on_message_create(::message::message * pmessage)
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


   void tab_view::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::tab_view::_001OnNcDraw(pgraphics);

   }


   void tab_view::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::tab_view::_001OnDraw(pgraphics);

   }


   void tab_view::on_change_cur_sel()
   {

      ::user::tab_view::on_change_cur_sel();

      string strId = get_view_id();

      string_array stra;

      stra.explode("->:<-",strId);

      if (get_view_id() == MENU_IMPACT)
      {

         __pointer(::user::menu_list_view) pmenuview = get_view_uie();

         pmenuview->destroy();

         if (pmenuview->load_xml_menu("matter://simple_menu.xml"))
         {

            pmenuview->create_inline_menu(this, m_pimpactdata->m_pplaceholder);

         }

      }

      string strViewId = get_view_id().to_string();

      if(::::str::ch().begins(strViewId, "drawing"))
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

         __refer(m_pviewTopic,m_pimpactdata->m_pplaceholder->get_hold());

      }
      //else if (get_view_id() == MENU_IMPACT)
      //{

      //   m_pdocMenu->open_document("matter://menu.html");

      //}

   }


   void tab_view::on_create_impact(::user::impact_data * pimpactdata)
   {

      //initialize_application_consumer();

      auto papp = m_papp;

      if (papp->has_property("notabs"))
      {

         return;

      }

      switch(pimpactdata->m_atom.i64())
      {
      case MENU_IMPACT:
      {

         ::user::impact::create_view < ::user::menu_list_view >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->m_atom;

      if(::::str::ch().begins_eat_ci(strId, "drawing"))
      {

         auto pimpact = papp->create_simple_drawing_view(this, pimpactdata);

         pimpact->m_atom = pimpactdata->m_atom;

         pimpactdata->m_eflag.add(::user::e_flag_hidid_on_show);

      }

      ::user::tab_view::on_create_impact(pimpactdata);

   }




   void tab_view::handle(::topic * ptopic, ::context * pcontext)
   {


   }


   //void tab_view::handle(::topic * ptopic, ::context * pcontext)
   //{


   //   ::user::tab_view::handle(ptopic, pcontext);

   //}


} // namespace app_simple_networking_application



