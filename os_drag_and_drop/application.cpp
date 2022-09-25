#include "framework.h"
#include "application.h"
#include "base/user/user/single_document_template.h"
#include "aura/user/user/button.h"


IMPLEMENT_APPLICATION(simple_os_drag_and_drop)
namespace simple_os_drag_and_drop
{


   application::application()
   {

      m_ptemplateSimpleDrawingMain = NULL;
      m_ptemplateSimpleDrawingImpact = NULL;

      m_strAppId = "app-simple/drag_and_drop";
      m_strBaseSupportId = "ca2_flag";
      m_strAppName = "Simple Drag and Drop";
      m_bLicense = false;

   }


   application::~application()
   {
   }


   void application::init_instance()
   {

      set_local_data();

      //puser->will_use_impact_hint(FONTSEL_IMPACT);
      
      ::factory::add_factory_item <::simple_os_drag_and_drop::document >();
      ::factory::add_factory_item <::simple_os_drag_and_drop::frame >();
      ::factory::add_factory_item <::simple_os_drag_and_drop::main_frame >();
      ::factory::add_factory_item <::user::button_impact >();
      ::factory::add_factory_item <::simple_os_drag_and_drop::impact >();
      ::factory::add_factory_item <::simple_os_drag_and_drop::main_impact >();
      ::factory::add_factory_item <::simple_os_drag_and_drop::tab_impact >();

      ::aura::application::init_instance();

      //if (!::aura::application::init_instance())
      //{

      //   return false;

      //}

      add_matter_locator("app-simple/drawing");

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(tab_impact)));

      m_ptemplateSimpleDrawingMain = pdoctemplate;
      add_document_template(pdoctemplate);


      pdoctemplate = __new(::user::single_document_template(
                          "main",
                          __type(document),
                          __type(frame),
                          __type(main_impact)));

      m_ptemplateSimpleDrawingImpact = pdoctemplate;
      add_document_template(pdoctemplate);

      //return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

//      {
//
//         auto pthread = fork([this]()
//            {
//
//               output_debug_string("test");
//
//            });
//
//      }

#if 0

#ifdef _DEBUG

      output_debug_string("_DEBUG build? (basis)");

      ASSERT(false);

#else

      output_debug_string("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      if (m_ptemplateSimpleDrawingMain->get_document_count() == 0)
      {

         if(pcreate->m_bMakeVisible)
         {

            INFORMATION("pcreate->m_bMakeVisible");

         }
         else
         {

            INFORMATION("NOT pcreate->m_bMakeVisible");

         }

         m_ptemplateSimpleDrawingMain->do_request(pcreate);

      }

      if (pcreate->m_payloadFile.has_char())
      {

         m_ptemplateSimpleDrawingImpact->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      output_debug_string("\nfinished simple_os_drag_and_drop::on_request");

   }


   string application::preferred_experience()
   {

      return "tranquillum";

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


   __pointer(impact) application::create_simple_os_drag_and_drop_impact(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_impact < impact >(pimpactdata);

   }

   
} // namespace simple_os_drag_and_drop



//
//extern "C"
//::acme::library * app_simple_drag_and_drop_get_new_library()
//{
//
//   return memory_new ::apex::single_application_library < ::simple_os_drag_and_drop::application >("app-simple/drag_and_drop");
//
//}
//
//
//aura_app aura_app_simple_drag_and_drop("app-simple/drag_and_drop", &app_simple_drag_and_drop_get_new_library);
//

