#include "framework.h"
#include "application.h"
#include "__implement.h"


//app_simple_shortcut_amender::application g_app_simple_shortcut_amender_application;


//int __implement()
//{
//
//   auto papp = __new app_simple_shortcut_amender::application();
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

   auto papplication = __new app_simple_shortcut_amender::application();

   papplication->application_main(pplatform);

}



