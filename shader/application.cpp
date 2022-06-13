#include "framework.h"
#include "aura/update.h"


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

      //puser->will_use_view_hint(FONTSEL_IMPACT);

      ::factory::add_factory_item <::app_simple_shader::document >();
      ::factory::add_factory_item <::app_simple_shader::frame >();
      ::factory::add_factory_item <::app_simple_shader::main_frame >();
      ::factory::add_factory_item <::user::button_view >();
      ::factory::add_factory_item <::app_simple_shader::impact >();
      ::factory::add_factory_item <::app_simple_shader::tab_view >();

      default_toggle_check_handling(id_simple_checkbox);

      default_toggle_check_handling(id_no_client_frame);

      ::aura::application::init_instance();

      //if (!::aura::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(tab_view)));

      add_document_template(pdoctemplate);

      m_ptemplateSimpleShaderMain = pdoctemplate;

      //return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

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

         pcreate->payload("document").cast < document >()->get_type_impact < ::user::tab_view >()->top_level_frame()->design_window_maximize();

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


   __pointer(impact) application::create_simple_shader_view(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_view < impact >(pimpactdata);

   }


   ::atom application::translate_property_id(const ::atom & atom)
   {

      if(atom == "simple_checkbox")
      {

         return id_simple_checkbox;

      }
      else if(atom == "simple_text")
      {

         return id_simple_text;

      }

      return atom;

   }



} // namespace simple_shader



