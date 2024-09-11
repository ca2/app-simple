#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_http::application g_app_simple_http;


//int __implement()
//{
//
//   auto papp = new app_simple_http::application();
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

   auto papplication = new app_simple_http::application();

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}



