#pragma once


namespace simple_application
{


   class CLASS_DECL_APP_SIMPLE_APPLICATION main_frame :
      virtual public simple_main_frame
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame();
      ~main_frame() override;


      void assert_valid() const override;
      void dump(dump_context & dumpcontext) const override;


      ::experience::frame * experience_get_frame() override;


      bool has_pending_graphical_update() override;


      void install_message_routing(::channel * pchannel) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);


   };


} // namespace simple_application



