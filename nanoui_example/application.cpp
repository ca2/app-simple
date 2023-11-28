#include "framework.h"
#include "application.h"
#include "main_window.h"
#include "nanoui/Screen.h"


__DECLARE_RELEASE_TIME(app_simple_nanoui_example);


namespace app_simple_nanoui_example
{


   __IMPLEMENT_APPLICATION_RELEASE_TIME(app_simple_nanoui_example);


   application::application()
   {

      m_strAppId = "app-simple/nanoui_example";

      m_strAppName = "app-simple/nanoui_example";

      m_strBaseSupportId = "app_simple_nanoui_example";

      m_bNetworking = false;

      m_bLicense = false;

   }


   application::~application()
   {

   }


   void application::init_instance()
   {

      ::aura::application::init_instance();

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

      __construct_new(m_pmainwindow);

      m_pmainwindow->display(e_display_normal);

      m_pmainwindow->add_graphical_output_purpose(this, ::graphics::e_output_purpose_screen);

      m_pmainwindow->create_main_window(prequest);

//      m_pmainwindow->set_need_layout();
//
//      m_pmainwindow->set_need_redraw();
//
//      m_pmainwindow->post_redraw();

   }


   string application::preferred_experience()
   {

      return "nanoui";

   }


#ifdef _DEBUG


   int64_t application::increment_reference_count(REFERENCING_DEBUGGING_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(REFERENCING_DEBUGGING_ARGS);

   }


   int64_t application::decrement_reference_count(REFERENCING_DEBUGGING_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(REFERENCING_DEBUGGING_ARGS);

   }


#endif


} // namespace simple_application



