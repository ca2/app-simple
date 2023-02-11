#include "framework.h"
#include "application.h"
#include "frame.h"
#include "main_frame.h"
#include "document.h"
#include "tab_impact.h"
#include "main_impact.h"
#include "impact.h"
#include "form_001.h"
#include "form_002.h"
#include "acme/handler/request.h"
#include "aura/user/user/button.h"
#include "base/user/user/show.h"
#include "base/user/user/single_document_template.h"


////#define memory_new ACME_NEW
///IMPLEMENT_APPLICATION(app_simple_change_grub_default_entry)
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

      //set_local_data();

      factory()->add_factory_item <::app_simple_change_grub_default_entry::document >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::frame >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::main_frame >();
      factory()->add_factory_item <::user::button_impact >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::impact >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::main_impact >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::tab_impact >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::form_001 >();
      factory()->add_factory_item <::app_simple_change_grub_default_entry::form_002 >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                              "main",
                              __type(document),
                              __type(main_frame),
                              __type(form_001)
               ));

      m_ptemplateChangeGrubDefaultEntryMain = pdoctemplate;

      add_document_template(pdoctemplate);

      //return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

      if (m_ptemplateChangeGrubDefaultEntryMain->get_document_count() == 0)
      {

         prequest->m_bMakeVisible = false;

         m_ptemplateChangeGrubDefaultEntryMain->request(prequest);

      }

   }


   string application::preferred_experience()
   {
      
      return "tranquillum";
      
   }

   
} // namespace app_simple_change_grub_default_entry



