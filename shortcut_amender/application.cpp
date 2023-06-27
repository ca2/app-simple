#include "framework.h"
#include "application.h"
#include "frame.h"
#include "main_frame.h"
#include "form_amender.h"
#include "form_reset_icon.h"
#include "form_set_icon.h"
#include "impact.h"
#include "document.h"
#include "tab_impact.h"
#include "main_impact.h"
#include "acme/handler/request.h"
#include "aura/user/user/button.h"
#include "base/user/user/show.h"
#include "base/user/user/single_document_template.h"


////#define memory_new ACME_NEW
//IMPLEMENT_APPLICATION(app_simple_shortcut_amender)

namespace app_simple_shortcut_amender
{


   application::application()
   {

      m_ptemplateShortcutAmenderMain  = NULL;
      m_ptemplateShortcutAmenderImpact  = NULL;

      m_strAppId                 = "app-simple/shortcut_amender";
      m_strBaseSupportId         = "app-simple/shortcut_amender";
      m_strAppName               = "Shortcut Amender";
      m_bLicense                 = false;


   }


   application::~application()
   {
   }


#ifdef _DEBUG


   int64_t application::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t application::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void application::init_instance()
   {

      //set_local_data();

      //puser->will_use_impact_hint(FONTSEL_IMPACT);

      factory()->add_factory_item <::app_simple_shortcut_amender::document >();
      factory()->add_factory_item <::app_simple_shortcut_amender::frame >();
      factory()->add_factory_item <::app_simple_shortcut_amender::main_frame >();
      factory()->add_factory_item <::user::button_impact >();
      factory()->add_factory_item <::app_simple_shortcut_amender::impact >();
      factory()->add_factory_item <::app_simple_shortcut_amender::main_impact >();
      factory()->add_factory_item <::app_simple_shortcut_amender::tab_impact >();
      factory()->add_factory_item <::app_simple_shortcut_amender::form_amender >();
      factory()->add_factory_item <::app_simple_shortcut_amender::form_reset_icon >();
      factory()->add_factory_item <::app_simple_shortcut_amender::form_set_icon >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(tab_impact)));
      m_ptemplateShortcutAmenderMain = pdoctemplate;
      add_document_template(pdoctemplate);


      pdoctemplate = __new(::user::single_document_template(
                          "main",
                          __type(document),
                          __type(frame),
                          __type(main_impact)));
      m_ptemplateShortcutAmenderImpact = pdoctemplate;
      add_document_template(pdoctemplate);




      //return true;

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

      information("_DEBUG build? (basis)");

      ASSERT(false);

#else

      information("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      if (m_ptemplateShortcutAmenderMain->get_document_count() == 0)
      {

         m_ptemplateShortcutAmenderMain->request(prequest);

      }

      if (prequest->m_payloadFile.has_char())
      {

         m_ptemplateShortcutAmenderImpact->request(prequest);

      }

      if (is_true("wfi_maximize"))
      {

         prequest->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      information("\nfinished simple_shortcut::on_request");

   }


   string application::preferred_experience()
   {
      
      return "tranquillum";
      
      //return "core";

//      return "tranquillum";

   }



   
//   __namespace_application_factory("app-simple/form");


} // namespace simple_shortcut


//
//extern "C"
//::acme::library * app_simple_shortcut_amender_get_new_library()
//{
//
//   return memory_new ::apex::single_application_library < ::simple_shortcut::application >("app-simple/form");
//
//}
//
//
//aura_app aura_app_simple_shortcut_amender("app-simple/form", &app_simple_shortcut_amender_get_new_library);
//
//
