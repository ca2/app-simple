#pragma once


#include "berg/platform/application.h"


namespace app_simple_box
{


   class CLASS_DECL_APP_SIMPLE_BOX application :
      virtual public ::base::application
   {
   public:


      ::payload                           m_varMessage;
      //::user::single_document_template *  m_ptemplateAppSimpleBoxMain;



      application();
      ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();



      void init_instance() override;

      
      void on_request(::request * prequest) override;


   };


} // namespace app_simple_box



