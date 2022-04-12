#include "framework.h"
//#include "aura/application.h"


#define new ACME_NEW

namespace app_simple_shortcut
{


   application::application()
   {

      m_ptemplateBeatMapperMain  = NULL;
      m_ptemplateBeatMapperView  = NULL;

      m_strAppId                 = "app-simple/shortcut";
      m_strBaseSupportId         = "app-simple/shortcut";
      m_strAppName               = "Shortcut Amender";
      m_bLicense                 = false;

      m_bMultiverseChat          = true;

//auto test = new int;

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

      set_local_data();

      //puser->will_use_view_hint(FONTSEL_IMPACT);

      ::factory::add_factory_item <::app_simple_shortcut::document >();
      ::factory::add_factory_item <::app_simple_shortcut::frame >();
      ::factory::add_factory_item <::app_simple_shortcut::main_frame >();
      ::factory::add_factory_item <::user::button_view >();
      ::factory::add_factory_item <::app_simple_shortcut::impact >();
      ::factory::add_factory_item <::app_simple_shortcut::main_impact >();
      ::factory::add_factory_item <::app_simple_shortcut::tab_view >();
      ::factory::add_factory_item <::app_simple_shortcut::form_001 >();
      ::factory::add_factory_item <::app_simple_shortcut::form_002 >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(tab_view)));
      m_ptemplateBeatMapperMain = pdoctemplate;
      add_document_template(pdoctemplate);


      pdoctemplate = __new(::user::single_document_template(
                          "main",
                          __type(document),
                          __type(frame),
                          __type(main_impact)));
      m_ptemplateBeatMapperView = pdoctemplate;
      add_document_template(pdoctemplate);




      //return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

//#if 1
      if (pcreate->m_pcommandline->has_property("m"))
      {

         //output_error_message("m=1");

         _001TryCloseApplication();

         return;

      }
//#endif
#if 0

#ifdef _DEBUG

      output_debug_string("_DEBUG build? (basis)");

      ASSERT(false);

#else

      output_debug_string("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      m_bMultiverseChat = !is_true("no_hello_edit");

      if (m_ptemplateBeatMapperMain->get_document_count() == 0)
      {

         m_ptemplateBeatMapperMain->do_request(pcreate);

      }

      if (pcreate->m_pcommandline->m_payloadFile.has_char())
      {

         m_ptemplateBeatMapperView->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->m_pcommandline->payload("document").cast < document >()->get_type_impact < ::user::tab_view >()->top_level_frame()->design_window_maximize();

      }

      output_debug_string("\nfinished simple_shortcut::on_request");

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
//::acme::library * app_simple_shortcut_get_new_library()
//{
//
//   return new ::apex::single_application_library < ::simple_shortcut::application >("app-simple/form");
//
//}
//
//
//aura_app aura_app_simple_shortcut("app-simple/form", &app_simple_shortcut_get_new_library);
//
//
