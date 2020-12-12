#pragma once


namespace simple_video
{


   class CLASS_DECL_APP_SIMPLE_VIDEO frame :
      virtual public simple_frame_window
   {
   public:


      frame();
      virtual ~frame();


	   virtual void assert_valid() const override;
	   virtual void dump(dump_context & dumpcontext) const override;


      //virtual ::user::enum_translucency get_translucency(::user::style * pstyle) const override;


   };


} // namespace simple_video












