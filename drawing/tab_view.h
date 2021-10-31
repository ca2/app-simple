#pragma once


namespace simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_DRAWING tab_view :
      virtual public application_interaction < application, ::user::tab_view >,
      virtual public ::user::form_callback
   {
   public:


      ::user::split_view *                            m_ptopviewLast;
      __reference(::simple_drawing::impact)     m_pimpactTopic;
      string                                          m_strTopicTitle;


      __pointer(::user::document)               m_pdocMenu;


      tab_view();
      ~tab_view() override;


      void on_create_impact(::user::impact_data * pimpactdata) override;

      void install_message_routing(::channel * pchannel) override;

      void assert_valid() const override;

      void dump(dump_context & dumpcontext) const override;


      DECLARE_MESSAGE_HANDLER(on_message_create);


      void on_change_cur_sel() override;

      void handle(::subject * psubject, ::context * pcontext) override;


   };


} // namespace simple_drawing




