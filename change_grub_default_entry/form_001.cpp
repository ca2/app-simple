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
#include <cerrno>
#include <sys/vfs.h>
#include <unistd.h>
#endif





namespace app_simple_change_grub_default_entry
{
   constexpr auto timer_grub_permission_retry = static_cast<enum_timer>(0x47525542);



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
                  // GTK must finish creating the native window before the show request.
                  pbox->create_window(e_parallelization_synchronous);
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

      if (pathFolder.is_empty())
      {
         stop_permission_retry();
         m_pstill->set_window_text("Boot or GRUB Folder: grub.cfg not found");
         set_need_layout();
         return error_not_found;
      }

      string config;
      try
      {
#if defined(LINUX)
         // exists() treats an unsearchable parent directory as a missing file.
         // Preserve EACCES so the permission dialog and retry can run.
         if (::access(pathConfig.c_str(), R_OK) != 0 && errno == EACCES)
            throw ::exception(error_file_access_denied);
#endif
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
               ::string permissionCommand = "sudo chmod a+r -- '" + quoted + "'";
#if defined(LINUX)
               // FAT permissions come from mount options; chmod and ACLs cannot
               // grant access. Walk to an accessible ancestor to query the mount.
               auto pathProbe = pathFolder;
               struct statfs filesystem;
               while (::statfs(pathProbe.c_str(), &filesystem) != 0)
               {
                  if (errno != EACCES || pathProbe == pathProbe.folder()) break;
                  pathProbe = pathProbe.folder();
               }
               if (::statfs(pathProbe.c_str(), &filesystem) == 0 && filesystem.f_type == 0x4d44)
               {
                  // FAT may retain its original masks on remount. Unmount and
                  // mount the same device afresh, without formatting it.
                  const std::string script =
                     "target=$(findmnt -n -o TARGET -T \"$1\") && "
                     "source=$(findmnt -n -o SOURCE -T \"$1\") && "
                     "umount -- \"$target\" && "
                     "mount -t vfat -o uid=0,gid=0,fmask=0133,dmask=0022 -- \"$source\" \"$target\"";
                  permissionCommand = (std::string("sudo sh -c ") + grub_menu::shell_quote(script)
                     + " sh " + grub_menu::shell_quote(pathProbe.c_str())).c_str();
               }
#endif
               // Finish the main window's create/text-change handler before
               // initializing another native window, entirely on the GUI thread.
               ::pointer<form_001> hold = this;
               main_post([this, hold, permissionCommand]()
               {
                  if (!hold->m_bPermissionRetry) return;
                  auto pbox = hold->create_newø < ::micro::command_message_box >();
                  hold->m_pPermissionBox = pbox;
                  pbox->m_pacmeuserinteractionOwner = hold->top_level();
                  ::pointer<::windowing::window> pwindow = hold->window();
                  pbox->initialize_command_message_box(
                     "Cannot read the GRUB configuration. Copy the command into a terminal and run it. "
                     "The entries will load automatically as soon as access is granted.",
                     permissionCommand,
                     [pwindow](const ::string & command) { pwindow->copydesk()->set_plain_text(command); });
                  // GTK must finish creating the native window before the show request.
                  pbox->create_window(e_parallelization_synchronous);
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

      try { straLines = pcontext->file()->lines(pathGrubEnv); }
      catch (const ::exception &) { return ""; }

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
      auto config = file()->as_string(get_grub_cfg_path(pathGrubFolder));
      if (!grub_menu::uses_saved_default(config.c_str()))
      {
         update_grub_entry_list(pathGrubFolder);
         ::pointer<form_001> hold = this;
         main_post([this, hold]()
         {
            auto pbox = create_newø < ::micro::message_box >();
            pbox->m_pacmeuserinteractionOwner = top_level();
            pbox->initialize_message_box(
               "This GRUB configuration does not use saved_entry as its default. "
               "Boot into the Linux installation that owns this boot menu, set GRUB_DEFAULT=saved "
               "in /etc/default/grub, and regenerate its grub.cfg. Then load the entries again. "
               "Changing grubenv from another Linux works when you select the boot folder used by the active GRUB.",
               "Enable saved GRUB defaults");
            pbox->create_window(e_parallelization_synchronous);
            pbox->display(e_display_normal, {});
         });
         return error_failed;
      }

      ::string requested(scopedstrSavedEntry);
      if (requested == get_grub_saved_entry(pathGrubFolder)) return ::success;

      if (m_strPendingSavedEntry.has_character()) return error_failed;
      m_strPendingSavedEntry = requested;
      m_pbuttonRestart->enable_window(false);
      m_pbuttonLoad->enable_window(false);
      m_pedit->enable_window(false);
      m_plistbox->enable_window(false);
      m_pstill->set_window_text("Waiting for administrator authorization...");
      set_need_layout();

      auto pathEnvironment = get_grubenv_path(pathGrubFolder);
      ::pointer<form_001> hold = this;
      fork([this, hold, pathEnvironment, pathGrubFolder, requested]()
      {
         ::string error;
         ::i32 exitCode = -1;
         try
         {
#if defined(LINUX)
            // Only this command is elevated. Polkit owns the password prompt;
            // the application never receives or stores the password.
            auto command = std::string("/usr/bin/pkexec /usr/bin/grub-editenv ")
               + grub_menu::shell_quote(pathEnvironment.c_str()) + " set "
               + grub_menu::shell_quote("saved_entry=" + std::string(requested.c_str()));
            node()->get_posix_shell_command_output(command.c_str(), e_posix_shell_system_default,
               &error, &exitCode, 2_minute);
#else
            error = "Graphical privilege elevation is not available on this platform.";
#endif
         }
         catch (const ::exception & exception) { error = exception.get_message(); }
         catch (...) { error = "The administrator authorization request failed."; }

         main_post([this, hold, pathGrubFolder, requested, exitCode, error]()
         {
            m_strPendingSavedEntry.clear();
            m_pbuttonRestart->enable_window(true);
            m_pbuttonLoad->enable_window(true);
            m_pedit->enable_window(true);
            m_plistbox->enable_window(true);
            bool verified = exitCode == 0 && get_grub_saved_entry(pathGrubFolder) == requested;
            update_grub_entry_list(pathGrubFolder);
            if (verified)
            {
               m_pstill->set_window_text("Boot default saved");
               set_need_layout();
               return;
            }
            auto pbox = create_newø < ::micro::message_box >();
            pbox->m_pacmeuserinteractionOwner = top_level();
            ::string message = (exitCode == 126 || exitCode == 127)
               ? "Administrator authorization was cancelled or unavailable. The boot default was not saved."
               : "Could not verify the saved boot default.";
            if (error.has_character()) message += "\n\n" + error;
            pbox->initialize_message_box(message, "Boot default not saved");
            pbox->create_window(e_parallelization_synchronous);
            pbox->display(e_display_normal, {});
         });
      });
      return ::success;
   }


} // namespace app_simple_change_grub_default_entry
