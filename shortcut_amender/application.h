#pragma once


#include "berg/platform/application.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender application :
      virtual public ::base::application
   {
   public:


      ::user::document *                     m_pdocMenu;
      //::user::single_document_template *     m_ptemplateShortcutAmenderMain;
      //::user::single_document_template *     m_ptemplateShortcutAmenderImpact;


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


} // namespace simple_shortcut



