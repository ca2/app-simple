#include "platform.h"
#include "form_001.h"
#include "grub_menu.h"
#include "acme/user/micro/command_message_box.h"
#include "aura/windowing/window.h"
#include "aura/user/user/copydesk.h"
#include "acme/exception/exception.h"
#include "acme/parallelization/synchronous_lock.h"
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
#if defined(LINUX)
#include <unistd.h>
#endif





namespace app_simple_change_grub_default_entry
{
   constexpr auto timer_grub_permission_retry = static_cast<enum_timer>(0x47525542);
   constexpr auto timer_grub_saved_entry_retry = static_cast<enum_timer>(0x47525543);



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


   ::i64 form_001::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   ::i64 form_001::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form_001::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      USER_MESSAGE_LINK(::user::e_message_create, psender, this, &form_001::on_message_create);

   }


   void form_001::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      construct_newø(m_pstill);

      construct_newø(m_pedit);

      construct_newø(m_plistbox);

      construct_newø(m_pbuttonRestart);
      construct_newø(m_pbuttonLoad);

      m_pstill->create_control(this, "still");

      m_pedit->create_control(this, "edit");

      m_pedit->add_handler(this);

      m_plistbox->create_control(this, "list_box");

      m_plistbox->add_handler(this);

      m_pbuttonRestart->create_control(this, "restart_button");

      m_pbuttonRestart->add_handler(this);
      m_pbuttonLoad->create_control(this, "load_entries");
      m_pbuttonLoad->add_handler(this);
      m_pbuttonLoad->set_window_text("Load Entries");

      m_pstill->set_window_text("Boot or GRUB Folder:");

      m_pedit->m_strEmtpyText = "Enter /boot or the GRUB folder";

      string strFolderPath;

      ::cast < ::database::client > pdatabaseclient = application();

      pdatabaseclient->datastream()->get("grub_folder_path", strFolderPath);

      m_pedit->set_text(strFolderPath, ::e_source_initialize);

      update_grub_entry_list(strFolderPath);

      m_pbuttonRestart->set_window_text("Restart Now");

   }


   void form_001::on_layout(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      ::user::form_impact::on_layout(pdraw2dgraphics);

      ::f64 iLeft = 10.;

      ::f64 y = 10.;

      auto rectangleX = this->rectangle();

      auto sizeStill = m_pstill->get_adjusted_fitting_size(pdraw2dgraphics);

      auto rectangleStillMargin = m_pstill->get_margin(m_pstill->get_style(pdraw2dgraphics));

      y += rectangleStillMargin.top;

      m_pstill->display_child(::f64_rectangle_dimension(iLeft, y, sizeStill.cx, sizeStill.cy));

      y += sizeStill.cy;

      y += rectangleStillMargin.bottom;

      auto sizeEdit = m_pedit->get_adjusted_fitting_size(pdraw2dgraphics);

      auto rectangleEditMargin = m_pedit->get_margin(m_pedit->get_style(pdraw2dgraphics), ::e_element_none);

      y += rectangleEditMargin.top;

      auto sizeLoad = m_pbuttonLoad->get_adjusted_fitting_size(pdraw2dgraphics);
      auto loadWidth = sizeLoad.cx + 32;
      auto editWidth = maximum(100.0, minimum(600.0, rectangleX.width() - iLeft * 3 - loadWidth));
      m_pedit->display_child(::f64_rectangle_dimension(iLeft, y, editWidth, sizeEdit.cy));
      m_pbuttonLoad->display_child(::f64_rectangle_dimension(iLeft * 2 + editWidth, y, loadWidth,
         maximum(sizeEdit.cy, sizeLoad.cy)));


      //auto sizeButtonClear = m_pbuttonClear->_001CalculateAdjustedFittingSize(pdraw2dgraphics);

      auto sizeButtonRestart = m_pbuttonRestart->get_adjusted_fitting_size(pdraw2dgraphics);

      //auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_pedit->get_style(pdraw2dgraphics));

      auto sizeButtonMarginRestart = m_pbuttonRestart->get_margin(m_pedit->get_style(pdraw2dgraphics));

      //y += maximum(sizeButtonMarginClear.top, sizeButtonMarginSend.top);

      auto button_width = sizeButtonRestart.cx + 32;

      auto button_height = sizeButtonRestart.cy;

      //m_pbuttonClear->display_child(::f64_rectangle_dimension(iLeft, y, button_width, button_height));

      y += sizeButtonMarginRestart.top;

      m_pbuttonRestart->display_child(::f64_rectangle_dimension(rectangleX.right - iLeft - button_width, y, button_width, button_height));

      y += sizeButtonMarginRestart.bottom;

      y += button_height;

      y += sizeEdit.cy;

      y += rectangleEditMargin.bottom;

      m_plistbox->display_child(::f64_rectangle_dimension(iLeft, y, rectangleX.width() - iLeft * 2, rectangleX.bottom - iLeft - y));

      m_plistbox->set_need_layout();
   }


   void form_001::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == ::id_after_change_cur_sel)
      {

         if (ptopic->m_puserelement->user_interaction()->id() == "list_box"
            && ptopic->m_actioncontext.is_user_source())
         {

            auto atomSavedEntry = m_plistbox->get_current_item_id();

            if (atomSavedEntry.has_character())
            {

               auto pcontext = m_papplication;

               auto pathGrubFolder = get_grub_folder_path();

               set_grub_saved_entry(pathGrubFolder, atomSavedEntry.as_string());

            }

         }

      }
      else if (ptopic->id() == ::id_after_change_text)
      {

         if (ptopic->m_puserelement->user_interaction()->id() == "edit")
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
      else if (ptopic->id() == ::id_click)
      {

         if (ptopic->m_puserelement->user_interaction()->id() == "load_entries")
         {
            m_pathPermissionMessage.clear();
            update_grub_entry_list(get_grub_folder_path());
            ptopic->m_bRet = true;
         }
         else if (ptopic->m_puserelement->user_interaction()->id() == "clear_button")
         {

            m_pedit->set_text("", ::e_source_user);

         }
         else if (ptopic->m_puserelement->user_interaction()->id() == "restart_button")
         {

            if (m_strPendingSavedEntry.has_character() || m_bRebootPending.exchange(true)) return;
            m_pbuttonRestart->enable_window(false);
            m_pbuttonRestart->set_window_text("Restart requested...");
            ::pointer<form_001> hold = this;
            fork([this, hold]()
            {
               ::string error;
               try
               {
                  node()->reboot();
               }
               catch (const ::exception & exception)
               {
                  error = exception.get_message();
                  if (exception.m_strDetails.has_character()) error += "\n\n" + exception.m_strDetails;
               }
               catch (...)
               {
                  error = "The restart request failed.";
               }
               if (error.is_empty()) return;
               main_post([this, hold, error]()
               {
                  m_bRebootPending = false;
                  m_pbuttonRestart->enable_window(true);
                  m_pbuttonRestart->set_window_text("Restart Now");
                  auto pbox = create_newø < ::micro::message_box >();
                  pbox->m_pacmeuserinteractionOwner = top_level();
                  pbox->initialize_message_box(error, "Restart failed or cancelled");
                  pbox->display(e_display_normal, {});
               });
            });

            ptopic->m_bRet = true;

         }

      }

   }


   ::file::path form_001::get_grub_folder_path()
   {

      string strGrubFolderPath;

      m_pedit->get_text(strGrubFolderPath);

      strGrubFolderPath.trim();

      ::file::path pathFolder = strGrubFolderPath;
      if (file()->exists(pathFolder / "grub.cfg")) return pathFolder;
      if (file()->exists(pathFolder / "grub" / "grub.cfg")) return pathFolder / "grub";
      if (file()->exists(pathFolder / "grub2" / "grub.cfg")) return pathFolder / "grub2";
      return pathFolder;

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

      auto pathFolder = get_grub_folder_path();
      auto pathConfig = get_grub_cfg_path(pathFolder);
      m_pstill->set_window_text("Boot or GRUB Folder:");

      if (pathFolder.is_empty() || !file()->exists(pathConfig))
      {
         stop_permission_retry();
         m_pstill->set_window_text("Boot or GRUB Folder: grub.cfg not found");
         set_need_layout();
         return error_not_found;
      }

      string config;
      try
      {
         config = file()->as_string(pathConfig);
      }
      catch (const ::exception & exception)
      {
         m_pstill->set_window_text("Boot or GRUB Folder: cannot read grub.cfg");
         set_need_layout();
         if (exception.estatus() == error_file_access_denied)
         {
            m_pstill->set_window_text("Permission needed: retrying every 500 ms");
            if (!m_bPermissionRetry)
            {
               m_bPermissionRetry = true;
               set_timer(timer_grub_permission_retry, 500_ms, [this](::timer *)
               {
                  if (!m_bPermissionRetry || m_bPermissionRetryPosted) return;
                  m_bPermissionRetryPosted = true;
                  ::pointer<form_001> hold = this;
                  main_post([this, hold]()
                  {
                     m_bPermissionRetryPosted = false;
                     if (m_bPermissionRetry) update_grub_entry_list(get_grub_folder_path());
                  });
               });
            }
            if (m_pathPermissionMessage != pathConfig)
            {
               m_pathPermissionMessage = pathConfig;
               string quoted = pathConfig;
               quoted.replace_with("'\"'\"'", "'");
               // Finish the main window's create/text-change handler before
               // initializing another native window, entirely on the GUI thread.
               ::pointer<form_001> hold = this;
               main_post([this, hold, quoted]()
               {
                  if (!hold->m_bPermissionRetry) return;
                  auto pbox = hold->create_newø < ::micro::command_message_box >();
                  hold->m_pPermissionBox = pbox;
                  pbox->m_pacmeuserinteractionOwner = hold->top_level();
                  ::pointer<::windowing::window> pwindow = hold->window();
                  pbox->initialize_command_message_box(
                     "Cannot read the GRUB configuration. Copy the command into a terminal and run it. "
                     "The entries will load automatically as soon as access is granted.",
                     "sudo chmod a+r -- '" + quoted + "'",
                     [pwindow](const ::string & command) { pwindow->copydesk()->set_plain_text(command); });
                  pbox->display(e_display_normal, {});
               });
            }
         }
         else
         {
            stop_permission_retry();
         }
         return exception.estatus();
      }
      stop_permission_retry();
      m_pathPermissionMessage.clear();
      string environment;
      try { environment = file()->as_string(get_grubenv_path(pathFolder)); }
      catch (const ::exception &) { }

      auto entries = grub_menu::parse(config.c_str());
      auto selected = grub_menu::default_entry(config.c_str(), environment.c_str());
      // Publish the new list atomically with respect to the graphics thread.
      _synchronous_lock listLock(m_plistbox->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);
      m_plistbox->reset_content();
      string selectedId;
      for (const auto & entry : entries)
      {
         m_plistbox->add_item(entry.display_title().c_str(), entry.id.c_str());
         if (selected == entry.id || selected == entry.title_path || selected == entry.index)
            selectedId = entry.id.c_str();
      }
      m_plistbox->set_current_item_by_atom(selectedId, ::e_source_initialize);
      information() << "GRUB loaded " << entries.size() << " entries from " << pathConfig
         << "; selected default: " << selectedId;
      if (entries.empty()) m_pstill->set_window_text("Boot or GRUB Folder: no menu entries found");
      set_need_layout();
      m_plistbox->set_need_layout();
      m_plistbox->set_need_redraw();
      m_plistbox->post_redraw();
      return ::success;

   }


   void form_001::stop_permission_retry()
   {
      m_bPermissionRetry = false;
      kill_timer(timer_grub_permission_retry);
      m_pathPermissionMessage.clear();
      if (m_pPermissionBox)
      {
         auto pbox = m_pPermissionBox;
         m_pPermissionBox.release();
         main_post([pbox]()
         {
            // Micro dialogs do not maintain interaction::m_bWindowCreated.
            // Complete the response even when that unrelated flag is false.
            pbox->set_dialog_response(e_dialog_result_cancel);
         });
      }
   }


   string form_001::get_grub_saved_entry(const ::file::path& pathGrubFolder)
   {

      string_array_base straLines;

      auto pcontext = m_papplication;

      auto pathGrubEnv = get_grubenv_path(pathGrubFolder);

      straLines = pcontext->file()->lines(pathGrubEnv);

      string strEntry;

      auto iFind = straLines.find_first_begins_eat(strEntry, "saved_entry=");

      if (!::found(iFind))
      {

         return "";

      }

      strEntry.trim();

      return strEntry;

   }

   
   ::e_status form_001::set_grub_saved_entry(const ::file::path& pathGrubFolder, const ::scoped_string & scopedstrSavedEntry)
   {
      ::string requested(scopedstrSavedEntry);
      if (requested == get_grub_saved_entry(pathGrubFolder)) return ::success;

      m_strPendingSavedEntry = requested;
      m_pbuttonRestart->enable_window(false);
      m_pstill->set_window_text("Default not saved yet: run the command in the dialog");
      set_need_layout();

      auto pathEnvironment = get_grubenv_path(pathGrubFolder);
      // Save immediately if the account still has access from a previous grant.
      check_pending_saved_entry();
      if (m_strPendingSavedEntry.is_empty()) return ::success;

#if defined(LINUX)
      auto command = std::string("sudo setfacl -m u:") + std::to_string(::getuid())
         + ":rw -- " + grub_menu::shell_quote(pathEnvironment.c_str());
#else
      auto command = std::string("sudo grub-editenv ") + grub_menu::shell_quote(pathEnvironment.c_str())
         + " set " + grub_menu::shell_quote("saved_entry=" + std::string(requested.c_str()));
#endif

      ::pointer<form_001> hold = this;
      main_post([this, hold, command]()
      {
         if (m_strPendingSavedEntry.is_empty()) return;
         if (m_pSaveBox)
         {
            m_pSaveBox->message_box_response_callback() = {};
            m_pSaveBox->set_dialog_response(e_dialog_result_cancel);
         }
         auto pbox = create_newø < ::micro::command_message_box >();
         m_pSaveBox = pbox;
         pbox->m_pacmeuserinteractionOwner = top_level();
         ::pointer<::windowing::window> pwindow = window();
         pbox->initialize_command_message_box(
            "The app needs write access to grubenv. Copy and run this command to grant your account access. "
            "The selection will then be saved automatically. A system update may remove this grant; "
            "the app will ask again when needed.",
            command.c_str(),
            [pwindow](const ::string & text) { pwindow->copydesk()->set_plain_text(text); },
            "Allow saving the GRUB default");
         pbox->message_box_response_callback() = [this](::user_interface::message_box *)
         {
            m_pSaveBox.release();
            m_strPendingSavedEntry.clear();
            kill_timer(timer_grub_saved_entry_retry);
            m_pbuttonRestart->enable_window(true);
            update_grub_entry_list(get_grub_folder_path());
         };
         pbox->display(e_display_normal, {});
      });
      set_timer(timer_grub_saved_entry_retry, 500_ms, [this](::timer *)
      {
         ::pointer<form_001> hold = this;
         main_post([this, hold]() { check_pending_saved_entry(); });
      });
      return ::success;
   }


   void form_001::check_pending_saved_entry()
   {
      if (m_strPendingSavedEntry.is_empty()) return;
      try
      {
         auto pathFolder = get_grub_folder_path();
         if (get_grub_saved_entry(pathFolder) != m_strPendingSavedEntry)
         {
#if defined(LINUX)
            auto pathEnvironment = get_grubenv_path(pathFolder);
            if (::access(pathEnvironment.c_str(), W_OK) != 0) return;
            auto command = std::string("grub-editenv ") + grub_menu::shell_quote(pathEnvironment.c_str())
               + " set " + grub_menu::shell_quote("saved_entry=" + std::string(m_strPendingSavedEntry.c_str()));
            ::string error;
            ::i32 exitCode = -1;
            node()->get_posix_shell_command_output(command.c_str(), e_posix_shell_system_default,
               &error, &exitCode, 10_s);
            if (exitCode != 0)
            {
               m_pstill->set_window_text("Could not save the boot default: " + error);
               set_need_layout();
               return;
            }
            if (get_grub_saved_entry(pathFolder) != m_strPendingSavedEntry) return;
#else
            return;
#endif
         }
      }
      catch (const ::exception &) { return; }

      information() << "GRUB saved default verified: " << m_strPendingSavedEntry;
      m_strPendingSavedEntry.clear();
      kill_timer(timer_grub_saved_entry_retry);
      m_pbuttonRestart->enable_window(true);
      if (m_pSaveBox)
      {
         auto pbox = m_pSaveBox;
         m_pSaveBox.release();
         pbox->set_dialog_response(e_dialog_result_cancel);
      }
      else
      {
         update_grub_entry_list(get_grub_folder_path());
      }
   }


} // namespace app_simple_change_grub_default_entry
