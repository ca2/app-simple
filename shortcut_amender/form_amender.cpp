#include "framework.h"
#include "form_amender.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/handler/topic.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/path_system.h"
#include "acme/filesystem/filesystem/link.h"
#include "acme/filesystem/filesystem/listing.h"
#include "apex/database/_binary_stream.h"
#include "acme/filesystem/filesystem/directory_context.h"
#include "apex/platform/node.h"
#include "aura/message/user.h"
#include "aura/user/user/still.h"
#include "aura/user/user/plain_edit.h"
#include "aura/user/user/button.h"


namespace app_simple_shortcut_amender
{


   form_amender::form_amender()
   {

   }


   form_amender::~form_amender()
   {

   }


   //void form_amender::assert_ok() const
   //{

   //   form::assert_ok();

   //}


   //void form_amender::dump(dump_context & dumpcontext) const
   //{

   //   form::dump(dumpcontext);

   //}


#ifdef _DEBUG


   long long form_amender::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long form_amender::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form_amender::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form_amender::on_message_create);

      add_command_handler("send_button", { this,  &form_amender::_001OnSendButton });
      add_command_handler("clear_button", { this,  &form_amender::_001OnClearButton });

   }


   void form_amender::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __construct_new(m_pstillFolder);

      __construct_new(m_peditFolder);

      __construct_new(m_pstillSource);

      __construct_new(m_peditSource);

      __construct_new(m_pstillTarget);

      __construct_new(m_peditTarget);

      __construct_new(m_pbuttonClear);

      __construct_new(m_pbuttonSend);

      __construct_new(m_pstillReceiver);

      m_pstillFolder->create_control(this, "still_folder");

      m_peditFolder->create_control(this, "edit_folder");

      m_peditFolder->add_handler(this);

      m_pstillSource->create_control(this, "still_source");

      m_peditSource->create_control(this, "edit_source");

      m_peditSource->add_handler(this);

      m_pstillTarget->create_control(this, "still_target");

      m_peditTarget->create_control(this, "edit_target");

      m_peditTarget->add_handler(this);

      m_pbuttonClear->create_control(this, "clear_button");

      m_pbuttonClear->add_handler(this);

      m_pbuttonSend->create_control(this, "send_button");

      m_pbuttonSend->add_handler(this);

      m_pstillFolder->set_window_text("Folder:");

      m_pstillSource->set_window_text("Source:");

      m_pstillTarget->set_window_text("Target:");

      m_pstillReceiver->create_control(this, "still");

      m_pstillReceiver->set_window_text("(Waiting to receive...)");

      m_peditFolder->m_strEmtpyText = "Enter folder where to fix links";

      m_peditSource->m_strEmtpyText = "Enter text to search for";

      m_peditTarget->m_strEmtpyText = "Enter text do substitution";

      

      ::cast < ::database::client > pdatabaseclient = application();

      {

         ::string strLastFolder;

         pdatabaseclient->datastream()->get("last_folder", strLastFolder);

         m_peditFolder->set_text(strLastFolder, ::e_source_initialize);

      }

      {

         ::string strLastSource;

         pdatabaseclient->datastream()->get("last_source", strLastSource);

         m_peditSource->set_text(strLastSource, ::e_source_initialize);

      }

      {

         ::string strLastTarget;

         pdatabaseclient->datastream()->get("last_target", strLastTarget);

         m_peditTarget->set_text(strLastTarget, ::e_source_initialize);

      }

      m_pbuttonClear->set_window_text("Clear");

      m_pbuttonSend->set_window_text("Thumbnail");

   }


   void form_amender::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_impact::on_layout(pgraphics);

      double iLeft = 100.;

      double y = 10.;

      auto rectangleX = this->rectangle();

      {

         auto sizeStill = m_pstillFolder->get_adjusted_fitting_size(pgraphics);

         auto rectangleStillMargin = m_pstillFolder->get_margin(m_pstillFolder->get_style(pgraphics));

         y += rectangleStillMargin.top();

         m_pstillFolder->display_child(::double_rectangle_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

         y += sizeStill.cy();

         y += rectangleStillMargin.bottom();

      }

      {

         auto sizeEdit = m_peditFolder->get_adjusted_fitting_size(pgraphics);

         auto rectangleEditMargin = m_peditFolder->get_margin(m_peditFolder->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top();

         m_peditFolder->display_child(::double_rectangle_dimension(iLeft, y, 600, sizeEdit.cy()));

         y += sizeEdit.cy();

         y += rectangleEditMargin.bottom();

      }


      {

         auto sizeStill = m_pstillSource->get_adjusted_fitting_size(pgraphics);

         auto rectangleStillMargin = m_pstillSource->get_margin(m_pstillSource->get_style(pgraphics));

         y += rectangleStillMargin.top();

         m_pstillSource->display_child(::double_rectangle_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

         y += sizeStill.cy();

         y += rectangleStillMargin.bottom();

      }

      {

         auto sizeEdit = m_peditSource->get_adjusted_fitting_size(pgraphics);

         auto rectangleEditMargin = m_peditSource->get_margin(m_peditSource->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top();

         m_peditSource->display_child(::double_rectangle_dimension(iLeft, y, 600, sizeEdit.cy()));

         y += sizeEdit.cy();

         y += rectangleEditMargin.bottom();

      }

      {

         auto sizeStill = m_pstillTarget->get_adjusted_fitting_size(pgraphics);

         auto rectangleStillMargin = m_pstillTarget->get_margin(m_pstillTarget->get_style(pgraphics));

         y += rectangleStillMargin.top();

         m_pstillTarget->display_child(::double_rectangle_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

         y += sizeStill.cy();

         y += rectangleStillMargin.bottom();

      }

      ::int_size sizeEdit;

      {

         sizeEdit = m_peditTarget->get_adjusted_fitting_size(pgraphics);

         auto rectangleEditMargin = m_peditTarget->get_margin(m_peditTarget->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top();

         m_peditTarget->display_child(::double_rectangle_dimension(iLeft, y, 600, sizeEdit.cy()));

         y += sizeEdit.cy();

         y += rectangleEditMargin.bottom();

      }


      auto sizeButtonClear = m_pbuttonClear->get_adjusted_fitting_size(pgraphics);

      auto sizeButtonSend = m_pbuttonSend->get_adjusted_fitting_size(pgraphics);

      auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_peditTarget->get_style(pgraphics));

      auto sizeButtonMarginSend = m_pbuttonSend->get_margin(m_peditTarget->get_style(pgraphics));

      y += maximum(sizeButtonMarginClear.top(), sizeButtonMarginSend.top());

      auto button_width = maximum(sizeButtonClear.cx() + 32, sizeButtonSend.cx() + 32);

      auto button_height = maximum(sizeButtonClear.cy(), sizeButtonSend.cy());

      m_pbuttonClear->display_child(::double_rectangle_dimension(iLeft, y, button_width, button_height));

      m_pbuttonSend->display_child(::double_rectangle_dimension(iLeft + button_width + 32, y, button_width, button_height));

      y += button_height + 20;

      m_pstillReceiver->m_ealignText = e_align_top_left;

      m_pstillReceiver->display_child(::double_rectangle_dimension(iLeft, y, 4000, sizeEdit.cy() * 100));

   }


   void form_amender::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == ::id_after_change_text)
      {

         if (ptopic->m_actioncontext.is_user_source())
         {

            if (ptopic->user_interaction_id() == "edit_folder")
            {

               string strText;

               m_peditFolder->get_text(strText);

               ::cast < ::database::client > pdatabaseclient = application();

               if (strText == "This is a test. This is a test")
               {

                  informationf("");

               }

               pdatabaseclient->datastream()->set("last_folder", strText);

               m_pbuttonSend->set_window_text("Thumbnail");

            }
            else if (ptopic->user_interaction_id() == "edit_source")
            {

               string strText;

               m_peditSource->get_text(strText);

               ::cast < ::database::client > pdatabaseclient = application();

               if (strText == "This is a test. This is a test")
               {

                  informationf("");

               }

               pdatabaseclient->datastream()->set("last_source", strText);

               m_pbuttonSend->set_window_text("Thumbnail");

            }
            else if (ptopic->user_interaction_id() == "edit_target")
            {

               string strText;

               m_peditTarget->get_text(strText);

               ::cast < ::database::client > pdatabaseclient = application();

               if (strText == "This is a test. This is a test")
               {

                  informationf("");

               }

               pdatabaseclient->datastream()->set("last_target", strText);

               m_pbuttonSend->set_window_text("Thumbnail");

            }

         }

      }
//      else if (ptopic->id() == ::id_click)
//      {
//
//         if (ptopic->user_interaction_id() == "clear_button")
//         {
//
//            m_pedit->set_text("", ::e_source_user);
//
//         }
//         else if (ptopic->user_interaction_id() == "send_button")
//         {
//
//            string strText;
//
//            m_pedit->get_text(strText);
//
//            //main_async(__routine([this, strText]()
//              // {
//
//                  output_error_message("send_button clicked\nText: " + strText);
//
//               //}));
//
//                  m_pstillReceiver->set_window_text(strText);
//
//                  m_pstillReceiver->post_redraw();
//
//            ptopic->m_bRet = true;
//
//         }
//
//      }

   }


   void form_amender::_001OnClearButton(::message::message * pmessage)
   {

      m_peditSource->set_text("", ::e_source_user);

      m_peditTarget->set_text("", ::e_source_user);

      pmessage->m_bRet = true;

   }


   void form_amender::_001OnSendButton(::message::message * pmessage)
   {

      string strSend;

      strSend = m_pbuttonSend->get_window_text();

      bool bThumbnail = strSend == "Thumbnail";

      string strFolder;

      m_peditFolder->get_text(strFolder);

      string strSource;

      m_peditSource->get_text(strSource);

      string strTarget;

      m_peditTarget->get_text(strTarget);

      string strMessage;

      strMessage.formatf("Gonna search for '%s', in '%s' and replace by '%s'\n\n",
         strSource.c_str(), strFolder.c_str(), strTarget.c_str());

      string_array straAction = do_amender(strTarget, strFolder, strSource, bThumbnail);

      strMessage += straAction.implode("\n");

      m_pstillReceiver->set_window_text(strMessage);

      m_pstillReceiver->post_redraw();

      if (bThumbnail)
      {

         m_pbuttonSend->set_window_text("Replace");

      }

      pmessage->m_bRet = true;



   }


   
   string_array form_amender::do_amender(const ::scoped_string & scopedstrTarget, const ::file::path & pathFolder, const ::scoped_string & scopedstrSource, bool bThumbnail)
   {

      file::listing listing;

      listing.set_pattern_file_listing(pathFolder, { "*.lnk" });

      directory()->enumerate(listing);

      string_array straAction;

      if (listing.is_empty())
      {

         straAction.add("No link files in Folder '" + pathFolder + "'");

         return straAction;

      }

      ::string strSource;

      strSource = scopedstrSource;

      strSource.find_replace("\\", "/");

      ::string strTarget;

      strTarget = scopedstrTarget;

      strTarget.find_replace("\\", "/");

      for (auto & path : listing)
      {

         auto plink = path_system()->resolve_link(path);

         ::file::path pathTarget = plink->m_pathTarget;

         ::file::path pathFolder = plink->m_pathFolder;

         ::file::path pathIcon = plink->m_pathIcon;

         ::string strActionSummary;

         auto elinkChanged = plink->path_find_replace(strSource, strTarget);

         if (!elinkChanged)
         {

            continue;

         }

         ::file::e_link elinkWithError = plink->check_link();

         ::file::e_link elinkWritten = ::file::e_link_none;

         if (!bThumbnail)
         {

            try
            {

               elinkWritten = plink->write(path);

            }
            catch (...)
            {

               elinkWritten = ::file::e_link_none;

            }

         }
         else
         {

            elinkWritten = elinkChanged;

         }

         if (elinkChanged & ::file::e_link_target)
         {

            straAction.add(
               (const char *)(elinkWritten & ::file::e_link_target ? u8"" : u8"\u2717!! ")
               + node()->display_file_path(path) + ": "
               + node()->display_file_path(plink->m_pathTarget) +
               + " <== "
               + node()->display_file_path(pathTarget));

            if (elinkWithError & ::file::e_link_target)
            {

               straAction.add(
                  node()->display_file_path(plink->m_pathTarget) + ::string("\u2717!!"));

            }

         }

         if (elinkChanged & ::file::e_link_folder)
         {

            straAction.add(
               (const char *)(elinkWritten & ::file::e_link_folder ? u8"" : u8"\u2717!! ")
               + node()->display_file_path(path) + ": "
               + node()->display_file_path(plink->m_pathFolder)
               + " <== "
               + node()->display_file_path(pathFolder));

            if (elinkWithError & ::file::e_link_folder)
            {

               straAction.add(
                  node()->display_file_path(plink->m_pathFolder) + ::string("\u2717!!"));

            }

         }

         if (elinkChanged & ::file::e_link_icon)
         {

            straAction.add(
               (const char *) (elinkWritten & ::file::e_link_icon ? u8"" : u8"\u2717!! ")
               + node()->display_file_path(path) + ": "
               + node()->display_file_path(plink->m_pathIcon)
               + " <== "
               + node()->display_file_path(pathIcon));

            if (elinkWithError & ::file::e_link_icon)
            {

               straAction.add(
                  node()->display_file_path(plink->m_pathIcon) + ::string("\u2717!!"));

            }

         }

      }

      return straAction;


   }


} // namespace simple_shortcut



