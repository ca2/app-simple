#pragma once


#include "base/user/form/impact.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender form :
      virtual public ::user::form_impact
   {
   public:


      tab_impact *                          m_ptabimpact;
      string                              m_strFont;
      int                                 m_iId;
      ::pointer<::user::still>             m_pstillFolder;
      ::pointer<::user::plain_edit>        m_peditFolder;
      ::pointer<::user::still>             m_pstillSource;
      ::pointer<::user::plain_edit>        m_peditSource;

      ::pointer<::user::button>            m_pbuttonClear;
      ::pointer<::user::button>            m_pbuttonSend;


      ::pointer<::user::still>             m_pstillReceiver;


      form();
      ~form() override;


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


      void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

#ifdef _DEBUG

      long long increment_reference_count() override;
      long long decrement_reference_count() override;

#endif

      void install_message_routing(::channel * psender) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;


   };


} // namespace simple_shortcut



