#include "framework.h"

#include "aura/application.h"
//#include "aura/update.h"



namespace simple_app
{


   __IMPLEMENT_APPLICATION_RELEASE_TIME();


   application::application()
   {

      m_strAppId = "app-simple/app";

      m_strAppName = "Simple Application!!";

      m_strBaseSupportId = "app_simple_app";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   void application::init_instance()
   {

      if (!::aura::application::init_instance())
      {

         return false;

      }

      return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

      __refer(m_pwindow, __create_new < window >());

      ::int_rectangle rectangleWindow;

      m_pwindow->_001InitialFramePosition(rectangleWindow, {0.05, 0.05, 0.4, 0.4});

      ::user::system cs(0, nullptr, "simple_app", WS_VISIBLE, rectangleWindow);

      m_pwindow->create_window_ex(cs);

      m_pwindow->display(e_display_normal);

      m_pwindow->place(rectangleWindow);

      m_pwindow->set_need_layout();

      m_pwindow->set_need_redraw();

      m_pwindow->post_redraw();

   }


#ifdef _DEBUG


   int64_t application::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   int64_t application::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   __namespace_application_factory("app-simple/app");


} // namespace simple_app







//
//extern "C"
//::acme::library * app_simple_drawing_get_new_library()
//{
//
//   return ___new ::apex::single_application_library < ::simple_app::application >("app-simple/drawing");
//
//}
//
//
//aura_app aura_app_simple_drawing("app-simple/drawing", &app_simple_drawing_get_new_library);
//
//
//simple_app::application application;


