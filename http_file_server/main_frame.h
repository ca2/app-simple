#pragma once


#include "base/user/simple/main_frame.h"


namespace app_simple_http_file_server
{


   class CLASS_DECL_APP_SIMPLE_HTTP_FILE_SERVER main_frame :
      virtual public simple_main_frame
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame();
      ~main_frame() override;


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


      //::user::enum_translucency get_translucency(::user::style * pstyle) override;
      ::pointer < ::experience::frame > frame_experience() override;

      //bool has_pending_graphical_update() override;

   };


} // namespace app_simple_http_file_server












