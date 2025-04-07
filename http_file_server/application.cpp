#include "framework.h"
#include "application.h"
#include "document.h"
#include "edit_impact.h"
#include "main_impact.h"
#include "frame.h"
#include "main_frame.h"
#include "main_document.h"
#include "impact.h"
#include "tab_impact.h"
#include "incoming_socket.h"
#include "incoming_socket_thread.h"
#include "socket.h"
#include "acme/handler/request.h"
#include "base/user/user/multiple_document_template.h"
#include "base/user/user/single_document_template.h"


__IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_http_file_server);
IMPLEMENT_APPLICATION_FACTORY(app_simple_http_file_server);


namespace app_simple_http_file_server
{


   // __IMPLEMENT_APPLICATION_RELEASE_TIME1(app_simple_http_file_server));


   application::application()
   {

      //m_ptemplateSimpleDrawingMain = nullptr;

      m_ptabimpact = nullptr;

      m_strAppId = "app-simple/http";

      m_strBaseSupportId = "ca2_flag";

      m_strAppName = "Networking Application";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   ::type_atom application::get_pane_impact_type() const
   {

      return ::type < tab_impact >();

   }


   void application::init_instance()
   {

      factory()->add_factory_item <::app_simple_http_file_server::document >();
      factory()->add_factory_item <::app_simple_http_file_server::frame >();
      factory()->add_factory_item <::app_simple_http_file_server::main_frame >();
      factory()->add_factory_item <::app_simple_http_file_server::tab_impact >();
      factory()->add_factory_item <::app_simple_http_file_server::main_document >();
      factory()->add_factory_item <::app_simple_http_file_server::edit_impact >();
      factory()->add_factory_item <::app_simple_http_file_server::main_impact >();

      factory()->add_factory_item <::app_simple_http_file_server::document >();
      factory()->add_factory_item <::app_simple_http_file_server::impact >();

      factory()->add_factory_item <::app_simple_http_file_server::incoming_socket >();
      factory()->add_factory_item <::app_simple_http_file_server::socket >();

      //default_toggle_check_handling("simple_checkbox");

      //default_toggle_check_handling("no_client_frame");

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}
      add_impact_system("main", __initialize_new ::user::single_document_template(
                               "main",
                               ::type < ::app_simple_http_file_server::main_document >(),
                               ::type < ::app_simple_http_file_server::main_frame >(),
                               get_pane_impact_type()));

      //m_ptemplateSimpleDrawingMain = pdoctemplate;

      //add_document_template(pdoctemplate);

      //add_impact_system("impact", __initialize_new ::user::multiple_document_template(
      //   "command",
      //   ::type < main_document >(),
      //   ::type < main_frame >(),
      //   ::type < impact >()));

      //m_ptemplateCommand = pdoctemplate2;

      //add_document_template(pdoctemplate2);

      //default_data_save_handling("simple_checkbox");

      //default_data_save_handling("no_client_frame");

      //default_data_save_handling("simple_text");

      __defer_construct_new(m_pincomingsocketthread);

      //return true;

   }


   void application::term_application()
   {

      ::base::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

#if 0

#ifdef _DEBUG

      informationf("_DEBUG build? (basis)");

      ASSERT(false);

#else

      informationf("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      if (impact_system("main")->get_document_count() == 0)
      {

         if(prequest->m_egraphicsoutputpurpose & ::graphics::e_output_purpose_screen)
         {

            information() << "pcreate->m_bMakeVisible";

         }
         else
         {

            information() << "NOT pcreate->m_bMakeVisible";

         }

         impact_system("main")->request(prequest);

         return;

      }

      if (is_true("wfi_maximize"))
      {

         prequest->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }


      //if (prequest->has_file())
      //{

      //   m_ptabimpact->add_tab(prequest->m_payloadFile.as_file_path().name(), prequest->m_payloadFile.as_file_path());
      //   m_ptabimpact->set_current_tab_by_id(prequest->m_payloadFile.as_file_path());

      //}

      informationf("\nfinished simple_webserver::on_request");

   }


   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


#ifdef _DEBUG


   long long application::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long application::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   //::pointer<impact> application::create_simple_drawing_impact(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   //{

   //   return pimpactParent->create_impact < impact >(pimpactdata);

   //}


} // namespace app_simple_http_file_server



