#include "framework.h"
#include "application.h"
#include "__implement.h"


//app_simple_shortcut_amender::application g_app_simple_shortcut_amender_application;


//int __implement()
//{
//
//   auto papp = new app_simple_shortcut_amender::application();
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

   auto papplication = new app_simple_shortcut_amender::application();

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}



