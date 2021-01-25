#include "framework.h"
#include <math.h>


namespace simple_form
{


   simple_form_002::simple_form_002()
   {


   }


   simple_form_002::~simple_form_002()
   {

   }


   void simple_form_002::assert_valid() const
   {

      simple_form::assert_valid();

   }


   void simple_form_002::dump(dump_context & dumpcontext) const
   {

      simple_form::dump(dumpcontext);

   }


#ifdef _DEBUG

  
   int64_t simple_form_002::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t simple_form_002::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void simple_form_002::install_message_routing(::channel * psender)
   {

      simple_form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &simple_form_002::_001OnCreate);

   }


   void simple_form_002::_001OnCreate(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __compose_new(m_pstill);

      __compose_new(m_pedit);

      __compose_new(m_pcombobox);

      m_pcombobox->m_bEdit = false;

      __compose_new(m_pbutton);

      m_pstill->create_child(this);

      m_pedit->create_child(this);

      m_pcombobox->create_child(this);

      m_pbutton->create_child(this);

      m_pstill->set_window_text("Enter new text:");

      m_pedit->m_strEmtpyText = "Enter New Text Here";

      m_pbutton->set_window_text("Send");

      m_pcombobox->m_edatamode = ::user::combo_box::data_mode_string;

      m_pcombobox->AddString("Combo1", "ComboData001");

      m_pcombobox->AddString("Combo2", "ComboData002");

      m_pcombobox->AddString("Combo3", "ComboData003");

      m_pcombobox->AddString("Combo4", "ComboData004");

   }


   void simple_form_002::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_view::on_layout(pgraphics);

      double iLeft = 100.;

      double y = 100.;

      auto sizeStill = m_pstill->_001CalculateAdjustedFittingSize(pgraphics);

      m_pstill->display_child(::rectd_dim(iLeft, y, 200, sizeStill.cy));

      y += sizeStill.cy * 1.25;

      auto sizeEdit = m_pedit->_001CalculateAdjustedFittingSize(pgraphics);

      m_pedit->display_child(::rectd_dim(iLeft-30.0, y, 200.0, sizeEdit.cy));

      y += sizeEdit.cy * 1.25;

      auto sizeCombo = m_pcombobox->_001CalculateAdjustedFittingSize(pgraphics);

      m_pcombobox->display_child(::rectd_dim(iLeft, y, 200., sizeCombo.cy));

      y += sizeCombo.cy * 1.25;

      auto sizeButton = m_pbutton->_001CalculateAdjustedFittingSize(pgraphics);

      m_pbutton->display_child(::rectd_dim(iLeft-30., y, 200., sizeButton.cy));

   }


   void simple_form_002::on_control_event(::user::control_event * pevent)
   {

      if (pevent->m_eevent == ::user::e_event_button_clicked)
      {

         if (pevent->m_id == "send_button")
         {

            string strText1;
            
            m_pedit->_001GetText(strText1);

            string strText2;

            m_pcombobox->_001GetText(strText2);

            string strText;

            strText = strText1 + ";" + strText2;

            string strData;

            strData = m_pcombobox->get_current_item_string_value();

            //auto routine = [this, strText, strData]()
            //{

               message_box("<h1>send_button clicked</h1><h2>Text: " + strText + "</h2><h2>Data: " + strData + "</h2>", strText);

            //};

            //auto proutine = __routine(routine);

            //main_async(proutine);

         }

      }

   }


} // namespace simple_form



