#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif


namespace app_simple_notify_drawing
{


   application::application()
   {

      m_ptemplateNotifyDrawingMain = NULL;

      m_strAppId = "app-simple/notify_drawing";
      m_strBaseSupportId = "ca2_flag";
      m_strAppName = "Notify Drawing";
      m_bLicense = false;

   }


   application::~application()
   {
   }


   void application::init_instance()
   {

      set_local_data();

      ::factory::add_factory_item <::app_simple_notify_drawing::main_frame >();
      ::factory::add_factory_item <::app_simple_notify_drawing::impact >();

      ::app_simple_drawing::application::init_instance();

      //if (!::app_simple_drawing::application::init_instance())
      //{

      //   return false;

      //}

      add_matter_locator("app-simple/drawing");

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(app_simple_drawing::document),
                               __type(main_frame),
                               __type(app_simple_drawing::tab_view)));
      m_ptemplateNotifyDrawingMain = pdoctemplate;
      add_document_template(pdoctemplate);


//      pdoctemplate = __new(::user::single_document_template(
//                          this,
//                          "main",
//                          __type(simple_drawing::document),
//                          __type(simple_drawing::frame),
//                          __type(simple_drawing::main_impact)));
//
//      m_ptemplateNotifyDrawingView = pdoctemplate;
//
//      add_document_template(pdoctemplate);

      //return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

#if 0
      {

         auto pthread = fork([this]()
            {

               output_debug_string("test");

            });

      }
#endif

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

      if (m_ptemplateNotifyDrawingMain->get_document_count() == 0)
      {

         m_ptemplateNotifyDrawingMain->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->payload("document").cast < app_simple_drawing::document >()->get_type_impact < ::user::tab_view >()->top_level_frame()->design_window_maximize();

      }

      output_debug_string("\nfinished notify_drawing::on_request");

   }


   string application::preferred_experience()
   {

      //return "aura";

      return ::aura::application::preferred_experience();

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


   __pointer(app_simple_drawing::impact) application::create_simple_drawing_view(::user::impact* pimpactParent, ::user::impact_data* pimpactdata)
   {

      return pimpactParent->create_view < impact >(pimpactdata);

   }

   
} // namespace notify_drawing



