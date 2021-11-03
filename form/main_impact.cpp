﻿#include "framework.h"


namespace app_simple_form
{


   main_impact::main_impact()
   {

      //m_ptopview = NULL;
      m_pimpact    = NULL;
      m_flagNonClient.add(non_client_background);
      m_flagNonClient.add(non_client_focus_rect);


   }


   main_impact::~main_impact()
   {

   }


   void main_impact::assert_valid() const
   {

      ::user::split_view::assert_valid();

   }


   void main_impact::dump(dump_context & dumpcontext) const
   {

      ::user::split_view::dump(dumpcontext);

   }


   void main_impact::handle(::subject * psubject, ::context * pcontext)
   {

      if (psubject->m_id == ::e_subject_click)
      {

         if (psubject->user_interaction()->m_id == "simple_form_toggle")
         {

            m_pimpact->set_need_layout();

            return;

         }

      }

      ::user::split_view::handle(psubject, pcontext);



   }


   void main_impact::on_create_split_impact()
   {

      if(get_pane_count() > 0)
      {

         return;

      }


      int iPane;

      //if (papplication->m_bMultiverseChat)
      //{

      //   SetPaneCount(2);

      //   SetSplitOrientation(e_orientation_horizontal);

      //   set_position(0, 31);

      //   initialize_split_layout();

      //   m_ptopview = host_view < ::userex::top_view >(0, "top_view");

      //   if (m_ptopview == NULL)
      //   {

      //      output_error_message("Could not create folder edit impact");

      //   }

      //   iPane = 1;

      //}
      //else
      {

         SetPaneCount(1);

         initialize_split_layout();

         iPane = 0;

      }

      //m_pimpact = create_view < lite_view >();

      m_pimpact = host_view < impact >(iPane, "simple_form_view");

      if(m_pimpact == NULL)
      {

         output_error_message("Could not create file list ::user::impact");

      }

//      __pointer(::userex::top_edit_view) peditview = get_child_by_id("top_edit_view");
//
//      if(peditview.is_set())
//      {
//
//         string strText;
//
//         papplication->data_get("cur_text",strText);
//
//         peditview->_001SetText(strText, ::e_source_initialize);
//
//      }
//
////      SetPane(iPane,m_pimpact,false);

   }


   void main_impact::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_view::_001OnNcDraw(pgraphics);

   }


   void main_impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_view::_001OnDraw(pgraphics);

   }


   //bool main_impact::handle(::subject * psubject, ::context * pcontext)
   //{

   //   if(psubject->m_id == ::e_subject_click)
   //   {

   //      if(psubject->user_element_id() == "simple_form_toggle")
   //      {

   //         m_pimpact->set_need_layout();

   //         return true;

   //      }

   //   }

   //   return false;

   //}


} // namespace simple_form



