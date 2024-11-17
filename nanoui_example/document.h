#pragma once


namespace app_simple_nanoui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOUI_EXAMPLE document :
      public ::user::document
   {
   public:
      
      
      string_array   m_straLine;


      document();
	   ~document() override;


	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;

      bool on_new_document() override;
      virtual bool on_open_document(const ::payload & payloadFile) override;

#ifdef _DEBUG
      virtual huge_integer increment_reference_count() override;
      virtual huge_integer decrement_reference_count() override;
#endif

      virtual ::stream& write(::stream& stream) const override;


   };


} // namespace simple_application















