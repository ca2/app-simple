#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif


#define new ACME_NEW

namespace app_simple_change_grub_default_entry
{


   application::application()
   {


      m_ptemplateChangeGrubDefaultEntryMain  = NULL;

      m_strAppId                 = "app-simple/change_grub_default_entry";
      m_strAppName               = "Change GRUB default entry";
      m_strBaseSupportId         = "app-simple/change_grub_default_entry";
      m_bLicense                 = false;

   }


   application::~application()
   {


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


   void application::init_instance()
   {

      set_local_data();

      ::factory::add_factory_item <::app_simple_change_grub_default_entry::document >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::frame >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::main_frame >();
      ::factory::add_factory_item <::user::button_view >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::impact >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::main_impact >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::tab_view >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::simple_change_grub_default_entry_001 >();
      ::factory::add_factory_item <::app_simple_change_grub_default_entry::simple_change_grub_default_entry_002 >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                              "main",
                              __type(document),
                              __type(main_frame),
                              __type(simple_change_grub_default_entry_001)
               ));

      m_ptemplateChangeGrubDefaultEntryMain = pdoctemplate;

      add_document_template(pdoctemplate);

      //return true;

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

   
} // namespace app_simple_change_grub_default_entry



