#pragma once


namespace app_simple_shader
{


   class CLASS_DECL_APP_SIMPLE_SHADER impact :
      virtual public ::application_consumer < application, ::user::impact >
   {
   public:


      int                                 m_iView;
      __pointer(::app_shader::render)     m_prender;
      bool                                m_bSaveFrame;


      impact();
      virtual ~impact();

      void assert_valid() const override;
      void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      virtual void handle(::topic * psubject, ::context * pcontext) override;

      ::user::document * get_document();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      DECLARE_MESSAGE_HANDLER(on_message_key_down);

      virtual bool keyboard_focus_is_focusable() const override;

   };


} // namespace simple_shader


