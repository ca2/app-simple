#pragma once


#include "base/user/user/split_impact.h"
#include "apex/platform/app_consumer.h"


namespace app_simple_form
{


   class CLASS_DECL_APP_SIMPLE_FORM main_impact:
      virtual public ::app_consumer < application, ::user::split_impact >
   {
   public:


      //::userex::top_impact *    m_ptopimpact;
      impact *                  m_pimpact;


      main_impact();
      virtual ~main_impact();


      // void assert_ok() const override;

      // void dump(dump_context & dumpcontext) const override;

      void on_create_split_impact() override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

//      virtual bool BaseOnControlEvent(::user::control_event * phappening);


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace simple_form





