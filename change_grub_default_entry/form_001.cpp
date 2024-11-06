#include "framework.h"
#include "form_001.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/platform/node.h"
#include "acme/handler/topic.h"
#include "acme/prototype/string/str.h"
#include "apex/database/_binary_stream.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "aura/message/user.h"
#include "aura/user/user/button.h"
#include "aura/user/user/still.h"
#include "aura/user/user/plain_edit.h"
#include "axis/user/user/list_box.h"


::e_status grub_set_variable(memory& memoryGrubEnv, const ::block& blockVariablePrefix, const block& blockValue);


namespace app_simple_change_grub_default_entry
{


   form_001::form_001()
   {

   }


   form_001::~form_001()
   {

   }


   //void form_001::assert_ok() const
   //{

   //   form::assert_ok();

   //}


   //void form_001::dump(dump_context & dumpcontext) const
   //{

   //   form::dump(dumpcontext);

   //}


#ifdef _DEBUG


   int64_t form_001::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   int64_t form_001::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form_001::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form_001::on_message_create);

   }


   void form_001::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __construct_new(m_pstill);

      __construct_new(m_pedit);

      __construct_new(m_plistbox);

      __construct_new(m_pbuttonRestart);

      m_pstill->create_control(this, "still");

      m_pedit->create_control(this, "edit");

      m_pedit->add_handler(this);

      m_plistbox->create_control(this, "list_box");

      m_plistbox->add_handler(this);

      m_pbuttonRestart->create_control(this, "restart_button");

      m_pbuttonRestart->add_handler(this);

      m_pstill->set_window_text("Grub Folder:");

      m_pedit->m_strEmtpyText = "Enter Grub Folder Here";

      string strFolderPath;

      ::cast < ::database::client > pdatabaseclient = application();

      pdatabaseclient->datastream()->get("grub_folder_path", strFolderPath);

      m_pedit->set_text(strFolderPath, ::e_source_initialize);

      m_pbuttonRestart->set_window_text("Restart Now");

   }


   void form_001::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_impact::on_layout(pgraphics);

      double iLeft = 10.;

      double y = 10.;

      auto rectangleX = this->rectangle();

      auto sizeStill = m_pstill->get_adjusted_fitting_size(pgraphics);

      auto rectangleStillMargin = m_pstill->get_margin(m_pstill->get_style(pgraphics));

      y += rectangleStillMargin.top();

      m_pstill->display_child(::rectangle_double_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

      y += sizeStill.cy();

      y += rectangleStillMargin.bottom();

      auto sizeEdit = m_pedit->get_adjusted_fitting_size(pgraphics);

      auto rectangleEditMargin = m_pedit->get_margin(m_pedit->get_style(pgraphics), ::e_element_none);

      y += rectangleEditMargin.top();

      m_pedit->display_child(::rectangle_double_dimension(iLeft, y, 600, sizeEdit.cy()));


      //auto sizeButtonClear = m_pbuttonClear->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonRestart = m_pbuttonRestart->get_adjusted_fitting_size(pgraphics);

      //auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_pedit->get_style(pgraphics));

      auto sizeButtonMarginRestart = m_pbuttonRestart->get_margin(m_pedit->get_style(pgraphics));

      //y += maximum(sizeButtonMarginClear.top(), sizeButtonMarginSend.top());

      auto button_width = sizeButtonRestart.cx() + 32;

      auto button_height = sizeButtonRestart.cy();

      //m_pbuttonClear->display_child(::rectangle_double_dimension(iLeft, y, button_width, button_height));

      y += sizeButtonMarginRestart.top();

      m_pbuttonRestart->display_child(::rectangle_double_dimension(rectangleX.right() - iLeft - button_width, y, button_width, button_height));

      y += sizeButtonMarginRestart.bottom();

      y += button_height;

      y += sizeEdit.cy();

      y += rectangleEditMargin.bottom();

      m_plistbox->display_child(::rectangle_double_dimension(iLeft, y, rectangleX.width() - iLeft * 2, rectangleX.bottom() - iLeft - y));

      m_plistbox->set_need_layout();
   }


   void form_001::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->m_atom == ::id_after_change_cur_sel)
      {

         if (ptopic->m_puserelement->user_interaction()->m_atom == "list_box")
         {

            auto atomSavedEntry = m_plistbox->get_current_item_atom();

            if (atomSavedEntry.has_char())
            {

               auto pcontext = m_papplication;

               auto pathGrubFolder = get_grub_folder_path();

               set_grub_saved_entry(pathGrubFolder, atomSavedEntry.as_string());

            }

         }

      }
      else if (ptopic->m_atom == ::id_after_change_text)
      {

         if (ptopic->m_puserelement->user_interaction()->m_atom == "edit")
         {

            string strText;

            m_pedit->get_text(strText);

            if(ptopic->m_actioncontext.is_user_source())
            {

               ::cast < ::database::client > pdatabaseclient = application();

               pdatabaseclient->datastream()->set("grub_folder_path", strText);

            }

            update_grub_entry_list(strText);

         }

      }
      else if (ptopic->m_atom == ::id_click)
      {

         if (ptopic->m_puserelement->user_interaction()->m_atom == "clear_button")
         {

            m_pedit->set_text("", ::e_source_user);

         }
         else if (ptopic->m_puserelement->user_interaction()->m_atom == "restart_button")
         {

            auto pnode = node();

            pnode->reboot();

            ptopic->m_bRet = true;

         }

      }

   }


   ::file::path form_001::get_grub_folder_path()
   {

      string strGrubFolderPath;

      m_pedit->get_text(strGrubFolderPath);

      return strGrubFolderPath;

   }


   ::file::path form_001::get_grubenv_path(const ::file::path& pathGrubFolder)
   {

      auto pathGrubEnv = pathGrubFolder / "grubenv";

      return pathGrubEnv;

   }


   ::file::path form_001::get_grub_cfg_path(const ::file::path& pathGrubFolder)
   {

      auto pathGrubEnv = pathGrubFolder / "grub.cfg";

      return pathGrubEnv;

   }


   ::e_status form_001::update_grub_entry_list(const ::file::path& pathGrubFolder)
   {

      auto pcontext = m_papplication;

      string_array straLines;

      auto pathGrubCfg = get_grub_cfg_path(pathGrubFolder);
      
      straLines = pcontext->file()->lines(pathGrubCfg);

      strsize iFind = 0;

      m_plistbox->reset_content();

      string strLine;

      while (::found(iFind = straLines.find_first_begins_eat(strLine, "menuentry", iFind)))
      {

         if (strLine.has_char() && strLine[0] == ' ')
         {

            auto range = strLine();

            string strEntryName = range.consume_command_line_argument();

            string strValue;

            while (strLine.has_char())
            {

               string strItem = range.consume_command_line_argument();

               strItem.trim();

               if (strItem.begins("-"))
               {

                  range.consume_command_line_argument();

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

               m_plistbox->add_item(strEntryName, strValue);

            }

            auto iBracket = straLines.find_first_begins("}", iFind);

            if (iBracket >= 0)
            {

               auto iMenuEntry = straLines.find_first_begins("menuentry", iBracket);
               
               auto iSubMenu = straLines.find_first_begins("submenu", iBracket);

               if(iMenuEntry >= 0 && (iMenuEntry < iSubMenu || iSubMenu < 0))
               {

                  iFind = iBracket;

               }
               else if (iSubMenu >= 0)
               {

                  iFind = straLines.find_first_begins("}", iSubMenu);

               }

            }

         }

         iFind++;

      }

      auto strSavedEntry = get_grub_saved_entry(pathGrubFolder);

      m_plistbox->set_current_item_by_atom(strSavedEntry, ::e_source_initialize);

      m_plistbox->set_need_layout();

      m_plistbox->set_need_redraw();

      m_plistbox->post_redraw();

      return ::success;

   }


   string form_001::get_grub_saved_entry(const ::file::path& pathGrubFolder)
   {

      string_array straLines;

      auto pcontext = m_papplication;

      auto pathGrubEnv = get_grubenv_path(pathGrubFolder);

      straLines = pcontext->file()->lines(pathGrubEnv);

      string strEntry;

      auto iFind = straLines.find_first_begins_eat(strEntry, "saved_entry=");

      if (::found(iFind))
      {

         return "";

      }

      strEntry.trim();

      return strEntry;

   }

   
   ::e_status form_001::set_grub_saved_entry(const ::file::path& pathGrubFolder, const string& strSavedEntry)
   {

      if (strSavedEntry == get_grub_saved_entry(pathGrubFolder))
      {

         return ::success;

      }

      auto pcontext = m_papplication;

      auto pathGrubEnv = get_grubenv_path(pathGrubFolder);

      auto memory = pcontext->file()->as_memory(pathGrubEnv);

      auto estatus = grub_set_variable(memory, "saved_entry=", strSavedEntry);

      if (!estatus)
      {

         return estatus;

      }

      //estatus =
      
      pcontext->file()->set(pathGrubEnv, memory);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      return estatus;

   }


} // namespace app_simple_change_grub_default_entry


