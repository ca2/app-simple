#pragma once


namespace app_simple_box
{


   class CLASS_DECL_APP_SIMPLE_BOX document :
      virtual public ::user::document
   {
   public:
      
      
      string_array   m_straLine;


      document();
	   ~document() override;


	   void assert_valid() const override;
	   void dump(dump_context & dumpcontext) const override;

      bool on_new_document() override;
      bool on_open_document(const ::payload & payloadFile) override;


#ifdef _DEBUG

      int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;

#endif


      ::stream& write(::stream& stream) const override;


   };


} // namespace app_simple_box



