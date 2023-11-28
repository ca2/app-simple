#pragma once


#include "base/user/user/document.h"


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_CHANGE_GRUB_DEFAULT_ENTRY document :
      public ::user::document
   {
   public:


      document();
	   virtual ~document();

      
	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;

      bool on_new_document() override;
      virtual bool on_open_document(const ::payload & payloadFile) override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count(REFERENCING_DEBUGGING_PARAMETERS) override;
      virtual int64_t decrement_reference_count(REFERENCING_DEBUGGING_PARAMETERS) override;
#endif


   };


} // namespace app_simple_change_grub_default_entry















