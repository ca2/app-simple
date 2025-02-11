#pragma once


#include "base/platform/application.h"


namespace app_simple_form
{


   class CLASS_DECL_APP_SIMPLE_FORM application :
      virtual public ::base::application
   {
   public:


//      bool                                   m_bMultiverseChat;
//
//      ::user::document *                     m_pdocMenu;
//      ::user::plain_edit_impact *            m_prollfps;
      //::pointer < ::user::single_document_template >        m_ptemplateAppSimpleFormMain;
      //::pointer < ::user::single_document_template >        m_ptemplateAppSimpleFormImpact;


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


} // namespace simple_form



