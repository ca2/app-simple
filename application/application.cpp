#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif
#include "base/user/user/_component.h"
#include "aura/update.h"


namespace app_simple_application
{


   application::application()
   {

      //message_box_synchronous("Message", "Title", e_message_box_yes_no_cancel);

      //m_bLocalization = true;
      
      m_bImaging = false;

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

      set_local_data();

      ::factory::add_factory_item <::app_simple_application::document >();
      ::factory::add_factory_item <::app_simple_application::main_frame >();
      ::factory::add_factory_item <::app_simple_application::impact >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(impact)));

      __compose(m_ptemplateSimpleDrawingMain, pdoctemplate);

      auto psession = get_session();

      auto puser = psession->user();

      puser->document_manager()->add_document_template(pdoctemplate);

      //return true;

   }


   void application::term_application()
   {

      ::base::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

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

         pcreate->payload("document").cast < document >()->get_type_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      output_debug_string("\nfinished simple_application::on_request");

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


} // namespace simple_application



