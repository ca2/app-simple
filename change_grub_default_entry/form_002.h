#pragma once


#include "form.h"


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_CHANGE_GRUB_DEFAULT_ENTRY form_002 :
      virtual public form
   {
   public:


      ::pointer<::user::still>                m_pstill;
      ::pointer<::user::plain_edit>           m_pedit;
      ::pointer<::user::combo_box>            m_pcombobox;
      ::pointer<::user::button>               m_pbutton;


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

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * pcontext) override;


   };


} // namespace app_simple_change_grub_default_entry


