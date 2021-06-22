#include "framework.h"


#define new ACME_NEW

namespace simple_change_grub_default_entry
{


   application::application()
   {


      m_ptemplateChangeGrubDefaultEntryMain  = NULL;

      m_strAppId                 = "app-simple/change_grub_default_entry";
      m_strAppName               = "app-simple/change_grub_default_entry";
      m_strBaseSupportId         = "app-simple/change_grub_default_entry";
      m_bLicense                 = false;

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
                              __type(simple_change_grub_default_entry_001)
               ));

      m_ptemplateChangeGrubDefaultEntryMain = pdoctemplate;

      add_document_template(pdoctemplate);

      return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

      if (m_ptemplateChangeGrubDefaultEntryMain->get_document_count() == 0)
      {

         pcreate->m_bMakeVisible = false;

         m_ptemplateChangeGrubDefaultEntryMain->do_request(pcreate);

      }

   }


   string application::preferred_experience()
   {
      
      return "tranquillum";
      
   }

   
} // namespace simple_change_grub_default_entry



