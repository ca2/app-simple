#pragma once


#include "form.h"


namespace app_simple_form
{


   class CLASS_DECL_APP_SIMPLE_FORM form_002 :
      virtual public form
   {
   public:


      ::pointer<::user::still>                m_pstill;
      ::pointer<::user::plain_edit>           m_pedit;
      ::pointer<::user::combo_box>            m_pcombobox;
      ::pointer<::user::button>               m_pbutton;
      ::pointer<::user::still>                m_pstillResponse;


      form_002();
      ~form_002() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      virtual void install_message_routing(::channel * psender) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnSendButton);

      void on_perform_top_down_layout(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;


   };


} // namespace simple_form


