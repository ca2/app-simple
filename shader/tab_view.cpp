#include "framework.h"
#include "aura/update.h"
#include "base/user/user/tab_pane.h"


namespace app_simple_shader
{


   tab_view::tab_view()
   {

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

      ::user::tab_view::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &tab_view::on_message_create);

   }


   void tab_view::on_message_create(::message::message * pmessage)
   {

      if(pmessage->previous())
      {

         return;

      }

      //initialize_application_consumer();

      m_papplication->m_ptabview = this;

      _001SetVertical();

      auto papplication = get_application();

      ::file::listing listing;

      papplication->get_shader_listing(listing);

      set_tab("Menu", MENU_IMPACT);

      for (auto& path : listing)
      {

         string strTitle = path.title();

         string strPath = path;

         set_tab(strTitle, "shader://" + strPath);

      }

      //set_tab("1", "shader1");
      //set_tab("2", "shader2");
      //set_tab("3", "shader3");
      //set_tab("4", "shader4");
      //set_tab("5", "shader5");
      //set_tab("6", "shader6");
      //set_tab("7", "shader7");
      //set_tab("8", "shader8");
      //set_tab("9", "shader9");
      //set_tab("10", "shader10");
      //set_tab("11", "shader11");
      //set_tab("12", "shader12");
      //set_tab("13", "shader13");
      //set_tab("14", "shader14");

      //set_tab("Font", FONTSEL_IMPACT);
      //set_tab("Color", COLORSEL_IMPACT);
      //set_tab("Open", FILEMANAGER_IMPACT);

      set_current_tab_by_index(1);

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

//      if (get_view_id() == MENU_IMPACT)
//      {
//
//         __pointer(::user::menu_list_view) pmenuview = get_view_uie();
//
//         pmenuview->destroy_menu();
//
//       }

      if(::str::begins_eat_ci(strId, "shader://"))
      {

         string strShaderPath = strId;

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

         ::user::impact::create_view < ::user::menu_list_view >(pimpactdata);

      }
      break;
      }

      string strId = pimpactdata->m_id;

      if(::str::begins_eat_ci(strId, "shader://"))
      {

         string strShaderPath = strId;

         auto pview = m_papplication->create_simple_shader_view(this, pimpactdata);

         pview->m_id = pimpactdata->m_id;

         pview->m_iView = (int) pimpactdata->m_iIndex;

         __pointer(app_simple_shader::impact) pviewShader = pview;

         pviewShader->m_prender->m_strShaderPath = strShaderPath;

         pimpactdata->m_eflag.add(::user::e_flag_hidid_on_show);

      }

      ::user::tab_view::on_create_impact(pimpactdata);

   }


   void tab_view::handle(::topic * ptopic, ::context * pcontext)
   {



   }


//   void tab_view::handle(::topic * ptopic, ::context * pcontext)
//   {
//
//
//      ::user::tab_view::handle(ptopic, pcontext);
//
//   }


} // namespace simple_shader



