#include "framework.h"
#include "application.h"
#include "impact.h"
#include "frame.h"
#include "main_frame.h"
#include "document.h"
#include "tab_impact.h"
#include "acme/handler/request.h"
#include "acme/platform/system.h"
#include "aura/user/user/button.h"
#include "base/user/user/show.h"
#include "base/user/user/single_document_template.h"


__IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_drawing);


namespace app_simple_drawing
{


   application::application() :
      m_checkSimple(this, "simple_checkbox"),
      m_checkNoClientFrame(this, "no_client_frame"),
      m_textSimple(this, "simple_text"),
      m_textMainTitle(this, "main_title")
   {

      m_ptabimpact = nullptr;

      m_strAppId = "app-simple/drawing";

      m_strDatabaseAppId = "app-simple/drawing";

      m_strBaseSupportId = "ca2_flag";

      m_strAppName = "Simple Drawing";

      m_bLicense = false;

      m_bNetworking = false;

      m_bMultiverseChat = true;

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

      m_textAppTitle = __text("text://app-simple/drawing/app_simple_drawing/Simple Drawing");

      m_textMainTitle = { "Simple Drawing", ::e_source_sync };

      //set_local_data();

      factory()->add_factory_item <::app_simple_drawing::document >();
      factory()->add_factory_item <::app_simple_drawing::frame >();
      factory()->add_factory_item <::app_simple_drawing::main_frame >();
      factory()->add_factory_item <::user::button_impact >();
      factory()->add_factory_item <::app_simple_drawing::impact >();
      factory()->add_factory_item <::app_simple_drawing::tab_impact >();

      //default_save_handling(m_checkSimple);

      //default_save_handling(m_checkNoClientFrame);

      ::base::application::init_instance();

      add_impact_system(
         "main", ::place(new ::user::single_document_template(
                               "main",
                               ::type < document >(),
                               ::type < main_frame >(),
                               get_pane_impact_type())));

      //m_ptemplateSimpleDrawingMain = pdoctemplate;

      //add_document_template(pdoctemplate);

      default_data_save_handling(m_checkSimple);

      default_data_save_handling(m_checkNoClientFrame);

      default_data_save_handling(m_textSimple);

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

      m_bMultiverseChat = !is_true("no_hello_edit");

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

      }

      if (is_true("wfi_maximize"))
      {

         prequest->payload("document").cast < document >()->get_typed_impact < ::user::tab_impact >()->top_level_frame()->design_window_maximize();

      }

      informationf("\nfinished simple_drawing::on_request");

   }


   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


#ifdef _DEBUG

   int xxx = 0;

   int64_t application::increment_reference_count()
   {
      xxx++;

      return ::object::increment_reference_count();

   }


   int64_t application::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   ::pointer<impact> application::create_simple_drawing_impact(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_impact < impact >(pimpactdata);

   }


//   ::atom application::translate_property_id(const ::atom & atom)
//   {
//      
//      return atom;
//
////      if(atom == "simple_checkbox")
////      {
////
////         return id_simple_checkbox;
////
////      }
////      else if(atom == "simple_text")
////      {
////
////         return id_simple_text;
////
////      }
////      else if (atom == "no_client_frame")
////      {
////
////         return id_no_client_frame;
////
////      }
////
////      return atom;
//
//   }

   
   string application::draw2d_get_default_implementation_name()
   {

      //return system()->implementation_name("draw2d", "opengl");

      return {};

   }



} // namespace simple_drawing



