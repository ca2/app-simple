#include "framework.h"
#include "base/user/user/_user.h"
#include "aura/update.h"


namespace simple_application
{


   application::application()
   {

      //m_bLocalization = true;
      
      m_bImaging = false;

      m_ppaneview = nullptr;

      m_strAppId = "app-simple/application";

      m_strAppName = "app-simple/application";

      m_strBaseSupportId = "app_simple_application";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   ::e_status application::init_instance()
   {

      set_local_data();

      create_factory <::simple_application::document >();
      create_factory <::simple_application::main_frame >();
      create_factory <::simple_application::view >();

      if (!::aura::application::init_instance())
      {

         return false;

      }

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               __type(view)));

      __compose(m_ptemplateSimpleDrawingMain, pdoctemplate);

      auto psession = get_session();

      auto puser = psession->user();

      puser->document_manager()->add_document_template(pdoctemplate);

      return true;

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

            INFO("pcreate->m_bMakeVisible");

         }
         else
         {

            INFO("NOT pcreate->m_bMakeVisible");

         }

         m_ptemplateSimpleDrawingMain->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->m_pcommandline->m_varQuery["document"].cast < document >()->get_typed_view < ::user::tab_view >()->top_level_frame()->sketch_prepare_window_maximize();

      }

      output_debug_string("\nfinished simple_application::on_request");

   }


   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


#ifdef _DEBUG


   int64_t application::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t application::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


} // namespace simple_application



