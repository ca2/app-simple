#pragma once


#include "base/platform/application.h"


namespace app_simple_box
{


   class CLASS_DECL_APP_SIMPLE_BOX application :
      virtual public ::base::application
   {
   public:


      ::payload                           m_varMessage;
      ::user::single_document_template *  m_ptemplateAppSimpleBoxMain;



      application();
      ~application() override;


      void init_instance() override;

      
      void on_request(::create * pcreate) override;


   };


} // namespace app_simple_box



