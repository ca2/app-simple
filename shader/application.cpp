#include "framework.h"
#include "aura/update.h"


namespace simple_shader
{


   application::application()
   {
      
      m_bImaging = true;

      m_ptemplateSimpleShaderMain = nullptr;

      m_ptabview = nullptr;

      m_strAppId = "app-simple/shader";

      m_strAppName = "app-simple/shader";

      m_strBaseSupportId = "app-simple/shader";

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


   ::e_status application::init_instance()
   {

      set_local_data();

      //puser->will_use_view_hint(FONTSEL_IMPACT);

      create_factory <::simple_shader::document >();
      create_factory <::simple_shader::frame >();
      create_factory <::simple_shader::main_frame >();
      create_factory <::user::button_view >();
      create_factory <::simple_shader::view >();
      create_factory <::simple_shader::tab_view >();

      default_toggle_check_handling(id_simple_checkbox);

      default_toggle_check_handling(id_no_client_frame);

      if (!::aura::application::init_instance())
      {

         return false;

      }

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(tab_view)));

      m_ptemplateSimpleShaderMain = pdoctemplate;

      auto puser = user();

      puser->document_manager()->add_document_template(pdoctemplate);

      return true;

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

            INFO("pcreate->m_bMakeVisible");

         }
         else
         {

            INFO("NOT pcreate->m_bMakeVisible");

         }

         m_ptemplateSimpleShaderMain->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->m_pcommandline->m_varQuery["document"].cast < document >()->get_typed_view < ::user::tab_view >()->top_level_frame()->sketch_prepare_window_maximize();

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
//   int64_t application::add_ref(OBJ_REF_DBG_PARAMS_DEF)
//   {
//
//      return ::object::add_ref(OBJ_REF_DBG_ARGS);
//
//   }
//
//
//   int64_t application::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
//   {
//
//      return ::object::dec_ref(OBJ_REF_DBG_ARGS);
//
//   }
//
//
//#endif


   __pointer(view) application::create_simple_shader_view(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_view < view >(pimpactdata);

   }


   ::id application::translate_property_id(const ::id & id)
   {

      if(id == "simple_checkbox")
      {

         return id_simple_checkbox;

      }
      else if(id == "simple_text")
      {

         return id_simple_text;

      }

      return id;

   }



} // namespace simple_shader



