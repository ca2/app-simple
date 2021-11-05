#pragma once


namespace app_simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_DRAWING main_frame :
      virtual public simple_main_frame
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame();
      ~main_frame() override;


      void assert_valid() const override;
      void dump(dump_context & dumpcontext) const override;


      //virtual ::user::enum_translucency get_translucency(::user::style * pstyle) const override;
      ::experience::frame * experience_get_frame() override;


      bool has_pending_graphical_update() override;


      void install_message_routing(::channel * pchannel) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);


   };


} // namespace simple_drawing












