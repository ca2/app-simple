#pragma once


namespace simple_form
{


   class CLASS_DECL_APP_SIMPLE_FORM simple_form_001 :
      virtual public simple_form
   {
   public:


      __composite(::user::still)             m_pstill;
      __composite(::user::plain_edit)        m_pedit;
      __composite(::user::button)            m_pbuttonClear;
      __composite(::user::button)            m_pbuttonSend;
      __composite(::user::still)             m_pstillReceiver;


      simple_form_001();
      virtual ~simple_form_001();

      void assert_valid() const override;
      void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      virtual void install_message_routing(::channel * psender) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      virtual void handle(::subject * psubject, ::context * pcontext) override;


   };


} // namespace simple_form


