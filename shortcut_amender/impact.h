#pragma once


#include "base/user/user/impact.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender impact :
      virtual public ::user::impact
   {
   public:


      impact();
      ~impact() override;


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      ::user::document * get_document();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);

   };


} // namespace simple_shortcut


