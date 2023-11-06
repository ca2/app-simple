#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_application::application g_app_simple_application;


int application_main()
{

   auto papplication = __new(app_simple_application::application());

   int iExitCode = papplication->application_main();

   return iExitCode;

}




