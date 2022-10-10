#pragma once


#include "form.h"


namespace app_simple_shortcut
{


   class CLASS_DECL_APP_SIMPLE_SHORTCUT form_002 :
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

      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      virtual void install_message_routing(::channel * psender) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnSendButton);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      virtual void handle(::topic * ptopic, ::context * pcontext) override;


   };


} // namespace simple_shortcut


