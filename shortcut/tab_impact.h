#pragma once


namespace app_simple_shortcut
{


   class CLASS_DECL_APP_SIMPLE_SHORTCUT tab_impact :
      virtual public ::user::tab_impact,
      virtual public ::user::form_callback
   {
   public:


      ::user::split_impact *                            m_ptopviewLast;
      impact *                                          m_pimpactLast;
      string                                          m_strTopicTitle;


      __pointer(::user::document)                            m_pdocMenu;


      tab_impact();
      ~tab_impact() override;


      void on_create_impact(::user::impact_data * pimpactdata) override;

      void install_message_routing(::channel * pchannel) override;

      void assert_ok() const override;

      void dump(dump_context & dumpcontext) const override;

      DECLARE_MESSAGE_HANDLER(on_message_create);

      void handle(::topic * ptopic, ::context * pcontext) override;

      void on_change_cur_sel() override;


   };


} // namespace simple_shortcut













