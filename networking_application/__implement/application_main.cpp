#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_networking_application::application g_app_simple_networking_application;


//int __implement()
//{
//
//   auto papp = __new< app_simple_networking_application::application >();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}
//
//
//


::i32 application_main(::platform::platform * pplatform)
{

   auto papplication = __allocate< app_simple_networking_application::application >();

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}



