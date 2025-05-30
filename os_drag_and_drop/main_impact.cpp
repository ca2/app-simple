#include "framework.h"
#include "acme/constant/id.h"
#include "acme/handler/topic.h"


namespace app_simple_os_drag_and_drop
{


   main_impact::main_impact()
   {

      //m_ptopimpact = NULL;
      m_pimpact    = NULL;
      m_flagNonClient.add(e_non_client_background);
      m_flagNonClient.add(e_non_client_focus_rect);


   }


   main_impact::~main_impact()
   {

   }


   //void main_impact::assert_ok() const
   //{

   //   ::user::split_impact::assert_ok();

   //}


   //void main_impact::dump(dump_context & dumpcontext) const
   //{

   //   ::user::split_impact::dump(dumpcontext);

   //}


   void main_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      //::user::split_impact::handle(ptopic, phandlercontext);
      if (ptopic->id() == ::id_click)
      {

         if (ptopic->user_interaction_id() == "simple_drag_and_drop_toggle")
         {

            m_pimpact->set_need_layout();

            return;

            //return true;

         }

      }

      //return false;


   }


   void main_impact::on_create_split_impact()
   {

      if(get_pane_count() > 0)
         return;

      //int iPane;

      SetPaneCount(2);

      SetSplitOrientation(e_orientation_horizontal);

      set_position(0, 31);

      initialize_split_layout();

//      m_ptopimpact = host_impact < ::userex::top_impact >(0, "top_impact");
//
//      if (m_ptopimpact == NULL)
//      {
//
//         output_error_message("Could not create folder edit impact");
//
//      }
//
//      SetPane(0, m_ptopimpact, false);
//
//      iPane = 1;
//
//      m_pimpact = host_impact < impact >(iPane, "simple_drag_and_drop_impact");
//
//      if(m_pimpact == NULL)
//      {
//
//         output_error_message("Could not create file list ::user::impact");
//
//      }
//
//      ::pointer<::userex::top_edit_impact> peditview = get_child_by_id("top_edit_impact");
//
//      if(peditview.is_set())
//      {
//
//         string strText;
//
//         papp->datastream()->get("cur_text",strText);
//
//         peditview->set_text(strText, ::e_source_initialize);
//
//      }
//
////      SetPane(iPane,m_pimpact,false);

   }


   void main_impact::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_impact::_001OnNcDraw(pgraphics);

   }


   void main_impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_impact::_001OnDraw(pgraphics);

   }


   //bool main_impact::BaseOnControlEvent(::user::control_event * pevent)
   //{

   //   if(ptopic->id() == ::id_click)
   //   {

   //      if(ptopic->user_interaction_id() == "simple_drag_and_drop_toggle")
   //      {

   //         m_pimpact->set_need_layout();

   //         return true;

   //      }

   //   }

   //   return false;

   //}

} // namespace app_simple_os_drag_and_drop



