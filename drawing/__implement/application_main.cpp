#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_drawing::application g_app_simple_drawing_application;



::i32 application_main(::platform::platform * pplatform)
{

   auto papplication = new app_simple_drawing::application();

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}




