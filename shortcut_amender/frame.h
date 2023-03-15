#pragma once


#include "base/user/simple/frame_window.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender frame :
      virtual public simple_frame_window
   {
   public:


      frame();
      virtual ~frame();


	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;


      //::user::enum_translucency get_translucency(::user::style * pstyle) override;


   };


} // namespace simple_shortcut












