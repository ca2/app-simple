#pragma once


#include "base/user/simple/frame_window.h"


namespace simple_os_drag_and_drop
{


   class CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP frame :
      virtual public simple_frame_window
   {
   public:


      frame();
      ~frame() override;


	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;


//      ::user::enum_translucency get_translucency(::user::style * pstyle) override;


   };


} // namespace simple_os_drag_and_drop












