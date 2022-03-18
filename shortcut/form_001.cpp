#include "framework.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include <math.h>


namespace app_simple_shortcut
{


   form_001::form_001()
   {

   }


   form_001::~form_001()
   {

   }


   void form_001::assert_ok() const
   {

      form::assert_ok();

   }


   void form_001::dump(dump_context & dumpcontext) const
   {

      form::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t form_001::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t form_001::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void form_001::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form_001::on_message_create);

      add_command_handler("send_button", this, &form_001::_001OnSendButton);
      add_command_handler("clear_button", this, &form_001::_001OnClearButton);

   }


   void form_001::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __compose_new(m_pstillFolder);

      __compose_new(m_peditFolder);

      __compose_new(m_pstillSource);

      __compose_new(m_peditSource);

      __compose_new(m_pstillTarget);

      __compose_new(m_peditTarget);

      __compose_new(m_pbuttonClear);

      __compose_new(m_pbuttonSend);

      __compose_new(m_pstillReceiver);

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

      

      auto papp = get_app();

      auto strLastFolder = papp->data_get("last_folder");

      m_peditFolder->_001SetText(strLastFolder, ::e_source_initialize);

      auto strLastSource = papp->data_get("last_source");

      m_peditSource->_001SetText(strLastSource, ::e_source_initialize);

      auto strLastTarget = papp->data_get("last_target");

      m_peditTarget->_001SetText(strLastTarget, ::e_source_initialize);

      m_pbuttonClear->set_window_text("Clear");

      m_pbuttonSend->set_window_text("Preview");

   }


   void form_001::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_view::on_layout(pgraphics);

      double iLeft = 100.;

      double y = 10.;

      auto rectangleClient = get_client_rect();

      {

         auto sizeStill = m_pstillFolder->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleStillMargin = m_pstillFolder->get_margin(m_pstillFolder->get_style(pgraphics));

         y += rectangleStillMargin.top;

         m_pstillFolder->display_child(::rectangle_f64_dimension(iLeft, y, sizeStill.cx, sizeStill.cy));

         y += sizeStill.cy;

         y += rectangleStillMargin.bottom;

      }

      {

         auto sizeEdit = m_peditFolder->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleEditMargin = m_peditFolder->get_margin(m_peditFolder->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top;

         m_peditFolder->display_child(::rectangle_f64_dimension(iLeft, y, 600, sizeEdit.cy));

         y += sizeEdit.cy;

         y += rectangleEditMargin.bottom;

      }


      {

         auto sizeStill = m_pstillSource->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleStillMargin = m_pstillSource->get_margin(m_pstillSource->get_style(pgraphics));

         y += rectangleStillMargin.top;

         m_pstillSource->display_child(::rectangle_f64_dimension(iLeft, y, sizeStill.cx, sizeStill.cy));

         y += sizeStill.cy;

         y += rectangleStillMargin.bottom;

      }

      {

         auto sizeEdit = m_peditSource->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleEditMargin = m_peditSource->get_margin(m_peditSource->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top;

         m_peditSource->display_child(::rectangle_f64_dimension(iLeft, y, 600, sizeEdit.cy));

         y += sizeEdit.cy;

         y += rectangleEditMargin.bottom;

      }

      {

         auto sizeStill = m_pstillTarget->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleStillMargin = m_pstillTarget->get_margin(m_pstillTarget->get_style(pgraphics));

         y += rectangleStillMargin.top;

         m_pstillTarget->display_child(::rectangle_f64_dimension(iLeft, y, sizeStill.cx, sizeStill.cy));

         y += sizeStill.cy;

         y += rectangleStillMargin.bottom;

      }

      ::size_i32 sizeEdit;

      {

         sizeEdit = m_peditTarget->_001CalculateAdjustedFittingSize(pgraphics);

         auto rectangleEditMargin = m_peditTarget->get_margin(m_peditTarget->get_style(pgraphics), ::e_element_none);

         y += rectangleEditMargin.top;

         m_peditTarget->display_child(::rectangle_f64_dimension(iLeft, y, 600, sizeEdit.cy));

         y += sizeEdit.cy;

         y += rectangleEditMargin.bottom;

      }


      auto sizeButtonClear = m_pbuttonClear->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonSend = m_pbuttonSend->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_peditTarget->get_style(pgraphics));

      auto sizeButtonMarginSend = m_pbuttonSend->get_margin(m_peditTarget->get_style(pgraphics));

      y += maximum(sizeButtonMarginClear.top, sizeButtonMarginSend.top);

      auto button_width = maximum(sizeButtonClear.cx + 32, sizeButtonSend.cx + 32);

      auto button_height = maximum(sizeButtonClear.cy, sizeButtonSend.cy);

      m_pbuttonClear->display_child(::rectangle_f64_dimension(iLeft, y, button_width, button_height));

      m_pbuttonSend->display_child(::rectangle_f64_dimension(iLeft + button_width + 32, y, button_width, button_height));

      y += button_height + 20;

      m_pstillReceiver->m_ealignText = e_align_top_left;

      m_pstillReceiver->display_child(::rectangle_f64_dimension(iLeft, y, 4000, sizeEdit.cy * 100));

   }


   void form_001::handle(::topic * ptopic, ::context * pcontext)
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

                  output_debug_string("");

               }

               papp->data_set("last_folder", strText);

               m_pbuttonSend->set_window_text("Preview");

            }
            else if (ptopic->m_puserelement->m_atom == "edit_source")
            {

               string strText;

               m_peditSource->_001GetText(strText);

               auto papp = get_app();

               if (strText == "This is a test. This is a test")
               {

                  output_debug_string("");

               }

               papp->data_set("last_source", strText);

               m_pbuttonSend->set_window_text("Preview");

            }
            else if (ptopic->m_puserelement->m_atom == "edit_target")
            {

               string strText;

               m_peditTarget->_001GetText(strText);

               auto papp = get_app();

               if (strText == "This is a test. This is a test")
               {

                  output_debug_string("");

               }

               papp->data_set("last_target", strText);

               m_pbuttonSend->set_window_text("Preview");

            }

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


   void form_001::_001OnClearButton(::message::message * pmessage)
   {

      m_peditSource->_001SetText("", ::e_source_user);

      m_peditTarget->_001SetText("", ::e_source_user);

      pmessage->m_bRet = true;

   }


   void form_001::_001OnSendButton(::message::message * pmessage)
   {

      string strSend;

      m_pbuttonSend->get_window_text(strSend);

      bool bPreview = strSend == "Preview";

      string strFolder;

      m_peditFolder->_001GetText(strFolder);

      string strSource;

      m_peditSource->_001GetText(strSource);

      string strTarget;

      m_peditTarget->_001GetText(strTarget);


      string strMessage;

      strMessage.format("Gonna search for '%s', in '%s' and replace by '%s'\n\n",
         strSource.c_str(), strFolder.c_str(), strTarget.c_str());

      string strAction = get_windows_file_action(strTarget, strFolder, strSource, bPreview);

      strMessage += strAction;

      m_pstillReceiver->set_window_text(strMessage);

      m_pstillReceiver->post_redraw();

      if (bPreview)
      {

         m_pbuttonSend->set_window_text("Replace");

      }

      pmessage->m_bRet = true;



   }

   
   string form_001::get_windows_file_action(const string & strTarget, const ::string & strFolder, const string & strSource, bool bPreview)
   {

      file::listing listing;

      listing.set_pattern_file_listing(strFolder, { "*.lnk" });

      m_pcontext->m_papexcontext->dir().enumerate(listing);

      string strAction;

      if (listing.is_empty())
      {

         strAction = "No link files in Folder '" + strFolder + "'";

         return strAction;

      }

      for (auto & path : listing)
      {

         ::file::path pathLinkTarget;

         string strLinkFolder;

         m_pcontext->m_papexcontext->os_context()->resolve_link(pathLinkTarget, path, &strLinkFolder);

         ::file::path pathNewTarget(pathLinkTarget);

         string strNewFolder(strLinkFolder);
         
         pathNewTarget.replace_with(strTarget, strSource);

         strNewFolder.replace_with(strTarget, strSource);

         if (pathNewTarget != pathLinkTarget)
         {

            bool bIsDirTarget = m_psystem->m_pacmedirectory->is(pathNewTarget);

            bool bIsFileTarget = m_psystem->m_pacmefile->exists(pathNewTarget);

            bool bIs = bIsDirTarget || bIsFileTarget;

            strAction += (!bIs ? "xxx " : "") + path + ": " + pathNewTarget + " <== " + pathLinkTarget + "\n";

            if (!bIsDirTarget && !bPreview)
            {

               m_pcontext->m_papexcontext->os_context()->edit_link_target(pathNewTarget, path);

            }

         }
           
         if (strNewFolder != strLinkFolder)
         {

            bool bIsDirTarget = m_psystem->m_pacmedirectory->is(strNewFolder);

            strAction += (!bIsDirTarget ? "xxx " : "") + path + ": " + strNewFolder + " <== " + strLinkFolder + "\n";

            if (!bIsDirTarget && !bPreview)
            {

               m_pcontext->m_papexcontext->os_context()->edit_link_folder(strNewFolder, path);

            }

         }

      }

      return strAction;


   }


} // namespace simple_shortcut



