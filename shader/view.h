#pragma once


namespace simple_shader
{


   class CLASS_DECL_APP_SIMPLE_SHADER view :
      virtual public ::application_consumer < application, ::user::impact >
   {
   public:


      int                                 m_iView;
      __pointer(::app_shader::render)     m_prender;
      bool                                m_bSaveFrame;


      view();
      virtual ~view();

      virtual void assert_valid() const override;
      virtual void dump(dump_context & dumpcontext) const override;


#ifdef DEBUG
      virtual int64_t add_ref(OBJ_REF_DBG_PARAMS) override;
      virtual int64_t dec_ref(OBJ_REF_DBG_PARAMS) override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      virtual void on_subject(::subject::subject * psubject, ::subject::context * pcontext) override;

      ::user::document * get_document();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnDestroy);
      DECLARE_MESSAGE_HANDLER(_001OnKeyDown);

      virtual bool keyboard_focus_is_focusable() const override;

   };


} // namespace simple_shader


