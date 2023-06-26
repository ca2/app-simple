// From form_amender.cpp by camilo on 2023-03-15 ~17:00 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "form_reset_icon.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/listing.h"
#include "apex/database/_binary_stream.h"
#include "apex/filesystem/filesystem/dir_context.h"
#include "apex/filesystem/filesystem/link.h"
#include "apex/platform/os_context.h"
#include "aura/message/user.h"
#include "aura/user/user/still.h"
#include "aura/user/user/plain_edit.h"
#include "aura/user/user/button.h"


namespace app_simple_shortcut_amender
{


   form_reset_icon::form_reset_icon()
   {

   }


   form_reset_icon::~form_reset_icon()
   {

   }


   //void form_reset_icon::assert_ok() const
   //{

   //   form::assert_ok();

   //}


   //void form_reset_icon::dump(dump_context & dumpcontext) const
   //{

   //   form::dump(dumpcontext);

   //}


#ifdef _DEBUG


   int64_t form_reset_icon::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t form_reset_icon::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void form_reset_icon::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(MESSAGE_CREATE, psender, this, &form_reset_icon::on_message_create);

      add_command_handler("send_button", { this,  &form_reset_icon::_001OnSendButton });
      add_command_handler("clear_button", { this,  &form_reset_icon::_001OnClearButton });

   }


   void form_reset_icon::on_message_create(::message::message * pmessage)
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

      __construct_new(m_pbuttonClear);

      __construct_new(m_pbuttonSend);

      __construct_new(m_pstillReceiver);

      m_pstillFolder->create_control(this, "still_folder");

      m_peditFolder->create_control(this, "edit_folder");

      m_peditFolder->add_handler(this);

      m_pstillSource->create_control(this, "still_source");

      m_peditSource->create_control(this, "edit_source");

      m_peditSource->add_handler(this);

      m_pbuttonClear->create_control(this, "clear_button");

      m_pbuttonClear->add_handler(this);

      m_pbuttonSend->create_control(this, "send_button");

      m_pbuttonSend->add_handler(this);

      m_pstillFolder->set_window_text("Folder:");

      m_pstillSource->set_window_text("Source:");

      m_pstillReceiver->create_control(this, "still");

      m_pstillReceiver->set_window_text("(Waiting to receive...)");

      m_peditFolder->m_strEmtpyText = "Enter folder where to reset links icon";

      m_peditSource->m_strEmtpyText = "Enter text to search for";

      auto papp = get_app();

      {

         ::string strLastFolder;

         papp->datastream()->get("last_folder", strLastFolder);

         m_peditFolder->_001SetText(strLastFolder, ::e_source_initialize);

      }

      {

         ::string strLastSource;

         papp->datastream()->get("last_source", strLastSource);

         m_peditSource->_001SetText(strLastSource, ::e_source_initialize);

      }

      m_pbuttonClear->set_window_text("Clear");

      m_pbuttonSend->set_window_text("Thumbnail");

   }


   void form_reset_icon::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_impact::on_layout(pgraphics);

      double iLeft = 100.;

      double y = 10.;

      auto rectangleClient = client_rectangle();

      {

         auto sizeStill = m_pstillFolder->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleStillMargin = m_pstillFolder->get_margin(m_pstillFolder->get_style(pgraphics));

         y += rectangleStillMargin.top;

         m_pstillFolder->display_child(::rectangle_f64_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

         y += sizeStill.cy();

         y += rectangleStillMargin.bottom;

      }

      {

         auto sizeEdit = m_peditFolder->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleEditMargin = m_peditFolder->get_margin(m_peditFolder->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top;

         m_peditFolder->display_child(::rectangle_f64_dimension(iLeft, y, 600, sizeEdit.cy()));

         y += sizeEdit.cy();

         y += rectangleEditMargin.bottom;

      }


      {

         auto sizeStill = m_pstillSource->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleStillMargin = m_pstillSource->get_margin(m_pstillSource->get_style(pgraphics));

         y += rectangleStillMargin.top;

         m_pstillSource->display_child(::rectangle_f64_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

         y += sizeStill.cy();

         y += rectangleStillMargin.bottom;

      }

      ::size_i32 sizeEdit;

      {

         sizeEdit = m_peditSource->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleEditMargin = m_peditSource->get_margin(m_peditSource->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top;

         m_peditSource->display_child(::rectangle_f64_dimension(iLeft, y, 600, sizeEdit.cy()));

         y += sizeEdit.cy();

         y += rectangleEditMargin.bottom;

      }

      auto sizeButtonClear = m_pbuttonClear->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonSend = m_pbuttonSend->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_peditSource->get_style(pgraphics));

      auto sizeButtonMarginSend = m_pbuttonSend->get_margin(m_peditSource->get_style(pgraphics));

      y += maximum(sizeButtonMarginClear.top, sizeButtonMarginSend.top);

      auto button_width = maximum(sizeButtonClear.cx() + 32, sizeButtonSend.cx() + 32);

      auto button_height = maximum(sizeButtonClear.cy(), sizeButtonSend.cy());

      m_pbuttonClear->display_child(::rectangle_f64_dimension(iLeft, y, button_width, button_height));

      m_pbuttonSend->display_child(::rectangle_f64_dimension(iLeft + button_width + 32, y, button_width, button_height));

      y += button_height + 20;

      m_pstillReceiver->m_ealignText = e_align_top_left;

      m_pstillReceiver->display_child(::rectangle_f64_dimension(iLeft, y, 4000, sizeEdit.cy() * 100));

   }


   void form_reset_icon::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->m_atom == ::id_after_change_text)
      {

         if (ptopic->m_actioncontext.is_user_source())
         {

            if (ptopic->m_puserelement->m_atom == "edit_folder")
            {

               string strText;

               m_peditFolder->_001GetText(strText);

               auto papp = get_app();

               if (strText == "This is a test. This is a test")
               {

                  infomration("");

               }

               papp->datastream()->set("last_folder", strText);

               m_pbuttonSend->set_window_text("Thumbnail");

            }
            else if (ptopic->m_puserelement->m_atom == "edit_source")
            {

               string strText;

               m_peditSource->_001GetText(strText);

               auto papp = get_app();

               if (strText == "This is a test. This is a test")
               {

                  infomration("");

               }

               papp->datastream()->set("last_source", strText);

               m_pbuttonSend->set_window_text("Thumbnail");

            }
            //else if (ptopic->m_puserelement->m_atom == "edit_target")
            //{

            //   string strText;

            //   m_peditTarget->_001GetText(strText);

            //   auto papp = get_app();

            //   if (strText == "This is a test. This is a test")
            //   {

            //      infomration("");

            //   }

            //   papp->datastream()->set("last_target", strText);

            //   m_pbuttonSend->set_window_text("Thumbnail");

            //}

         }

      }
      //      else if (ptopic->m_atom == ::id_click)
      //      {
      //
      //         if (ptopic->m_puserelement->m_atom == "clear_button")
      //         {
      //
      //            m_pedit->_001SetText("", ::e_source_user);
      //
      //         }
      //         else if (ptopic->m_puserelement->m_atom == "send_button")
      //         {
      //
      //            string strText;
      //
      //            m_pedit->_001GetText(strText);
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


   void form_reset_icon::_001OnClearButton(::message::message * pmessage)
   {

      m_peditSource->_001SetText("", ::e_source_user);

      //m_peditTarget->_001SetText("", ::e_source_user);

      pmessage->m_bRet = true;

   }


   void form_reset_icon::_001OnSendButton(::message::message * pmessage)
   {

      string strSend;

      strSend = m_pbuttonSend->get_window_text();

      bool bThumbnail = strSend == "Thumbnail";

      string strFolder;

      m_peditFolder->_001GetText(strFolder);

      string strSource;

      m_peditSource->_001GetText(strSource);

      //string strTarget;

      //m_peditTarget->_001GetText(strTarget);

      string strMessage;

      strMessage.format("Gonna search for '%s', in '%s' and reset icon\n\n",
         strSource.c_str(), strFolder.c_str());

      string_array straAction = reset_icon(strFolder, strSource, bThumbnail);

      strMessage += straAction.implode("\n");

      m_pstillReceiver->set_window_text(strMessage);

      m_pstillReceiver->post_redraw();

      if (bThumbnail)
      {

         m_pbuttonSend->set_window_text("Reset Icon");

      }

      pmessage->m_bRet = true;

   }


   string_array form_reset_icon::reset_icon(const ::file::path & pathFolder, const ::scoped_string & scopedstrSource, bool bThumbnail)
   {

      file::listing listing;

      listing.set_pattern_file_listing(pathFolder, { "*.lnk" });

      dir()->enumerate(listing);

      string_array straAction;

      if (listing.is_empty())
      {

         straAction.add("No link files in Folder '" + pathFolder + "'");

         return straAction;

      }

      ::string strSource;

      strSource = scopedstrSource;

      strSource.find_replace("\\", "/");

      for (auto & path : listing)
      {

         auto plink = m_pcontext->m_papexcontext->os_context()->resolve_link(path);

         ::file::path pathTarget = plink->m_pathTarget;

         ::file::path pathFolder = plink->m_pathFolder;

         ::file::path pathIcon = plink->m_pathIcon;

         if (pathTarget.contains(strSource) 
            && pathIcon.has_char()
            && plink->m_elink & ::file::e_link_icon)
         {

            ::file::e_link elinkChanged = ::file::e_link_icon;

            ::file::e_link elinkWritten = ::file::e_link_none;

            if (!bThumbnail)
            {

               try
               {

                  plink->m_elink = ::file::e_link_icon;

                  plink->m_pathIcon.clear();

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

            if (elinkChanged & ::file::e_link_icon)
            {

               straAction.add(path);

            }

         }

      }

      return straAction;


   }

} // namespace simple_shortcut



