#include "framework.h"


#define new ACME_NEW

namespace simple_change_grub_default_entry
{


   application::application()
   {

      m_ptemplateBeatMapperMain  = NULL;
      //m_ptemplateBeatMapperView  = NULL;

      m_strAppId                 = "app-simple/change_grub_default_entry";
      m_strAppName               = "app-simple/change_grub_default_entry";
      m_strBaseSupportId         = "app-simple/change_grub_default_entry";
      m_bLicense                 = false;

      m_bMultiverseChat          = true;

//auto test = new int;

   }


   application::~application()
   {
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


   ::e_status application::init_instance()
   {

      set_local_data();

      //puser->will_use_view_hint(FONTSEL_IMPACT);

      create_factory <::simple_change_grub_default_entry::document >();
      create_factory <::simple_change_grub_default_entry::frame >();
      create_factory <::simple_change_grub_default_entry::main_frame >();
      create_factory <::user::button_view >();
      create_factory <::simple_change_grub_default_entry::view >();
      create_factory <::simple_change_grub_default_entry::main_view >();
      create_factory <::simple_change_grub_default_entry::tab_view >();
      create_factory <::simple_change_grub_default_entry::simple_change_grub_default_entry_001 >();
      create_factory <::simple_change_grub_default_entry::simple_change_grub_default_entry_002 >();

      if (!::base::application::init_instance())
      {

         return false;

      }

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               //__type(tab_view))
         __type(simple_change_grub_default_entry_001)
         ));
      m_ptemplateBeatMapperMain = pdoctemplate;
      add_document_template(pdoctemplate);


      //pdoctemplate = __new(::user::single_document_template(
      //                    "main",
      //                    __type(document),
      //                    __type(frame),
      //                    __type(main_view)));
      //m_ptemplateBeatMapperView = pdoctemplate;
      //add_document_template(pdoctemplate);




      return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

//#if 1
      if (pcreate->m_pcommandline->m_varQuery.has_property("m"))
      {

         message_box("m=1");

         finish();

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

         pcreate->m_bMakeVisible = false;

         m_ptemplateBeatMapperMain->do_request(pcreate);

      }

      //if (pcreate->m_pcommandline->m_varFile.has_char())
      //{

      //   m_ptemplateBeatMapperView->do_request(pcreate);

      //}

      if (is_true("wfi_maximize"))
      {

         pcreate->m_pcommandline->m_varQuery["document"].cast < document >()->get_typed_view < ::user::tab_view >()->top_level_frame()->sketch_prepare_window_maximize();

      }

      output_debug_string("\nfinished simple_change_grub_default_entry::on_request");

   }


   string application::preferred_experience()
   {
      
      return "tranquillum";
      
      //return "core";

//      return "tranquillum";

   }



   
} // namespace simple_change_grub_default_entry


//
//extern "C"
//::acme::library * app_simple_change_grub_default_entry_get_new_library()
//{
//
//   return new ::apex::single_application_library < ::simple_change_grub_default_entry::application >("app-simple/form");
//
//}
//
//
//aura_app aura_app_simple_change_grub_default_entry("app-simple/form", &app_simple_change_grub_default_entry_get_new_library);
//
//
