#include "framework.h"
#include "application.h"
#include "main_frame.h"
#include "document.h"
#include "impact.h"
#include "acme/handler/request.h"
#include "base/user/user/tab_impact.h"
#include "base/platform/session.h"
#include "base/user/user/document_manager.h"
#include "base/user/user/user.h"
#include "base/user/user/single_document_template.h"


__DECLARE_RELEASE_TIME(app_simple_application);


namespace app_simple_application
{


   __IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_application);


   application::application()
   {

      m_bImaging = false;

      m_bNetworking = false;

      m_ppaneimpact = nullptr;

      m_strAppId = "app-simple/application";

      m_strAppName = "app-simple/application";

      m_strBaseSupportId = "app_simple_application";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   void application::init_instance()
   {

      factory()->add_factory_item <::app_simple_application::document >();
      factory()->add_factory_item <::app_simple_application::main_frame >();
      factory()->add_factory_item <::app_simple_application::impact >();

      ::base::application::init_instance();

      auto pdoctemplate = __allocate < ::user::single_document_template >(
                               "main",
                               ::type < document >(),
                               ::type < main_frame >(),
                               ::type < impact >()));

      __construct(m_ptemplateSimpleDrawingMain, pdoctemplate);

      auto psession = get_session();

      auto puser = psession->baseuser();

      puser->document_manager()->add_document_template(pdoctemplate);

   }


   void application::term_application()
   {

      ::base::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

      if (m_ptemplateSimpleDrawingMain->get_document_count() == 0)
      {

         if(prequest->m_egraphicsoutputpurpose & ::graphics::e_output_purpose_screen)
         {

            information() << "::graphics::e_output_purpose_screen";

         }
         else
         {

            information() << "NOT ::graphics::e_output_purpose_screen";

         }

         m_ptemplateSimpleDrawingMain->request(prequest);

      }

      if (is_true("wfi_maximize"))
      {

         prequest->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      informationf("finished simple_application::on_request");

   }


   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


#ifdef _DEBUG


   int64_t application::increment_reference_count(REFERENCING_DEBUGGING_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(REFERENCING_DEBUGGING_ARGS);

   }


   int64_t application::decrement_reference_count(REFERENCING_DEBUGGING_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(REFERENCING_DEBUGGING_ARGS);

   }


#endif


} // namespace app_simple_application



