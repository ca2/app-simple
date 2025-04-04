#include "framework.h"
#define APPLICATION_NAMESPACE app_core_
#include "acme/inline/application/main.inl"


//app_simple_drawing::application g_app_simple_drawing_application;



void application_main(::platform::system * psystem)
{

   app_simple_drawing::application application;

   application.application_main();

}




