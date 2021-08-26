#include "framework.h"
#include "aura/update.h"
#include "base/user/user/tab_pane.h"


namespace simple_os_drag_and_drop
{


   tab_view::tab_view()
   {

      m_pviewTopic = nullptr;

   }


   tab_view::~tab_view()
   {

   }


   void tab_view::assert_valid() const
   {

      ::user::impact::assert_valid();

   }


   void tab_view::dump(dump_context & dumpcontext) const
   {

      ::user::impact::dump(dumpcontext);

   }


   void tab_view::install_message_routing(::channel * pchannel)
   {

      //::userex::pane_tab_view::install_message_routing(pchannel);

      ::user::tab_view::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &tab_view::on_message_create);

   }


   void tab_view::on_message_create(::message::message * pmessage)
   {

      if(pmessage->previous())
         return;

      set_tab("Menu",MENU_IMPACT);
      set_tab("001", "drawing1");
      set_tab("002", "drawing2");
      set_tab("003", "drawing3");
      set_tab("arcs", "drawing4");
      set_tab("arcpths", "drawing5");
      set_tab("Font",FONTSEL_IMPACT);
      set_tab("Open", FILEMANAGER_IMPACT);

      set_current_tab_by_id("drawing1");

   }


   void tab_view::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      //::userex::pane_tab_view::_001OnNcDraw(pgraphics);
      ::user::tab_view::_001OnNcDraw(pgraphics);

   }


   void tab_view::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      //::userex::pane_tab_view::_001OnDraw(pgraphics);
      ::user::tab_view::_001OnDraw(pgraphics);

   }


   void tab_view::on_change_cur_sel()
   {

      //::userex::pane_tab_view::on_change_cur_sel();
      ::user::tab_view::on_change_cur_sel();
      string strId = get_view_id();
      string_array stra;

      stra.explode("->:<-",strId);

      if (get_view_id() == MENU_IMPACT)
      {

         //__pointer(::user::menu_list_view) pmenuview = get_view_uie();

         //pmenuview->destroy_menu();

         //pmenuview->load_xml_menu("matter://simple_menu.xml");

         //pmenuview->create_inline_menu(m_pviewTopic, m_pimpactdata->m_pplaceholder);

      }

      if(get_view_id() == MAIN_IMPACT)
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

         m_pviewTopic = nullptr;

      }
      //else if (get_view_id() == FONTSEL_IMPACT)
      //{

      //   __pointer(::user::font_list_view) pfontview = ptabpaneFontSel->m_pplaceholder->get_child_by_id("font_list_view");

      //   if (m_pviewTopic != nullptr && pfontview.is_set())
      //   {

      //      pfontview->set_sel_by_name(m_pviewTopic->m_psimpleosdraganddrop->m_strFont);

      //   }

      //}

   }


   void tab_view::on_create_impact(::user::impact_data * pimpactdata)
   {

      auto papplication = get_application();

      if (papplication->has_property("notabs"))
      {

         return;

      }

      switch(pimpactdata->m_id)
      {
      case MENU_IMPACT:
      {

         //::user::impact::create_view < ::user::menu_list_view >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->m_id;

      if(::str::begins_eat_ci(strId, "drawing"))
      {

         auto pview = m_papplication->create_simple_os_drag_and_drop_view(this, pimpactdata);

         pview->m_id = pimpactdata->m_id;

         pview->m_psimpleosdraganddrop->initialize_drag_and_drop(atoi(strId));

      }

      pimpactdata->m_eflag.add(::user::e_flag_hide_topic_on_show);

      //::userex::pane_tab_view::on_create_impact(pimpactdata);
      ::user::tab_view::on_create_impact(pimpactdata);

   }


   bool tab_view::BaseOnControlEvent(::user::form_window * pview,::user::control_event * pevent)
   {

      if(m_pdocMenu != nullptr && dynamic_cast < ::user::impact * > (pview) == m_pdocMenu->get_view(0) && pevent->m_puserinteraction != nullptr)
      {

         if(pevent->m_eevent == ::user::e_event_after_change_text)
         {


         }
         else if (pevent->m_eevent == ::user::e_event_set_check && pevent->m_puserinteraction != nullptr)
         {

            string strCheck = pevent->m_puserinteraction->m_id;


            if (::str::begins_eat_ci(strCheck, "bilbo"))
            {

               if (pevent->m_puserinteraction != nullptr && pevent->m_actioncontext.is_user_source())
               {

                  //int iCheck = atoi(strCheck);

                  //__pointer(::user::check) pcheck = pevent->m_puserinteraction;

               }

            }

         }

      }

      return false;

   }


   void tab_view::on_subject(::subject::subject * psubject, ::subject::context * pcontext)
   {

      ////__update(::update)
      //{

      //   if (psubject->id() == id_control_event
      //         && psubject->m_puserinteraction == m_pfontview
      //         && m_pviewTopic != nullptr)
      //   {

      //      if(pupdate->m_pcontrolevent->m_eevent == ::user::e_event_after_change_cur_sel)
      //      {

      //         string strFont = m_pfontview->m_pimpact->get_cur_sel_face_name();

      //      }
      //      else if (pupdate->m_pcontrolevent->m_eevent == ::user::e_event_after_change_cur_hover)
      //      {

      //         string strFont = m_pfontview->m_pimpact->get_cur_hover_face_name();

      //      }

      //   }

      //}

//      ::userex::pane_tab_view::on_subject(psubject, pcontext);
      ::user::tab_view::on_subject(psubject, pcontext);

   }


} // namespace simple_os_drag_and_drop



