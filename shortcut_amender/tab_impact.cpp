#include "framework.h"
#include "tab_impact.h"
#include "application.h"
#include "form_amender.h"
#include "form_reset_icon.h"
#include "form_set_icon.h"
#include "document.h"
#include "acme/constant/id.h"
#include "acme/constant/impact.h"
#include "acme/handler/topic.h"
#include "base/user/user/tab_pane.h"


namespace app_simple_shortcut_amender
{


   tab_impact::tab_impact()
   {

      m_pimpactLast = NULL;

   }


   tab_impact::~tab_impact()
   {

   }


   //void tab_impact::assert_ok() const
   //{

   //   ::user::impact::assert_ok();

   //}


   //void tab_impact::dump(dump_context & dumpcontext) const
   //{

   //   ::user::impact::dump(dumpcontext);

   //}


   void tab_impact::install_message_routing(::channel * pchannel)
   {

      ::user::tab_impact::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &tab_impact::on_message_create);

   }


   void tab_impact::on_message_create(::message::message * pmessage)
   {

      if(pmessage->previous())
         return;

      add_tab("Menu",MENU_IMPACT);
      add_tab("Amender", "form_amender");
      add_tab("Reset Icon", "form_reset_icon");
      add_tab("Set Icon", "form_set_icon");


      set_current_tab_by_id("form_amender");

   }


   void tab_impact::on_change_cur_sel()
   {

      //::userex::pane_tab_impact::on_change_cur_sel();
      ::user::tab_impact::on_change_cur_sel();
      string strId = get_impact_id();
      string_array stra;

      stra.explode("->:<-",strId);

      if (get_impact_id() == MENU_IMPACT)
      {

         //::pointer<::user::menu_list_impact> pmenuview = get_impact_uie();

         //pmenuview->load_xml_menu("matter://simple_menu.xml");

         //pmenuview->create_inline_menu(m_pimpactdataOld->m_puserinteraction, m_pimpactdata->m_pplaceholder);

         //}

         //hide_all_except({ get_impact_id(), ::impact_karaoke });

      }

      if(get_impact_id() == ::e_impact_simple_form)
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


   void tab_impact::on_create_impact(::user::impact_data * pimpactdata)
   {

      switch(pimpactdata->id().as_int())
      {
      case MENU_IMPACT:
      {

         //::user::impact::create_impact < ::user::menu_list_impact >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->id();

      if (strId.case_insensitive_begins("form_"))
      {

         ::pointer<form> pform;

         if (strId.case_insensitive_equals("form_amender"))
         {


            pform = create_impact<form_amender>(pimpactdata);

         }
         else if(strId.case_insensitive_equals("form_reset_icon"))
         {
            
            pform = create_impact<form_reset_icon>(pimpactdata);

         }
         else if (strId.case_insensitive_equals("form_set_icon"))
         {

            pform = create_impact<form_set_icon>(pimpactdata);

         }

         pform->m_ptabimpact = this;

         pform->id() = pimpactdata->id();

         return;

      }

      ::user::tab_impact::on_create_impact(pimpactdata);

      pimpactdata->m_eflag.add(::user::e_flag_hide_all_others_on_show);

   }


   //bool tab_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   //{

   //   if(m_pdocMenu != nullptr
   //         && dynamic_cast < ::user::impact * > (pimpact) == m_pdocMenu->get_impact(0)
   //         && ptopic->user_interaction() != nullptr)
   //   {

   //      if(ptopic->id() == ::id_after_change_text)
   //      {


   //      }
   //      else if (ptopic->id() == ::id_set_check && ptopic->user_interaction() != NULL)
   //      {

   //         string strCheck = ptopic->user_interaction_id();

   //         if (strCheck.case_insensitive_begins_eat("bilbo"))
   //         {

   //            if (ptopic->user_interaction() != NULL && ptopic->m_actioncontext.is_user_source())
   //            {

   //               //int iCheck = atoi(strCheck);

   //               //::pointer<::user::check> pcheck = ptopic->user_interaction();

   //            }

   //         }

   //      }

   //   }

   //   return false;

   //}


   void tab_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      //////__update(::update)
      //{

      //   if (ptopic->id() == id_control_event
      //         && ptopic->user_interaction() == m_pfontimpact
      //         && m_pimpactLast != NULL)
      //   {

      //      if(pupdate->m_pcontrolevent->m_ehappening == ::id_after_change_cur_sel)
      //      {

      //         string strFont = m_pfontimpact->m_pimpact->get_cur_sel_face_name();

      //      }
      //      else if (pupdate->m_pcontrolevent->m_ehappening == ::id_after_change_cur_hover)
      //      {

      //         string strFont = m_pfontimpact->m_pimpact->get_cur_hover_face_name();

      //      }

      //   }

      //}


      if (m_pdocMenu != nullptr && ptopic->is_about(m_pdocMenu->get_impact(0)))
      {

         if (ptopic->id() == ::id_after_change_text)
         {


         }
         else if (ptopic->id() == ::id_set_check && ::is_set(ptopic->m_puserelement))
         {

            string strCheck = ptopic->user_interaction_id();

            if (strCheck.case_insensitive_begins_eat("bilbo"))
            {

               if (::is_set(ptopic->m_puserelement) && ptopic->m_actioncontext.is_user_source())
               {

                  //int iCheck = atoi(strCheck);

                  //::pointer<::user::check> pcheck = ptopic->user_interaction();

               }

            }

         }

      }

//      ::userex::pane_tab_impact::handle(ptopic, phandlercontext);
      ::user::tab_impact::handle(ptopic, phandlercontext);

   }


} // namespace simple_shortcut





