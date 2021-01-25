#include "framework.h"
#include <math.h>


namespace simple_form
{


   simple_form_001::simple_form_001()
   {

   }


   simple_form_001::~simple_form_001()
   {

   }


   void simple_form_001::assert_valid() const
   {

      simple_form::assert_valid();

   }


   void simple_form_001::dump(dump_context & dumpcontext) const
   {

      simple_form::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t simple_form_001::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t simple_form_001::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void simple_form_001::install_message_routing(::channel * psender)
   {

      simple_form::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &simple_form_001::_001OnCreate);

   }


   void simple_form_001::_001OnCreate(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      __compose_new(m_pstill);

      __compose_new(m_pedit);

      __compose_new(m_pbuttonClear);

      __compose_new(m_pbuttonSend);

      m_pstill->create_control(this, "still");

      m_pedit->create_control(this, "edit");

      m_pbuttonClear->create_control(this, "clear_button");

      m_pbuttonSend->create_control(this, "send_button");

      m_pstill->set_window_text("Enter new text:");

      m_pedit->m_strEmtpyText = "Enter New Text Here";

      string strInitialText;

      strInitialText = Application.data_get("last_text");

      m_pedit->_001SetText(strInitialText, ::e_source_initialize);

      m_pbuttonClear->set_window_text("Clear");

      m_pbuttonSend->set_window_text("Send");

   }


   void simple_form_001::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_view::on_layout(pgraphics);

      double iLeft = 100.;

      double y = 100.;

      auto sizeStill = m_pstill->_001CalculateAdjustedFittingSize(pgraphics);

      auto rectStillMargin = m_pstill->get_margin(m_pstill->get_style(pgraphics));

      y += rectStillMargin.top;

      m_pstill->display_child(::rectd_dim(iLeft, y, sizeStill.cx, sizeStill.cy));

      y += sizeStill.cy;

      y += rectStillMargin.bottom;

      auto sizeEdit = m_pedit->_001CalculateAdjustedFittingSize(pgraphics);

      auto rectEditMargin = m_pedit->get_margin(m_pedit->get_style(pgraphics), ::user::e_element_none);

      y += rectEditMargin.top;

      m_pedit->display_child(::rectd_dim(iLeft, y, 600, sizeEdit.cy));

      y += sizeEdit.cy;

      y += rectEditMargin.bottom;

      auto sizeButtonClear = m_pbuttonClear->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonSend = m_pbuttonSend->_001CalculateAdjustedFittingSize(pgraphics);

      auto sizeButtonMarginClear = m_pbuttonClear->get_margin(m_pedit->get_style(pgraphics));

      auto sizeButtonMarginSend = m_pbuttonSend->get_margin(m_pedit->get_style(pgraphics));

      y += max(sizeButtonMarginClear.top, sizeButtonMarginSend.top);

      auto button_width = max(sizeButtonClear.cx + 32, sizeButtonSend.cx + 32);

      auto button_height = max(sizeButtonClear.cy, sizeButtonSend.cy);

      m_pbuttonClear->display_child(::rectd_dim(iLeft, y, button_width, button_height));

      m_pbuttonSend->display_child(::rectd_dim(iLeft + button_width + 32, y, button_width, button_height));

   }


   void simple_form_001::on_control_event(::user::control_event * pevent)
   {

      if (pevent->m_eevent == ::user::e_event_after_change_text)
      {

         if (pevent->m_actioncontext.is_user_source())
         {

            if (pevent->m_id == "edit")
            {

               string strText;

               m_pedit->_001GetText(strText);

               Application.data_set("last_text", strText);

            }

         }

      }
      else if (pevent->m_eevent == ::user::e_event_button_clicked)
      {

         if (pevent->m_id == "clear_button")
         {

            m_pedit->_001SetText("", ::e_source_user);

         }
         else if (pevent->m_id == "send_button")
         {

            string strText;

            m_pedit->_001GetText(strText);

            //main_async(__routine([this, strText]()
              // {

                  message_box("send_button clicked\nText: " + strText);

               //}));

            pevent->m_bRet = true;

         }

      }

   }


} // namespace simple_form



