#pragma once


#include "base/user/form/impact.h"


namespace app_simple_form
{


   class CLASS_DECL_APP_SIMPLE_FORM form :
      virtual public ::user::form_impact
   {
   public:


      tab_impact *                          m_ptabimpact;
      string                              m_strFont;
      int                                 m_iId;


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


} // namespace simple_form



