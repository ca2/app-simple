#pragma once


#include "base/user/simple/frame_window.h"


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION frame :
      virtual public simple_frame_window
   {
   public:


      frame();
      ~frame() override;


	   void assert_ok() const override;
	   void dump(dump_context & dumpcontext) const override;


      //virtual ::user::enum_translucency get_translucency(::user::style * pstyle) const override;


   };


} // namespace app_simple_networking_application












