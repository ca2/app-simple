#pragma once


namespace app_simple_shortcut
{


   class CLASS_DECL_APP_SIMPLE_SHORTCUT frame :
      virtual public simple_frame_window
   {
   public:


      frame();
      virtual ~frame();


	   void assert_ok() const override;
	   void dump(dump_context & dumpcontext) const override;


      //virtual ::user::enum_translucency get_translucency(::user::style * pstyle) const override;


   };


} // namespace simple_shortcut











