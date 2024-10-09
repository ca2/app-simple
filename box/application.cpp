#include "framework.h"
#include "application.h"
#include "document.h"
#include "main_frame.h"
#include "impact.h"
#include "base/user/user/single_document_template.h"


__IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_box);


namespace app_simple_box
{


   // __IMPLEMENT_APPLICATION_RELEASE_TIME1(app_simple_box));


   application::application()
   {
      
      m_bImaging = false;
      //m_ptemplateAppSimpleBoxMain = nullptr;
      
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

      add_impact_system(
         "main", ::as(new ::user::single_document_template(
         "main",
         ::type < document >(),
         ::type < main_frame >(),
         ::type < impact >())));

      //m_ptemplateAppSimpleBoxMain = pdoctemplate;

      //add_document_template(pdoctemplate);
      //default_data_save_handling(m_checkSimple);

      //default_data_save_handling(m_checkNoClientFrame);

      //default_data_save_handling(m_textSimple);


      //return true;

   }




   void application::on_request(::request * prequest)
   {

      m_strAppName = "Simple Message Box!!";

      if (impact_system("main")->get_document_count() <= 0)
      {

         impact_system("main")->request(prequest);

      }

   }


} // namespace app_simple_box



