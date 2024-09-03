#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_application::application g_app_simple_application;


::i32 application_main(::platform::platform * pplatform)
{

   auto papplication = ::place(new app_simple_application::application());

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}




