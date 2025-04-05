#include "framework.h"
#include "form_002.h"
#include "acme/constant/message.h"
#include "aura/message/user.h"
#include "axis/user/user/combo_box.h"
#include "aura/user/user/button.h"
#include "aura/user/user/still.h"
#include "aura/user/user/plain_edit.h"


namespace app_simple_form
{


   form_002::form_002()
   {


   }


   form_002::~form_002()
   {

   }


//   void form_002::assert_ok() const
//   {
//
//      form::assert_ok();
//
//   }
//
//
//   void form_002::dump(dump_context & dumpcontext) const
//   {
//
//      form::dump(dumpcontext);
//
//   }


#ifdef _DEBUG

  
   long long form_002::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long form_002::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form_002::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form_002::on_message_create);

      add_command_handler("send_button", { this,  &form_002::_001OnSendButton });

   }


   void form_002::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __construct_new(m_pstill);

      __construct_new(m_pedit);

      __construct_new(m_pcombobox);

      m_pcombobox->m_bEdit = false;

      __construct_new(m_pbutton);

      __construct_new(m_pstillResponse);

      m_pstill->create_control(this, "still");

      m_pedit->create_control(this, "edit");

      m_pcombobox->create_control(this, "combo_box");

      m_pbutton->create_control(this, "send_button");

      m_pbutton->add_handler(this);

      m_pstill->set_window_text("Enter ___new text:");

      m_pedit->m_strEmtpyText = "Enter New Text Here";

      m_pstillResponse->create_control(this, "still_response");

      m_pbutton->set_window_text("Send");

      m_pstillResponse->set_window_text("(Waiting for data to be sent...)");

      m_pstillResponse->m_etextwrap = e_text_wrap_character;

      //m_pcombobox->m_edatamode = ::user::combo_box::data_mode_string;

      m_pcombobox->add_item("Combo1", "ComboData001");

      m_pcombobox->add_item("Combo2", "ComboData002");

      m_pcombobox->add_item("Combo3", "ComboData003");

      m_pcombobox->add_item("Combo4", "ComboData004");

   }


   void form_002::on_perform_top_down_layout(::draw2d::graphics_pointer & pgraphics)
   {

      //::user::form_impact::on_layout(pgraphics);

      auto rectClient = this->rectangle(::user::e_layout_lading);
      
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

      m_pedit->display_child(::double_rectangle_dimension(iLeft, y, 200.0, sizeEdit.cy()));

      y += sizeEdit.cy();

      y += rectangleEditMargin.bottom();

      y += 4;

      auto sizeCombo = m_pcombobox->get_adjusted_fitting_size(pgraphics);

      m_pcombobox->display_child(::double_rectangle_dimension(iLeft, y, 200.0, sizeCombo.cy()));

      y += sizeCombo.cy() + 4;

      auto sizeButton = m_pbutton->get_adjusted_fitting_size(pgraphics);

      m_pbutton->display_child(::double_rectangle_dimension(iLeft, y, 200., sizeButton.cy()));

      y += sizeButton.cy() + 4;

      m_pstillResponse->display_child(::double_rectangle_dimension(iLeft, y, 200, sizeEdit.cy() * 8));

   }


   void form_002::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

//      if (ptopic->id() == ::id_click)
//      {
//
//         if (ptopic->user_interaction_id() == "send_button")
//         {
//
//            string strText1;
//
//            m_pedit->get_text(strText1);
//
//            string strText2;
//
//            m_pcombobox->get_text(strText2);
//
//            string strText;
//
//            strText = strText1 + ";" + strText2;
//
//            string strData;
//
//            strData = m_pcombobox->get_current_item_string_value();
//
//            //auto routine = [this, strText, strData]()
//            //{
//            string strMessage = "<h1>send_button clicked</h1><h2>Text: " + strText + "</h2><h2>Data: " + strData + "</h2>" + strText;
//               output_error_message("<h1>send_button clicked</h1><h2>Text: " + strText + "</h2><h2>Data: " + strData + "</h2>", strText);
//
//            //};
//
//            //auto proutine = __routine(routine);
//
//            //main_async(proutine);
//
//               m_pstillResponse->set_window_text(strMessage);
//
//               m_pstillResponse->post_redraw();
//
//         }
//
//      }

   }


   void form_002::_001OnSendButton(::message::message * pmessage)
   {

//      if (ptopic->id() == ::id_click)
//      {
//
//         if (ptopic->user_interaction_id() == "send_button")
//         {

         string strText1;

         m_pedit->get_text(strText1);

         string strText2;

         m_pcombobox->get_text(strText2);

         string strText;

         strText = strText1 + ";" + strText2;

         string strData;

         strData = m_pcombobox->get_current_item_id();        //auto routine = [this, strText, strData]()
         //{
         string strMessage = "<h1>send_button clicked</h1><h2>Text: " + strText + "</h2><h2>Data: " + strData + "</h2>" + strText;
         output_error_message("<h1>send_button clicked</h1><h2>Text: " + strText + "</h2><h2>Data: " + strData + "</h2>", strText);

         //};

         //auto proutine = __routine(routine);

         //main_async(proutine);

         m_pstillResponse->set_window_text(strMessage);

         m_pstillResponse->post_redraw();

//         }
//
//      }

   }


} // namespace simple_form



