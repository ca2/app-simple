#include "framework.h"
#include "application.h"
#include "document.h"
#include "main_frame.h"
#include "impact.h"
#include "base/user/user/single_document_template.h"

//IMPLEMENT_APPLICATION(app_simple_box)
namespace app_simple_box
{


   application::application()
   {
      
      m_bImaging = false;
      m_ptemplateAppSimpleBoxMain = nullptr;
      
      //m_bWriteText = false;
      
      m_strAppId = "app-simple/box";

      m_strAppName = "app-simple/box";

      m_strBaseSupportId = "app_simple_box";

   }


   application::~application()
   {


   }


   void application::init_instance()
   {

      //set_local_data();

      factory()->add_factory_item <::app_simple_box::document >();
      factory()->add_factory_item <::app_simple_box::main_frame >();
      factory()->add_factory_item <::app_simple_box::impact >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
         "main",
         ::type < document >(),
         ::type < main_frame >(),
         ::type < impact >()));

      m_ptemplateAppSimpleBoxMain = pdoctemplate;

      add_document_template(pdoctemplate);

      default_data_save_handling("simple_checkbox");

      default_data_save_handling("no_client_frame");

      default_data_save_handling("simple_text");

      //return true;

   }




   void application::on_request(::request * prequest)
   {

      m_strAppName = "Simple Message Box!!";

      if (m_ptemplateAppSimpleBoxMain->get_document_count() <= 0)
      {

         m_ptemplateAppSimpleBoxMain->request(prequest);

      }

   }


} // namespace app_simple_box



