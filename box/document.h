#pragma once


#include "berg/user/user/document.h"


namespace app_simple_box
{


   class CLASS_DECL_APP_SIMPLE_BOX document :
      virtual public ::user::document
   {
   public:
      
      
      string_array   m_straLine;


      document();
	   ~document() override;


	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;

      bool on_new_document() override;
      bool on_open_document(const ::payload & payloadFile) override;


#ifdef _DEBUG

      long long increment_reference_count() override;
      long long decrement_reference_count() override;

#endif


      //::stream& write(::stream& stream) const override;


   };


} // namespace app_simple_box



