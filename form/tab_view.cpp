#include "framework.h"
#include "aura/update.h"
#include "base/user/user/tab_pane.h"


namespace app_simple_form
{


   tab_view::tab_view()
   {

      m_pimpactLast = NULL;

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
         return;

      add_tab("Menu",MENU_IMPACT);
      add_tab("001", "form1");
      add_tab("002", "form2");

      string strForm;

      auto papp = get_app();

      strForm = papp->payload("tab");

      string_array straForm;

      straForm.add("form1");
      straForm.add("form2");

      if(straForm.contains(strForm))
      {

         set_current_tab_by_id(strForm);

      }
      else
      {

         set_current_tab_by_id("form1");

      }

   }


   void tab_view::on_change_cur_sel()
   {

      //::userex::pane_tab_impact::on_change_cur_sel();
      ::user::tab_view::on_change_cur_sel();
      string strId = get_view_id();
      string_array stra;

      stra.explode("->:<-",strId);

      if (get_view_id() == MENU_IMPACT)
      {

         //__pointer(::user::menu_list_view) pmenuview = get_view_uie();

         //pmenuview->load_xml_menu("matter://simple_menu.xml");

         //pmenuview->create_inline_menu(m_pimpactdataOld->m_puserinteraction, m_pimpactdata->m_pplaceholder);

         //}

         //hide_all_except({ get_view_id(), ::impact_karaoke });

      }

      if(get_view_id() == ::impact_simple_form)
      {

         auto ptabpaneFileManager = get_tab_by_id(FILEMANAGER_IMPACT);

         if(ptabpaneFileManager != nullptr
               && ptabpaneFileManager->m_pplaceholder != nullptr)
         {

            ptabpaneFileManager->m_pplaceholder->hide();

         }

         auto ptabpaneFontSel = get_tab_by_id(FONTSEL_IMPACT);

         if (ptabpaneFontSel != nullptr
               && ptabpaneFontSel->m_pplaceholder != nullptr)
         {

            ptabpaneFontSel->m_pplaceholder->hide();

         }

         m_pimpactLast = nullptr;

      }

   }


   void tab_view::on_create_impact(::user::impact_data * pimpactdata)
   {

      switch(pimpactdata->m_atom)
      {
      case MENU_IMPACT:
      {

         //::user::impact::create_view < ::user::menu_list_view >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->m_atom;

      if(::str::begins_eat_ci(strId, "form"))
      {

         __pointer(form) pform;

         index iId = atoi(strId);

         switch (iId)
         {
         case 1:

            pform = create_view<form_001>(pimpactdata);

            break;

         case 2:

            pform = create_view<form_002>(pimpactdata);

            break;

         default:

            break;

         }

         pform->m_ptabimpact = this;

         pform->m_iId = (int)iId;

         pform->m_atom = pimpactdata->m_atom;

         return;

      }

      ::user::tab_view::on_create_impact(pimpactdata);

      pimpactdata->m_eflag.add(::user::e_flag_hide_all_others_on_show);

   }


   //bool tab_view::handle(::topic * ptopic, ::context * pcontext)
   //{

   //   if(m_pdocMenu != nullptr
   //         && dynamic_cast < ::user::impact * > (pimpact) == m_pdocMenu->get_view(0)
   //         && ptopic->user_interaction() != nullptr)
   //   {

   //      if(ptopic->m_atom == ::id_after_change_text)
   //      {


   //      }
   //      else if (ptopic->m_atom == ::id_set_check && ptopic->user_interaction() != NULL)
   //      {

   //         string strCheck = ptopic->user_element_id();

   //         if (::str::begins_eat_ci(strCheck, "bilbo"))
   //         {

   //            if (ptopic->user_interaction() != NULL && ptopic->m_actioncontext.is_user_source())
   //            {

   //               //int iCheck = atoi(strCheck);

   //               //__pointer(::user::check) pcheck = ptopic->user_interaction();

   //            }

   //         }

   //      }

   //   }

   //   return false;

   //}


   void tab_view::handle(::topic * ptopic, ::context * pcontext)
   {

      //////__update(::update)
      //{

      //   if (ptopic->m_atom == id_control_event
      //         && ptopic->user_interaction() == m_pfontview
      //         && m_pimpactLast != NULL)
      //   {

      //      if(pupdate->m_pcontrolevent->m_eevent == ::id_after_change_cur_sel)
      //      {

      //         string strFont = m_pfontview->m_pimpact->get_cur_sel_face_name();

      //      }
      //      else if (pupdate->m_pcontrolevent->m_eevent == ::id_after_change_cur_hover)
      //      {

      //         string strFont = m_pfontview->m_pimpact->get_cur_hover_face_name();

      //      }

      //   }

      //}
      if (m_pdocMenu != nullptr
         && ::is_set(ptopic->m_puserelement)
         && ptopic->m_puserelement->get_form() == m_pdocMenu->get_view(0))
      {

         if (ptopic->m_atom == ::id_after_change_text)
         {


         }
         else if (ptopic->m_atom == ::id_set_check && ::is_set(ptopic->m_puserelement))
         {

            string strCheck = ptopic->m_puserelement->m_atom;

            if (::str::begins_eat_ci(strCheck, "bilbo"))
            {

               if (::is_set(ptopic->m_puserelement) && ptopic->m_actioncontext.is_user_source())
               {

                  //int iCheck = atoi(strCheck);

                  //__pointer(::user::check) pcheck = ptopic->user_interaction();

               }

            }

         }

      }

//      ::userex::pane_tab_impact::handle(ptopic, pcontext);
      ::user::tab_view::handle(ptopic, pcontext);

   }


} // namespace simple_form





