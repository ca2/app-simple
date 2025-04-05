#include "framework.h"
#include "form_001.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/handler/topic.h"
#include "acme/prototype/geometry2d/_text_stream.h"
#include "apex/database/_binary_stream.h"
#include "aura/message/user.h"
#include "aura/user/user/button.h"
#include "aura/user/user/still.h"
#include "aura/user/user/plain_edit.h"


namespace app_simple_form
{


   form_001::form_001()
   {

   }


   form_001::~form_001()
   {

   }


   //void form_001::destroy()
   //{

   //   m_pstill.release();
   //   m_pedit.release();
   //   m_pbuttonClear.release();
   //   m_pbuttonSend.release();
   //   m_pstillReceiver.release();

   //   ::app_simple_form::form::destroy();


   //}


//   void form_001::assert_ok() const
//   {
//
//      form::assert_ok();
//
//   }
//
//
//   void form_001::dump(dump_context & dumpcontext) const
//   {
//
//      form::dump(dumpcontext);
//
//   }


#ifdef _DEBUG


   long long form_001::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long form_001::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form_001::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form_001::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &form_001::on_message_destroy);

      add_command_handler("send_button", { this,  &form_001::_001OnSendButton });
      add_command_handler("clear_button", { this,  &form_001::_001OnClearButton });

   }


   void form_001::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __check_refdbg

      __construct_new(m_pstill);

      __check_refdbg

      __construct_new(m_pedit);

      __check_refdbg

      __construct_new(m_pbuttonClear);

      __check_refdbg

      __construct_new(m_pbuttonSend);

      __check_refdbg

      __construct_new(m_pstillReceiver);

      __check_refdbg

      m_pstill->create_control(this, "still");

      __check_refdbg

      m_pedit->create_control(this, "edit");

      __check_refdbg

      m_pedit->add_handler(this);

      __check_refdbg

      m_pbuttonClear->create_control(this, "clear_button");

      __check_refdbg

      m_pbuttonClear->add_handler(this);

      __check_refdbg

      m_pbuttonSend->create_control(this, "send_button");

      __check_refdbg

      m_pbuttonSend->add_handler(this);

      __check_refdbg

      m_pstill->set_window_text("Enter ___new text:");

      __check_refdbg

      m_pstillReceiver->create_control(this, "still");

      __check_refdbg

      m_pstillReceiver->set_window_text("(Waiting to receive...)");

      __check_refdbg

      m_pedit->m_strEmtpyText = "Enter New Text Here";

      __check_refdbg

      string strInitialText;

      __check_refdbg

      ::cast < ::database::client > pdatabaseclient = application();

      __check_refdbg

      pdatabaseclient->datastream()->get("last_text", strInitialText);

      __check_refdbg

      m_pedit->set_text(strInitialText, ::e_source_initialize);

      __check_refdbg

      m_pbuttonClear->set_window_text("Clear");

      __check_refdbg

      m_pbuttonSend->set_window_text("Send");

      __check_refdbg

      //set_need_layout();

      //set_need_redraw();

      //post_redraw();

   }


   void form_001::on_message_destroy(::message::message * pmessage)
   {

      __UNREFERENCED_PARAMETER(pmessage);

      m_pstill.release();
      m_pedit.release();
      m_pbuttonClear.release();
      m_pbuttonSend.release();
      m_pstillReceiver.release();

   }


   void form_001::on_perform_top_down_layout(::draw2d::graphics_pointer & pgraphics)
   {

      //::user::form_impact::on_perform_top_down_layout(pgraphics);

      auto rectClient = this->rectangle(::user::e_layout_lading);

      information() << "form_001 " << rectClient;
      
      double iLeft = minimum(100.0, rectClient.width() * 0.05);

      double iRight = iLeft;

      double y = iLeft * 2.0;
      
      auto sizeStill = m_pstill->get_adjusted_fitting_size(pgraphics);
      
      auto cx = rectClient.width() - iLeft - iRight;

      auto rectangleStillMargin = m_pstill->get_margin(m_pstill->get_style(pgraphics));

      y += rectangleStillMargin.top();
      
      m_pstill->m_ealignText = e_align_left;

      m_pstill->display_child(::double_rectangle_dimension(iLeft, y, sizeStill.cx(), sizeStill.cy()));

      y += sizeStill.cy();

      y += rectangleStillMargin.bottom();

      auto sizeEdit = m_pedit->get_adjusted_fitting_size(pgraphics);
      
      sizeEdit.cx() = cx;

      auto rectangleEditMargin = m_pedit->get_margin(m_pedit->get_style(pgraphics), ::e_element_none);
      
      //y += 1;
      
      y += rectangleEditMargin.top();

      m_pedit->display_child(::double_rectangle_dimension(iLeft, y, cx, sizeEdit.cy()));

      y += sizeEdit.cy();

      y += rectangleEditMargin.bottom();

      auto sizeButtonClear = m_pbuttonClear->get_adjusted_fitting_size(pgraphics);

      auto sizeButtonSend = m_pbuttonSend->get_adjusted_fitting_size(pgraphics);

      auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_pedit->get_style(pgraphics));

      auto sizeButtonMarginSend = m_pbuttonSend->get_margin(m_pedit->get_style(pgraphics));

      y += maximum(sizeButtonMarginClear.top(), sizeButtonMarginSend.top());

      y += 4;
      
      auto button_width = maximum(sizeButtonClear.cx() + 32, sizeButtonSend.cx() + 32);

      auto button_height = maximum(sizeButtonClear.cy(), sizeButtonSend.cy());

      ::double_rectangle rectangleSend;
      
      rectangleSend.right() = rectClient.right() - iRight;
      
      rectangleSend.left() = rectangleSend.right() - button_width;
      
      rectangleSend.top() = y;
      
      rectangleSend.bottom() = y + button_height;
      
      m_pbuttonSend->display_child(rectangleSend);
      
      ::double_rectangle rectangleClear;
      
      rectangleClear.right() = rectangleSend.left() - iLeft;
      
      rectangleClear.left() = rectangleClear.right() - button_width;
      
      rectangleClear.top() = rectangleSend.top();
      
      rectangleClear.bottom() = rectangleSend.bottom();

      m_pbuttonClear->display_child(rectangleClear);


      y += button_height + 20;

      m_pstillReceiver->display_child(::double_rectangle_dimension(iLeft, y, cx, sizeEdit.cy() * 5));

   }


   void form_001::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == ::id_after_change_text)
      {

         if (ptopic->m_actioncontext.is_user_source())
         {

            if (ptopic->m_puserelement->user_interaction()->id() == "edit")
            {

               string strText;

               m_pedit->get_text(strText);

               ::cast < ::database::client > pdatabaseclient = application();

               if (strText == "This is a test. This is a test")
               {

                  informationf("");

               }

               pdatabaseclient->datastream()->set("last_text", strText);

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


   void form_001::_001OnClearButton(::message::message * pmessage)
   {

      m_pedit->set_text("", ::e_source_user);

      pmessage->m_bRet = true;

   }


   void form_001::_001OnSendButton(::message::message * pmessage)
   {

      string strText;

      m_pedit->get_text(strText);

      output_error_message("send_button clicked\nText: " + strText);

      m_pstillReceiver->set_window_text(strText);

      m_pstillReceiver->post_redraw();

      pmessage->m_bRet = true;

   }


} // namespace simple_form



