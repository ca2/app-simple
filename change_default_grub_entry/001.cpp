#include "framework.h"
#include <math.h>


namespace simple_change_grub_default_entry
{


   simple_change_grub_default_entry_001::simple_change_grub_default_entry_001()
   {

   }


   simple_change_grub_default_entry_001::~simple_change_grub_default_entry_001()
   {

   }


   void simple_change_grub_default_entry_001::assert_valid() const
   {

      simple_change_grub_default_entry::assert_valid();

   }


   void simple_change_grub_default_entry_001::dump(dump_context & dumpcontext) const
   {

      simple_change_grub_default_entry::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t simple_change_grub_default_entry_001::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t simple_change_grub_default_entry_001::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void simple_change_grub_default_entry_001::install_message_routing(::channel * psender)
   {

      simple_change_grub_default_entry::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &simple_change_grub_default_entry_001::on_message_create);

   }


   void simple_change_grub_default_entry_001::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __compose_new(m_pstill);

      __compose_new(m_pedit);

      __compose_new(m_plistbox);

      //__compose_new(m_pbuttonClear);

      //__compose_new(m_pbuttonSend);

      m_pstill->create_control(this, "still");

      m_pedit->create_control(this, "edit");

      m_pedit->add_control_event_handler(this);

      m_plistbox->create_control(this, "list_box");

      m_plistbox->add_control_event_handler(this);

      //m_pbuttonClear->create_control(this, "clear_button");

      //m_pbuttonClear->add_control_event_handler(this);

      //m_pbuttonSend->create_control(this, "send_button");

      //m_pbuttonSend->add_control_event_handler(this);

      m_pstill->set_window_text("Grub Folder:");

      m_pedit->m_strEmtpyText = "Enter Grub Folder Here";

      string strInitialText;

      auto papplication = get_application();

      strInitialText = papplication->data_get("last_text");

      m_pedit->_001SetText(strInitialText, ::e_source_initialize);

      //m_pbuttonClear->set_window_text("Clear");

