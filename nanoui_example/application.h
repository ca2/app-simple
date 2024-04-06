#pragma once


#include "aura/platform/application.h"


namespace app_simple_nanoui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOUI_EXAMPLE application :
      virtual public ::aura::application
   {
   public:


      ::pointer<::app_simple_nanoui_example::main_window>       m_pmainwindow;


      application();
      ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();



      virtual string preferred_experience() override;
      virtual void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::request * prequest) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif

   };


} // namespace simple_application



