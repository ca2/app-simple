#pragma once


#include "base/platform/application.h"


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_CHANGE_GRUB_DEFAULT_ENTRY application :
      virtual public ::base::application
   {
   public:


      //::user::single_document_template *     m_ptemplateChangeGrubDefaultEntryMain;


      application();
      ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();


      virtual string preferred_experience() override;
      void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::request * prequest) override;


#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif


   };


} // namespace app_simple_change_grub_default_entry



