#include "framework.h"
#include "application.h"
#include "impact.h"
#include "main_impact.h"
#include "edit_impact.h"
#include "acme/constant/id.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/handler/topic.h"
#include "apex/database/_binary_stream.h"


namespace app_simple_http_file_server
{


   main_impact::main_impact()
   {

      m_flagNonClient.add(e_non_client_background);
      m_flagNonClient.add(e_non_client_focus_rect);


   }


   main_impact::~main_impact()
   {

   }


   void main_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == ::id_click)
      {

      }

      ::user::split_impact::handle(ptopic, phandlercontext);

   }


   void main_impact::on_create_split_impact()
   {

      if (get_pane_count() > 0)
      {

         return;

      }


      int iPane;

      //if (papp->m_bMultiverseChat)
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

         SetPaneCount(2);

         set_position(0, 40);

         initialize_split_layout();

         iPane = 0;

      }

      m_peditimpact = host_impact < ::app_simple_http_file_server::edit_impact >(0);

      m_peditimpact->m_pmainimpact = this;

      if (m_peditimpact == NULL)
      {

         output_error_message("Could not create file list ::user::impact");

      }

      m_pimpact = host_impact < ::app_simple_http_file_server::impact >(1);

      if (m_pimpact == NULL)
      {

         output_error_message("Could not create file list ::user::impact");

      }

      m_peditimpact->add_handler(m_pimpact);

      ::string strUrl;

      get_app()->datastream()->get("folder", strUrl);

      if (strUrl.is_empty())
      {

         strUrl = directory_system()->home();

      }

      m_peditimpact->set_text(strUrl, ::e_source_initialize);

      m_pimpact->m_pmainimpact = this;

      get_app()->m_pathFolder = strUrl;

      //      ::pointer < ::userex::top_edit_view) peditview = get_child_by_id("top_edit_view");
      //
      //      if(peditview.is_set())
      //      {
      //
      //         string strText;
      //
      //         papp->data_get("cur_text",strText);
      //
      //         peditview->set_text(strText, ::e_source_initialize);
      //
      //      }
      //
      ////      SetPane(iPane,m_puserform,false);

   }


   void main_impact::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_impact::_001OnNcDraw(pgraphics);

   }


   void main_impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_impact::_001OnDraw(pgraphics);

   }


} // namespace app_simple_http_file_server



