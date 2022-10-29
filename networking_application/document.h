#pragma once


#include "base/user/user/document.h"


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION document :
      public ::user::document
   {
   public:


      document();
	   ~document() override;


	   // void assert_ok() const override;
	   void dump(dump_context & dumpcontext) const override;

      bool on_new_document() override;
      virtual bool on_open_document(const ::payload & payloadFile) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      //virtual void write(::binary_stream < FILE > & stream) const override;


   };


} // namespace app_simple_networking_application















