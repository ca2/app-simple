#include "framework.h"
#include "application.h"
#include "document.h"
#include "form_001.h"
#include "form_002.h"
#include "frame.h"
#include "main_frame.h"
#include "tab_impact.h"
#include "main_impact.h"
#include "impact.h"
#include "acme/handler/request.h"
#include "aura/user/user/button.h"
#include "base/user/user/single_document_template.h"


__IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_form);
IMPLEMENT_APPLICATION_FACTORY(app_simple_form);


namespace app_simple_form
{


   // __IMPLEMENT_APPLICATION_RELEASE_TIME1(app_simple_form));


   application::application()
   {

      //m_ptemplateBeatMapperMain  = NULL;
      //m_ptemplateBeatMapperImpact  = NULL;

      m_strAppId                 = "app-simple/form";
      m_strBaseSupportId         = "app-simple/form";
      m_strAppName               = "Simple Form";
      m_bLicense                 = false;
      m_bNetworking              = false;
      //m_bMultiverseChat          = true;

   }


   application::~application()
   {
      
   }


#ifdef _DEBUG


   long long application::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long application::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void application::init_instance()
   {

      //set_local_data();

      factory()->add_factory_item <::app_simple_form::document >();
      factory()->add_factory_item <::app_simple_form::frame >();
      factory()->add_factory_item <::app_simple_form::main_frame >();
      factory()->add_factory_item <::user::button_impact >();
      factory()->add_factory_item <::app_simple_form::impact >();
      factory()->add_factory_item <::app_simple_form::main_impact >();
      factory()->add_factory_item <::app_simple_form::tab_impact >();
      factory()->add_factory_item <::app_simple_form::form_001 >();
      factory()->add_factory_item <::app_simple_form::form_002 >();

      ::base::application::init_instance();
      add_impact_system("main", __initialize_new ::user::single_document_template(
                               "main",
                               ::type < document >(),
                               ::type < main_frame >(),
                               ::type < tab_impact >()));

      //m_ptemplateAppSimpleFormMain = pdoctemplate;

      //add_document_template(pdoctemplate);

      add_impact_system(
         "impact", __initialize_new ::user::single_document_template(
                          "main",
                          ::type < document >(),
                          ::type < frame >(),
                          ::type < main_impact >()));

      //m_ptemplateAppSimpleFormImpact = pdoctemplate;

      //add_document_template(pdoctemplate);

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

//#if 1
      if (prequest->has_property("m"))
      {

         //output_error_message("m=1");

         _001TryCloseApplication();

         return;

      }
//#endif
#if 0

#ifdef _DEBUG

      informationf("_DEBUG build? (basis)");

      ASSERT(false);

#else

      informationf("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      //m_bMultiverseChat = !is_true("no_hello_edit");

      if (impact_system("main")->get_document_count() == 0)
      {

         impact_system("main")->request(prequest);

         return;

      }

      if (prequest->m_payloadFile.has_character())
      {

         impact_system("impact")->request(prequest);

      }

      if (is_true("wfi_maximize"))
      {

         prequest->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      informationf("finished simple_form::on_request");

   }


   string application::preferred_experience()
   {
      
      return "tranquillum";
      
      //return "core";

//      return "tranquillum";

   }



   
//   __namespace_application_factory("app-simple/form");


} // namespace simple_form


//
//extern "C"
//::acme::library * app_simple_form_get_new_library()
//{
//
//   return ___new ::apex::single_application_library < ::simple_form::application >("app-simple/form");
//
//}
//
//
//aura_app aura_app_simple_form("app-simple/form", &app_simple_form_get_new_library);
//
//
