#include "framework.h"
#include "application.h"
#include "main_window.h"
#include "nanogui/Screen.h"


namespace app_simple_nanogui_example
{


   application::application()
   {

      m_strAppId = "app-simple/nanogui_example";

      m_strAppName = "app-simple/nanogui_example";

      m_strBaseSupportId = "app_simple_nanogui_example";

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


   void application::on_request(::create * pcreate)
   {

      __compose_new(m_pmainwindow);

      m_pmainwindow->display(e_display_restored);

      m_pmainwindow->create_main_window();

      m_pmainwindow->set_need_layout();

      m_pmainwindow->set_need_redraw();

      m_pmainwindow->post_redraw();

   }


   string application::preferred_experience()
   {

      return "nanogui";

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


} // namespace simple_application



