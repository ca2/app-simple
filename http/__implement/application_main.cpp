#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_http::application g_app_simple_http;


//int __implement()
//{
//
//   auto papp = ___new app_simple_http::application();
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

   app_simple_http::application application;

   application.application_main();

}



