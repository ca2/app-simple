#pragma once


#include "apex/platform/app_consumer.h"
#include "base/user/user/split_impact.h"


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_CHANGE_GRUB_DEFAULT_ENTRY main_impact:
      virtual public ::app_consumer < application, ::user::split_impact >
   {
   public:


      //::userex::top_impact *    m_ptopimpact;
      impact *                  m_pimpact;


      main_impact();
      ~main_impact() override;


      // void assert_ok() const override;

      // void dump(dump_context & dumpcontext) const override;

      void on_create_split_impact() override;

      void handle(::topic * ptopic, ::handler_context * pcontext) override;

      //virtual bool BaseOnControlEvent(::user::control_event * phappening);


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace app_simple_change_grub_default_entry





