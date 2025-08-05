#pragma once


#include "berg/user/user/impact.h"
#include "apex/platform/app_consumer.h"


namespace app_simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_DRAWING impact :
      virtual public app_consumer < application, ::user::impact >
   {
   public:


      ::pointer<render>          m_prender;


      impact();
      ~impact() override;

      
//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      long long increment_reference_count() override;
      long long decrement_reference_count() override;
#endif


      void on_property_changed(::data::property_change & change) override;


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      ::user::document * get_document();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);

   };


} // namespace simple_drawing


