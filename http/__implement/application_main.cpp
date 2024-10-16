#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_http::application g_app_simple_http;


//int __implement()
//{
//
//   auto papp = __new app_simple_http::application();
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

   auto papplication = __new app_simple_http::application();

   papplication->application_main(pplatform);

}



