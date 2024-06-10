#include "framework.h"
#include "application.h"
#include "impact_path.h"
#include "impact_folder_path.h"
#include "impact_netnode_url.h"
#include "impact_start_button.h"
#include "main_impact.h"
#include "acme/constant/id.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/handler/topic.h"
#include "apex/database/_binary_stream.h"


namespace app_simple_http_folder_upload
{


   impact_path::impact_path()
   {


      m_pmainimpact = nullptr;

      m_flagNonClient.add(e_non_client_background);
      m_flagNonClient.add(e_non_client_focus_rect);


   }


   impact_path::~impact_path()
   {

   }


   void impact_path::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->m_atom == ::id_click)
      {

      }

      ::user::split_impact::handle(ptopic, pcontext);

   }


   void impact_path::on_create_split_impact()
   {

      if (get_pane_count() > 0)
      {

         return;

      }


      int iPane;

      //if (papp->m_bMultiverseChat)
      //{

      //   SetPaneCount(2);

         SetSplitOrientation(e_orientation_vertical);

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

         SetPaneCount(3);

         set_position_rate(0, 0.4);

         set_position_rate(1, 0.8);

         initialize_split_layout();

         iPane = 0;

      }

      m_pimpactfolderpath = host_impact < ::app_simple_http_folder_upload::impact_folder_path >(0);

      if (m_pimpactfolderpath == NULL)
      {

         output_error_message("Could not create file list ::user::impact");

      }

      m_pimpactfolderpath->m_pimpactpath = this;

      m_pimpactfolderpath->add_handler(this);

      m_pimpactnetnodeurl = host_impact < ::app_simple_http_folder_upload::impact_netnode_url >(1);

      if (m_pimpactnetnodeurl == NULL)
      {

         output_error_message("Could not create file list ::user::impact");

      }

      m_pimpactnetnodeurl->m_pimpactpath = this;

      m_pimpactnetnodeurl->add_handler(this);


      m_pimpactstartbutton = host_impact < ::app_simple_http_folder_upload::impact_start_button >(2);

      if (m_pimpactstartbutton == NULL)
      {

         output_error_message("Could not create file list ::user::impact");

      }

      m_pimpactstartbutton->m_pimpactpath = this;

      m_pimpactstartbutton->add_handler(this);
      //::string strUrl;

      //get_app()->datastream()->get("folder", strUrl);

      //if (strUrl.is_empty())
      //{

      //   strUrl = acmedirectory()->home();

      //}

      //m_peditimpact->set_text(strUrl, ::e_source_initialize);

      //m_pimpact->m_pmainimpact = this;

      //get_app()->m_pathFolder = strUrl;

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


   void impact_path::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_impact::_001OnNcDraw(pgraphics);

   }


   void impact_path::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::split_impact::_001OnDraw(pgraphics);

   }


} // namespace app_simple_http_folder_upload



