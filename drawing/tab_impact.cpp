#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif
#include "aura/update.h"
#include "base/user/user/tab_pane.h"


namespace app_simple_drawing
{


   tab_impact::tab_impact()
   {

   }


   tab_impact::~tab_impact()
   {

   }


   void tab_impact::assert_ok() const
   {

      ::user::impact::assert_ok();

   }


   void tab_impact::dump(dump_context & dumpcontext) const
   {

      ::user::impact::dump(dumpcontext);

   }


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

      set_tab("Menu", MENU_IMPACT);
      set_tab("text://app-simple/drawing/:001", "drawing1");
      set_tab("text://app-simple/drawing/:002", "drawing2");
      set_tab("text://app-simple/drawing/:003", "drawing3");
      set_tab("text://app-simple/drawing/:box gradient", "drawing4");
      set_tab("text://app-simple/drawing/:circle path", "drawing5");
      set_tab("text://app-simple/drawing/:arcs", "drawing6");
      set_tab("text://app-simple/drawing/:arcpths", "drawing7");


      set_current_tab_by_id("drawing1");

   }


   void tab_impact::on_change_cur_sel()
   {

      ::user::tab_impact::on_change_cur_sel();

      string strId = get_impact_id();

      string_array stra;

      stra.explode("->:<-",strId);

      string strImpactId = get_impact_id().to_string();

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

         __refer(m_pimpactDrawing,m_pimpactdata->m_pplaceholder->get_hold());

      }

   }


   void tab_impact::on_create_impact(::user::impact_data * pimpactdata)
   {

      if (get_app()->has_property("notabs"))
      {

         return;

      }

      switch(pimpactdata->m_atom)
      {
      case MENU_IMPACT:
      {

         //::user::impact::create_impact < ::user::menu_list_impact >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->m_atom;

      if(::str().begins_eat_ci(strId, "drawing"))
      {

         auto pimpact = get_app()->create_simple_drawing_impact(this, pimpactdata);

         pimpact->m_atom = pimpactdata->m_atom;

         pimpact->m_prender->initialize_simple_drawing(atoi(strId));

         pimpactdata->m_eflag.add(::user::e_flag_hidid_on_show);

      }

      ::user::tab_impact::on_create_impact(pimpactdata);

   }


   void tab_impact::handle(::topic * ptopic, ::context * pcontext)
   {


   }


} // namespace simple_drawing


