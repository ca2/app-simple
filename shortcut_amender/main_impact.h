#pragma once


#include "apex/platform/app_consumer.h"
#include "base/user/user/split_impact.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender main_impact:
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

      void handle(::topic * ptopic, ::context * pcontext) override;

//      virtual bool BaseOnControlEvent(::user::control_event * pevent);


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace simple_shortcut





