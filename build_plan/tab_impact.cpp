#include "framework.h"
#include "tab_impact.h"
#include "application.h"
#include "impact.h"
#include "render.h"
#include "acme/constant/user_message.h"
#include "acme/filesystem/filesystem/directory_context.h"
#include "acme/filesystem/filesystem/listing.h"
#include "berg/user/user/tab_pane.h"


namespace app_simple_build_plan
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

      USER_MESSAGE_LINK(::user::e_message_create, pchannel, this, &tab_impact::on_message_create);

   }


   void tab_impact::on_message_create(::message::message * pmessage)
   {

      if(pmessage->previous())
      {

         return;

      }

      ::file::path pathBuildPlanFolder = "google_drive://application/app-simple/build_plan";

      auto files = directory()->files(pathBuildPlanFolder);

      files.predicate_sort(
         [](auto &path1, auto &path2)
         {
            return path1 > path2;
         });

      int iLimitCount = 10;

      auto & straBuildPlan = m_papp->m_straBuildPlan;

      for (auto & path : files)
      {

         ::string strName = path.name();

         if (strName.ends_eat(".build_plan_spreadsheet_export"))
         {

            auto strBuildPlan = strName;

            straBuildPlan.add(strBuildPlan);

            if (straBuildPlan.size() >= 10)
            {

               break;

            }

         }

      }

      ::string_array & straBuildPlanId = m_papp->m_straBuildPlanId;

      add_tab("Menu", MENU_IMPACT);

      if (straBuildPlan.has_element())
      {
         for (auto &strBuildPlan: straBuildPlan)
         {
            ::string strBuildPlanId;
            strBuildPlanId = "build_plan:" + strBuildPlan;
            add_tab(strBuildPlan, strBuildPlanId);
            straBuildPlanId.add(strBuildPlanId);
         }
         set_current_tab_by_id(straBuildPlanId.first());
      }
      //set_tab("05Jul2026", "build_plan:05Jul2026");
      //set_tab("12Jun2026", "build_plan:12Jun2026");
      //set_tab("text://app-simple/build_plan/:002", "drawing2");
      //set_tab("text://app-simple/build_plan/:003", "drawing3");
      //set_tab("text://app-simple/build_plan/:box gradient", "drawing4");
      //set_tab("text://app-simple/build_plan/:circle path", "drawing5");
      //set_tab("text://app-simple/build_plan/:arcs", "drawing6");
      //set_tab("text://app-simple/build_plan/:arcpths", "drawing7");

      

   }


   void tab_impact::on_change_cur_sel()
   {

      ::user::tab_impact::on_change_cur_sel();

      string strId = get_impact_id();

      string_array_base stra;

      stra.explode("->:<-",strId);

      string strImpactId = get_impact_id();

      if(string_begins(strImpactId, "drawing"))
      {

         auto ptabpaneFileManager = get_tab_by_id("file_manager_impact");

         if(ptabpaneFileManager != nullptr && ptabpaneFileManager->m_pplaceholder != nullptr)
         {

            ptabpaneFileManager->m_pplaceholder->display(e_display_hide, {});

         }

         auto ptabpaneFontSel = get_tab_by_id("font_selection_impact");

         if (ptabpaneFontSel != nullptr && ptabpaneFontSel->m_pplaceholder != nullptr)
         {

            ptabpaneFontSel->m_pplaceholder->display(e_display_hide, {});

         }

         m_pimpactDrawing = m_pimpactdata->m_pplaceholder->get_hold();

      }
      
   }


   void tab_impact::on_create_impact(::user::impact_data * pimpactdata)
   {

      if (get_app()->has_property("notabs"))
      {

         return;

      }

      string strId = pimpactdata->id();

      if(strId.case_insensitive_begins_eat("build_plan:"))
      {

         auto pimpact = get_app()->create_simple_build_plan_impact(this, pimpactdata);

         pimpact->id() = pimpactdata->id();

         pimpact->initialize_simple_build_plan(strId);

         pimpactdata->m_eflag.add(::user::e_flag_hidid_on_show);

      }

      ::user::tab_impact::on_create_impact(pimpactdata);

   }


   void tab_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      ::user::tab::handle(ptopic, phandlercontext);

   }


} // namespace simple_build_plan



