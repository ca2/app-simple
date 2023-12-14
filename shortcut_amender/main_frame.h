#pragma once


#include "base/user/simple/main_frame.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender main_frame :
      virtual public simple_main_frame
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame();
      virtual ~main_frame();


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


      //::user::enum_translucency get_translucency(::user::style * pstyle) override;
      ::pointer < ::experience::frame > frame_experience() override;

      //bool has_pending_graphical_update() override;

   };


} // namespace simple_shortcut












