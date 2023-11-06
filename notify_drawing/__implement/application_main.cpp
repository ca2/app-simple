#include "framework.h"
#include "application.h"
#include "__implement.h"


//app_simple_notify_drawing::application g_app_simple_notify_drawing_application;


//int __implement()
//{
//
//   auto papp = memory_new app_simple_notify_drawing::application();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}
//
//
//
int application_main()
{

   auto papplication = __new(app_simple_notify_drawing::application());

   int iExitCode = papplication->application_main();

   return iExitCode;

}
