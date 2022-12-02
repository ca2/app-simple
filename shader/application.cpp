#include "framework.h"
#include "application.h"
#include "frame.h"
#include "main_frame.h"
#include "tab_impact.h"
#include "impact.h"
#include "document.h"
#include "acme/platform/request.h"
#include "base/user/user/single_document_template.h"


namespace app_simple_shader
{


   application::application()
   {
      
      m_bImaging = true;

      m_ptemplateSimpleShaderMain = nullptr;

      m_ptabimpact = nullptr;

      m_strAppId = "app-simple/shader";

      m_strBaseSupportId = "app-simple/shader";

      m_strAppName = "Simple Shader";

      m_bLicense = false;

      m_strMainTitle = "Simple Drawing";

   }


   application::~application()
   {

   }




   //string application::get_hover_font() const
   //{

   //   return "Helvetica";

   //}


   void application::init_instance()
   {

      set_local_data();

      //puser->will_use_impact_hint(FONTSEL_IMPACT);

      factory()->add_factory_item <::app_simple_shader::document >();
      factory()->add_factory_item <::app_simple_shader::frame >();
      factory()->add_factory_item <::app_simple_shader::main_frame >();
      //factory()->add_factory_item <::user::button_impact >();
      factory()->add_factory_item <::app_simple_shader::impact >();
      factory()->add_factory_item <::app_simple_shader::tab_impact >();

      default_toggle_check_handling("simple_checkbox");

      default_toggle_check_handling("no_client_frame");

      ::aura::application::init_instance();

      //if (!::aura::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(tab_impact)));

      add_document_template(pdoctemplate);

      m_ptemplateSimpleShaderMain = pdoctemplate;

      //return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::request * prequest)
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

      if (m_ptemplateSimpleShaderMain->get_document_count() == 0)
      {

         if(pcreate->m_bMakeVisible)
         {

            INFORMATION("pcreate->m_bMakeVisible");

         }
         else
         {

            INFORMATION("NOT pcreate->m_bMakeVisible");

         }

         m_ptemplateSimpleShaderMain->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      output_debug_string("\nfinished simple_shader::on_request");

   }


   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


//#ifdef _DEBUG
//
//
//   int64_t application::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
//   {
//
//      return ::object::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);
//
//   }
//
//
//   int64_t application::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
//   {
//
//      return ::object::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);
//
//   }
//
//
//#endif


   ::pointer<impact> application::create_simple_shader_impact(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_impact < impact >(pimpactdata);

   }


   ::atom application::translate_property_id(const ::atom & atom)
   {

      return atom;

      //if(atom == "simple_checkbox")
      //{

      //   return id_simple_checkbox;

      //}
      //else if(atom == "simple_text")
      //{

      //   return id_simple_text;

      //}

      //return atom;

   }



} // namespace simple_shader



