#pragma once


#include "base/user/form/impact.h"


namespace app_simple_change_grub_default_entry
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

      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;


      void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      virtual void install_message_routing(::channel * psender) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

   };


} // namespace app_simple_change_grub_default_entry


