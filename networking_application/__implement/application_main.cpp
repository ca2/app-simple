#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_networking_application::application g_app_simple_networking_application;


//int __implement()
//{
//
//   auto papp = __new app_simple_networking_application::application();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}
//
//
//


void application_main()
{

   auto papplication = __new app_simple_networking_application::application();

   papplication->application_main(pplatform);

}



