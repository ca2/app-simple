#include "framework.h"
#include "aura/update.h"
#include "video_input/video_input.h"
#include "video_input/video_device_array.h"
#include "video_input/video_device.h"


void video_input_stop_event(int deviceID, void * userData)
{
   
   auto & videoinput = ::video_input::video_input::get_instance();

   videoinput.close_device(deviceID);

}


namespace simple_video
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

      set_tab("Menu", MENU_IMPACT);

      set_tab("video", "video");

      set_cur_tab_by_id("video");

      //set_tab("002", "video2");
      //set_tab("003", "video3");
      //set_tab("arcs", "video4");
      //set_tab("arcpths", "video5");
      //set_tab("Font", FONTSEL_IMPACT);
      //set_tab("Color", COLORSEL_IMPACT);
      //set_tab("Open", FILEMANAGER_IMPACT);

      //set_cur_tab_by_id("video1");

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

         auto str = prepare_menu_view();

         if (!m_pdocMenu->open_document(str))
         {

            GetParentFrame()->message_box("Failed to open the menu.");

            return;

         }

         ::user::impact * pview = m_pdocMenu->get_view(0);

         pview->set_need_load_form_data();

      }

      string strViewId = get_view_id().to_string();

      if(::str::begins(strViewId, "video"))
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

   }


   string tab_view::prepare_menu_view()
   {

      string strHtml;

      string strBilbo;

      auto & videoinput = ::video_input::video_input::get_instance();

      auto cCount = videoinput.list_devices();

      m_checkptraDevice.set_size(cCount);

      strHtml += "<html>";
      strHtml += "<head>";
      strHtml += "</head>";
      strHtml += "<body>";

      for (int i = 0; i < cCount; i++)
      {

         string strName;

         strName = videoinput.get_video_device_name(i);

         string strId;

         strId = videoinput.get_video_device_id2(i);

         strHtml +="<input type = \"checkbox\" id=\"" + strId + "\" /><h1>" + strName + "</h1><br/>\n";

      }

      strHtml += "</body>";

      ::file::path path;

      path = Context.dir().appdata() / "menu.html";

      Context.file().put_contents(path, strHtml);
   
      return path;

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

         auto puser = User;

         m_pdocMenu = puser->create_child_form(this, this, pimpactdata->m_pplaceholder);

         pimpactdata->m_eflag.add(::user::e_flag_hide_on_kill_focus);

      }
      break;
      }

      string strId = pimpactdata->m_id;

      if(::str::begins_eat_ci(strId, "video"))
      {

         auto pview = ThisApp.create_simple_video_view(this, pimpactdata);

         pview->m_id = pimpactdata->m_id;

         pimpactdata->m_eflag.add(::user::e_flag_hide_topic_on_show);

      }

      ::user::tab_view::on_create_impact(pimpactdata);

   }




   void tab_view::on_control_event(::user::control_event * pevent)
   {

      string strId = pevent->m_id;

      if (pevent->m_eevent == ::user::e_event_load_form_data)
      {

         ::user::impact * pview = m_pdocMenu->get_view(0);

         string str;

         auto puiRollFps = pview->get_child_by_id("roll_fps");

         auto & videodevicearray = ::video_input::video_device_array::get_instance();

         for (auto & videodevice : videodevicearray.m_deviceptra)
         {

            string strId = System.crypto_md5_text(videodevice->m_strName);

            auto pcheckbox = pview->get_child_by_id(strId);

            bool bSelected = ThisApp.m_pview->m_prender->m_strDevice == strId;

            pcheckbox->_001SetCheck(bSelected? ::check_checked : ::check_unchecked, ::source_sync);

         }

         pevent->m_bOk = true;

         pevent->m_bRet = true;

         return;

      }

   else if (pevent->m_eevent == ::user::e_event_set_check)
   {
         if (pevent->m_actioncontext.is_user_source())
         {

            for (auto & pcheck : m_checkptraDevice)
            {

               ThisApp.m_pview->m_prender->initialize_simple_video(strId);

            }

         }

      }


   }


   void tab_view::on_subject(::promise::subject * psubject, ::promise::context * pcontext)
   {


      ::user::tab_view::on_subject(psubject, pcontext);

   }


} // namespace simple_video