::e_status grub_set_variable(memory & memoryGrubEnv, const ::block& blockVariablePrefix, const block& blockValue)
{

   auto iStart = memoryGrubEnv.find_line_prefix_index(blockVariablePrefix);

   if (iStart < 0)
   {

      return error_not_found;

   }

   auto iFindEol = memoryGrubEnv.find_index(as_block('\n'), iStart);

   if (iFindEol < 0)
   {

      iFindEol = memoryGrubEnv.size();

   }

   auto iFindEnd = memoryGrubEnv.reverse_find_index(as_block('#'), iStart);

   if (iFindEnd <= 0)
   {

      iFindEnd = memoryGrubEnv.size();

   }
   else
   {

      iFindEnd = memoryGrubEnv.reverse_find_index_of_byte_not_in_block("#", iFindEnd);

   }

   auto iOldLen = iFindEol - iStart;

   auto iNewLen = blockValue.size();

   auto iSize = memoryGrubEnv.size();

   auto pdata = (unsigned char*)memoryGrubEnv.data();

   if (iNewLen != iOldLen)
   {

      auto ptarget = pdata + iStart + iNewLen;

      auto psource = pdata + iStart + iOldLen;

      auto c = abs(iNewLen - iOldLen);

      memory_transfer(ptarget, psource, iSize - iStart - iNewLen);

   }

   if (iNewLen < iOldLen)
   {
      
      auto c = iOldLen - iNewLen;

      auto pemptypadding = pdata + memoryGrubEnv.size() - c;

      memory_set(pemptypadding, '#', c);

   }

   if (iNewLen > 0)
   {

      auto ptarget = pdata + iStart;

      auto psource = (const char *) blockValue.data();

      auto c = blockValue.size();

      memory_copy(ptarget, psource, c);

   }

   return ::success;

}