      //m_pbuttonSend->set_window_text("Send");

   }


   void simple_change_grub_default_entry_001::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_view::on_layout(pgraphics);

      double iLeft = 10.;

      double y = 10.;

      ::rectangle_i32 rectangleClient;

      get_client_rect(rectangleClient);

      auto sizeStill = m_pstill->_001CalculateAdjustedFittingSize(pgraphics);

      auto rectStillMargin = m_pstill->get_margin(m_pstill->get_style(pgraphics));

      y += rectStillMargin.top;

      m_pstill->display_child(::rectd_dim(iLeft, y, sizeStill.cx, sizeStill.cy));

      y += sizeStill.cy;

      y += rectStillMargin.bottom;

      auto sizeEdit = m_pedit->_001CalculateAdjustedFittingSize(pgraphics);

      auto rectEditMargin = m_pedit->get_margin(m_pedit->get_style(pgraphics), ::user::e_element_none);

      y += rectEditMargin.top;

      m_pedit->display_child(::rectd_dim(iLeft, y, 600, sizeEdit.cy));

      y += sizeEdit.cy;

      y += rectEditMargin.bottom;

      m_plistbox->display_child(::rectd_dim(iLeft, y, rectangleClient.width() - iLeft * 2, rectangleClient.bottom - iLeft - y));

      m_plistbox->set_need_layout();

      //auto sizeButtonClear = m_pbuttonClear->_001CalculateAdjustedFittingSize(pgraphics);

      //auto sizeButtonSend = m_pbuttonSend->_001CalculateAdjustedFittingSize(pgraphics);

      //auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_pedit->get_style(pgraphics));

      //auto sizeButtonMarginSend = m_pbuttonSend->get_margin(m_pedit->get_style(pgraphics));

      //y += maximum(sizeButtonMarginClear.top, sizeButtonMarginSend.top);

      //auto button_width = maximum(sizeButtonClear.cx + 32, sizeButtonSend.cx + 32);

      //auto button_height = maximum(sizeButtonClear.cy, sizeButtonSend.cy);

      //m_pbuttonClear->display_child(::rectd_dim(iLeft, y, button_width, button_height));

      //m_pbuttonSend->display_child(::rectd_dim(iLeft + button_width + 32, y, button_width, button_height));

   }


   void simple_change_grub_default_entry_001::on_control_event(::user::control_event * pevent)
   {

      if (pevent->m_eevent == ::user::e_event_after_change_cur_sel)
      {

         string strSavedEntry = m_plistbox->get_current_item_string_value();

         if(strSavedEntry.has_char())
         {

            auto pcontext = m_pcontext->m_papexcontext;

            auto pathGrubFolder = get_grub_folder_path();

            set_grub_saved_entry(pathGrubFolder, strSavedEntry);

         }

      }
      else if (pevent->m_eevent == ::user::e_event_after_change_text)
      {

         if (pevent->m_id == "edit")
         {

            string strText;

            m_pedit->_001GetText(strText);

            auto papplication = get_application();

            papplication->data_set("grub_folder_path", strText);

            update_grub_entry_list(strText);

         }

      }
      else if (pevent->m_eevent == ::user::e_event_button_clicked)
      {

         if (pevent->m_id == "clear_button")
         {

            m_pedit->_001SetText("", ::e_source_user);

         }
         else if (pevent->m_id == "send_button")
         {

            string strText;

            m_pedit->_001GetText(strText);

            message_box("send_button clicked\nText: " + strText);

            pevent->m_bRet = true;

         }

      }

   }


   ::file::path simple_change_grub_default_entry_001::get_grub_folder_path()
   {

      string strGrubFolderPath;

      m_pedit->_001GetText(strGrubFolderPath);

      return strGrubFolderPath;

   }


   ::file::path simple_change_grub_default_entry_001::get_grubenv_path(const ::file::path& pathGrubFolder)
   {

      auto pathGrubEnv = pathGrubFolder / "grubenv";

      return pathGrubEnv;

   }


   ::file::path simple_change_grub_default_entry_001::get_grub_cfg_path(const ::file::path& pathGrubFolder)
   {

      auto pathGrubEnv = pathGrubFolder / "grub.cfg";

      return pathGrubEnv;

   }


   ::e_status simple_change_grub_default_entry_001::update_grub_entry_list(const ::file::path& pathGrubFolder)
   {

      auto pcontext = m_pcontext->m_papexcontext;

      string_array straLines;

      auto pathGrubCfg = get_grub_cfg_path(pathGrubFolder);
      
      pcontext->file().lines(straLines, pathGrubCfg);

      ::index iFind = 0;

      m_plistbox->reset_content();

      string strLine;

      while ((iFind = straLines.find_first_begins_eat(strLine, "menuentry", iFind)) >= 0)
      {

         if (strLine.has_char() && strLine[0] == ' ')
         {

            string strEntryName = ::str::consume_command_line_argument(strLine);

            string strValue;

            while (strLine.has_char())
            {

               string strItem = ::str::consume_command_line_argument(strLine);

               strItem.trim();

               if (strItem.begins("-"))
               {

                  ::str::consume_command_line_argument(strLine);

               }
               else if (strItem.begins("$"))
               {

               }
               else
               {

                  strValue = strItem;

                  break;

               }


            }

            if (strEntryName.has_char() && strValue.has_char())
            {

               m_plistbox->add_string(strEntryName, strValue);

            }

            auto iBracket = straLines.find_first_begins("}", iFind);

            if (iBracket >= 0)
            {
               
               auto iSubMenu = straLines.find_first_begins("submenu", iBracket);

               if (iSubMenu >= 0)
               {

                  iFind = straLines.find_first_begins("}", iSubMenu);

               }

            }


         }

         iFind++;

      }

      return ::success;

   }


   string simple_change_grub_default_entry_001::get_grub_saved_entry(const ::file::path& pathGrubFolder)
   {

      string_array straLines;

      auto pcontext = m_pcontext->m_papexcontext;

      auto pathGrubEnv = get_grubenv_path(pathGrubFolder);

      pcontext->file().lines(straLines, pathGrubEnv);

      string strEntry;

      auto iFind = straLines.find_first_begins_eat(strEntry, "saved_entry=");

      if (iFind < 0)
      {

         return "";

      }

      strEntry.trim();

      return strEntry;

   }

   
   ::e_status simple_change_grub_default_entry_001::set_grub_saved_entry(const ::file::path& pathGrubFolder, const string& strSavedEntry)
   {

      if (strSavedEntry == get_grub_saved_entry(pathGrubFolder))
      {

         return ::success;

      }

      auto pcontext = m_pcontext->m_papexcontext;

      auto pathGrubEnv = get_grubenv_path(pathGrubFolder);

      auto memory = pcontext->file().as_memory(pathGrubEnv);

      auto estatus = memory.patch_line_suffix("saved_entry=", strSavedEntry);

      if (!estatus)
      {

         return estatus;

      }

      estatus = pcontext->file().set(pathGrubEnv, memory);

      if (!estatus)
      {

         return estatus;

      }

      return estatus;

   }


} // namespace simple_change_grub_default_entry



