#include "framework.h"
#include "aura/update.h"


namespace simple_drawing
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

      MESSAGE_LINK(e_message_create, pchannel, this, &tab_view::_001OnCreate);

   }


   void tab_view::_001OnCreate(::message::message * pmessage)
   {

      if(pmessage->previous())
      {

         return;

      }

      //Application.m_ptabview = this;

      set_tab("Menu", MENU_IMPACT);
      set_tab("001", "drawing1");
      set_tab("002", "drawing2");
      set_tab("003", "drawing3");
      set_tab("arcs", "drawing4");
      set_tab("arcpths", "drawing5");
      //set_tab("Font", FONTSEL_IMPACT);
      //set_tab("Color", COLORSEL_IMPACT);
      //set_tab("Open", FILEMANAGER_IMPACT);

      set_cur_tab_by_id("drawing1");

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

      if (get_view_id() == MENU_IMPACT)
      {

         __pointer(::user::menu_list_view) pmenuview = get_view_uie();

         pmenuview->destroy_menu();

         if (pmenuview->load_xml_menu("matter://simple_menu.xml"))
         {

            pmenuview->create_inline_menu(this, m_pimpactdata->m_pplaceholder);

         }

      }

      string strViewId = get_view_id().to_string();

      if(::str::begins(strViewId, "drawing"))
      {

         if(get_pane_by_id(FILEMANAGER_IMPACT) != nullptr && get_pane_by_id(FILEMANAGER_IMPACT)->m_pplaceholder != nullptr)
         {

            get_pane_by_id(FILEMANAGER_IMPACT)->m_pplaceholder->hide();

         }

         if (get_pane_by_id(FONTSEL_IMPACT) != nullptr && get_pane_by_id(FONTSEL_IMPACT)->m_pplaceholder != nullptr)
         {

            get_pane_by_id(FONTSEL_IMPACT)->m_pplaceholder->hide();

         }

         __refer(m_pviewTopic,m_pimpactdata->m_pplaceholder->get_hold());

      }
      //else if (get_view_id() == MENU_IMPACT)
      //{

      //   m_pdocMenu->open_document("matter://menu.html");

      //}

   }


   void tab_view::on_create_impact(::user::impact_data * pimpactdata)
   {

      if (Application.has_property("notabs"))
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

      if(::str::begins_eat_ci(strId, "drawing"))
      {

         auto pview = ThisApp.create_simple_drawing_view(this, pimpactdata);

         pview->m_id = pimpactdata->m_id;

         pview->m_prender->initialize_simple_drawing(atoi(strId));

         pimpactdata->m_eflag.add(::user::flag_hide_topic_on_show);

      }

      ::user::tab_view::on_create_impact(pimpactdata);

   }




   void tab_view::on_control_event(::user::control_event * pevent)
   {


   }


   void tab_view::on_apply(::action * paction)
   {


      ::user::tab_view::on_apply(paction);

   }


} // namespace simple_drawing



