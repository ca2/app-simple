#pragma once


namespace simple_application
{


   class CLASS_DECL_APP_SIMPLE_APPLICATION view :
      virtual public ::application_consumer < application, ::user::impact >
   {
   public:


      ::write_text::font_pointer       m_pfontThomasBS_;
      string                           m_strFont1;

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

      document * get_document();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);

   };


} // namespace simple_application


