#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_drawing::application g_app_simple_drawing_application;



void application_main()
{

   auto papplication = __new app_simple_drawing::application();

   papplication->application_main();

}




