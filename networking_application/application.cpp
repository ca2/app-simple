#include "framework.h"
//#define _APP_ID "app-simple/webserver"
//#include "aura/application.h"
//#include "aura/update.h"
//#include "_webserver.h"



namespace app_simple_networking_application
{


   application::application()
   {

      m_ptemplateSimpleDrawingMain = nullptr;

      m_ptabview = nullptr;

      m_strAppId = "app-simple/networking_application";

      m_strAppName = "app-simple/networking_application";

      m_strBaseSupportId = "ca2_flag";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   ::e_status application::create_networking_application()
   {

      auto estatus = ::base::application::create_networking_application();

      if (!estatus)
      {

         return estatus;

      }

      return estatus;

   }


   ::type application::get_pane_view_type() const
   {

      return __type(tab_view);

   }


 /*  string application::get_hover_font() const
   {

      return "Helvetica";

   }*/


   ::e_status application::init_instance()
   {

      set_local_data();

      ::factory::add_factory_item <::app_simple_networking_application::document >();
      ::factory::add_factory_item <::app_simple_networking_application::frame >();
      ::factory::add_factory_item <::app_simple_networking_application::main_frame >();
      ::factory::add_factory_item <::app_simple_networking_application::impact >();
      ::factory::add_factory_item <::app_simple_networking_application::tab_view >();

      default_toggle_check_handling(id_simple_checkbox);

      default_toggle_check_handling(id_no_client_frame);

      if (!::base::application::init_instance())
      {

         return false;

      }

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               get_pane_view_type()));

      m_ptemplateSimpleDrawingMain = pdoctemplate;

      add_document_template(pdoctemplate);

      default_data_save_handling(id_simple_checkbox);

      default_data_save_handling(id_no_client_frame);

      default_data_save_handling(id_simple_text);

      return true;

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

         pcreate->m_pcommandline->m_varQuery["document"].cast < document >()->get_typed_view < ::user::tab_view >()->top_level_frame()->sketch_prepare_window_maximize();

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


   __pointer(impact) application::create_simple_drawing_view(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_view < impact >(pimpactdata);

   }


} // namespace app_simple_networking_application



