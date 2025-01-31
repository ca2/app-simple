#include "framework.h"
#include "form_002.h"
#include "acme/constant/id.h"
#include "acme/handler/topic.h"
#include "aura/message/user.h"
#include "aura/user/user/still.h"
#include "aura/user/user/button.h"
#include "axis/user/user/combo_box.h"


namespace app_simple_change_grub_default_entry
{


   form_002::form_002()
   {


   }


   form_002::~form_002()
   {

   }


   //void form_002::assert_ok() const
   //{

   //   form::assert_ok();

   //}


   //void form_002::dump(dump_context & dumpcontext) const
   //{

   //   form::dump(dumpcontext);

   //}


#ifdef _DEBUG

  
   huge_integer form_002::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   huge_integer form_002::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form_002::install_message_routing(::channel * psender)
   {

      form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form_002::on_message_create);

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

      m_pstill->create_control(this, "still");

      m_pedit->create_control(this, "edit");

      m_pcombobox->create_control(this, "combo_box");

      m_pbutton->create_control(this, "send_button");

      m_pbutton->add_handler(this);

      m_pstill->set_window_text("Enter ___new text:");

      m_pedit->m_strEmtpyText = "Enter New Text Here";

      m_pbutton->set_window_text("Send");

      //m_pcombobox->m_edatamode = ::user::combo_box::data_mode_string;

      m_pcombobox->add_item("Combo1", "ComboData001");

      m_pcombobox->add_item("Combo2", "ComboData002");

      m_pcombobox->add_item("Combo3", "ComboData003");

      m_pcombobox->add_item("Combo4", "ComboData004");

   }


   void form_002::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_impact::on_layout(pgraphics);

      double iLeft = 100.;

      double y = 100.;

      auto sizeStill = m_pstill->get_adjusted_fitting_size(pgraphics);

      m_pstill->display_child(::double_rectangle_dimension(iLeft, y, 200, sizeStill.cy()));

      y += sizeStill.cy() * 1.25;

      auto sizeEdit = m_pedit->get_adjusted_fitting_size(pgraphics);

      m_pedit->display_child(::double_rectangle_dimension(iLeft-30.0, y, 200.0, sizeEdit.cy()));

      y += sizeEdit.cy() * 1.25;

      auto sizeCombo = m_pcombobox->get_adjusted_fitting_size(pgraphics);

      m_pcombobox->display_child(::double_rectangle_dimension(iLeft, y, 200., sizeCombo.cy()));

      y += sizeCombo.cy() * 1.25;

      auto sizeButton = m_pbutton->get_adjusted_fitting_size(pgraphics);

      m_pbutton->display_child(::double_rectangle_dimension(iLeft-30., y, 200., sizeButton.cy()));

   }


   void form_002::handle(::topic * ptopic, ::context * pcontext)
   {

      if (ptopic->id() == ::id_click)
      {

         if (ptopic->m_puserelement->user_interaction()->id() == "send_button")
         {

            string strText1;
            
            m_pedit->get_text(strText1);

            string strText2;

            m_pcombobox->get_text(strText2);

            string strText;

            strText = strText1 + ";" + strText2;

            string strData;

            strData = m_pcombobox->get_current_iteid()();

            //auto routine = [this, strText, strData]()
            //{

               output_error_message("<h1>send_button clicked</h1><h2>Text: " + strText + "</h2><h2>Data: " + strData + "</h2>", strText);

            //};

            //auto proutine = __routine(routine);

            //main_async(proutine);

         }

      }

   }


} // namespace app_simple_change_grub_default_entry



