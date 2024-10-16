#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_http_file_server::application g_app_simple_http_file_server;


//int __implement()
//{
//
//   auto papp = __new app_simple_http_file_server::application();
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

   auto papplication = __new app_simple_http_file_server::application();

   papplication->application_main(pplatform);

}



