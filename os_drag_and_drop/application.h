#pragma once


#include "base/platform/application.h"


namespace app_simple_os_drag_and_drop
{


   class CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP application :
      virtual public ::base::application
   {
   public:


      ::user::document *                     m_pdocMenu;
      ::user::plain_edit_impact *              m_prollfps;
      ::user::single_document_template *     m_ptemplateSimpleDrawingMain;
      ::user::single_document_template *     m_ptemplateSimpleDrawingImpact;


      application();
      ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();


      virtual string preferred_experience() override;
      void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::request * prequest) override;

#ifdef _DEBUG
      virtual huge_integer increment_reference_count() override;
      virtual huge_integer decrement_reference_count() override;
#endif

      virtual ::pointer<impact> create_simple_os_drag_and_drop_impact(::user::impact * pimpactParent, ::user::impact_data * pimpactdata);

   };


} // namespace app_simple_os_drag_and_drop



