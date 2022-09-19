#include "framework.h"

#include "application.h"
#include "document.h"
#include "frame.h"
#include "main_frame.h"
#include "impact.h"
#include "tab_impact.h"
#include "base/user/user/single_document_template.h"


//IMPLEMENT_APPLICATION(app_simple_networking_application);


namespace app_simple_networking_application
{


   application::application()
   {

      m_ptemplateSimpleDrawingMain = nullptr;

      m_ptabimpact = nullptr;

      m_strAppId = "app-simple/networking_application";

      m_strBaseSupportId = "ca2_flag";

      m_strAppName = "Networking Application";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   void application::create_networking_application()
   {

      //auto estatus = 
      
      ::base::application::create_networking_application();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   ::type application::get_pane_impact_type() const
   {

      return __type(tab_impact);

   }


 /*  string application::get_hover_font() const
   {

      return "Helvetica";

   }*/


   void application::init_instance()
   {

      set_local_data();

      ::factory::add_factory_item <::app_simple_networking_application::document >();
      ::factory::add_factory_item <::app_simple_networking_application::frame >();
      ::factory::add_factory_item <::app_simple_networking_application::main_frame >();
      ::factory::add_factory_item <::app_simple_networking_application::impact >();
      ::factory::add_factory_item <::app_simple_networking_application::tab_impact >();

      default_toggle_check_handling("simple_checkbox");

      default_toggle_check_handling("no_client_frame");

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               get_pane_impact_type()));

      m_ptemplateSimpleDrawingMain = pdoctemplate;

      add_document_template(pdoctemplate);

      default_data_save_handling("simple_checkbox");

      default_data_save_handling("no_client_frame");

      default_data_save_handling("simple_text");

      //return true;

   }


   void application::term_application()
   {

      ::base::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

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

      if (is_true("wfi_maximize"))
      {

         pcreate->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      output_debug_string("\nfinished simple_webserver::on_request");

   }


   string application::preferred_experience()
   {

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


   __pointer(impact) application::create_simple_drawing_impact(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_impact < impact >(pimpactdata);

   }


} // namespace app_simple_networking_application



