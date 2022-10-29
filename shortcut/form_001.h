#pragma once


#include "form.h"


namespace app_simple_shortcut
{


   class CLASS_DECL_APP_SIMPLE_SHORTCUT form_001 :
      virtual public ::app_simple_shortcut::form
   {
   public:


      ::pointer<::user::still>             m_pstillFolder;
      ::pointer<::user::plain_edit>        m_peditFolder;
      ::pointer<::user::still>             m_pstillSource;
      ::pointer<::user::plain_edit>        m_peditSource;
      ::pointer<::user::still>             m_pstillTarget;
      ::pointer<::user::plain_edit>        m_peditTarget;
      ::pointer<::user::button>            m_pbuttonClear;
      ::pointer<::user::button>            m_pbuttonSend;
      ::pointer<::user::still>             m_pstillReceiver;


      form_001();
      ~form_001() override;


//      // void assert_ok() const override;
//      void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      virtual void install_message_routing(::channel * psender) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnSendButton);
      DECLARE_MESSAGE_HANDLER(_001OnClearButton);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      virtual void handle(::topic * ptopic, ::context * pcontext) override;

      virtual string get_windows_file_action(const string & strTarget, const ::string & strFolder, const string & strSource, bool bThumbnail);


   };


} // namespace simple_shortcut


