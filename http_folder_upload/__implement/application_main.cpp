#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_http_folder_upload::application g_app_simple_http_folder_upload;


//int __implement()
//{
//
//   auto papp = new app_simple_http_folder_upload::application();
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

   auto papplication = ::place(new app_simple_http_folder_upload::application());

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}



