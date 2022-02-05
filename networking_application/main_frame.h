#pragma once


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION main_frame :
      virtual public simple_main_frame
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame();
      virtual ~main_frame();


      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;


      //virtual ::user::enum_translucency get_translucency(::user::style * pstyle) const override;
      virtual ::experience::frame * frame_experience() override;

      virtual bool has_pending_graphical_update() override;

   };


} // namespace app_simple_networking_application












