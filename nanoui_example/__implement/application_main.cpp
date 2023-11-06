#include "framework.h"
#include "application.h"
#include "__implement.h"


//app_simple_nanoui_example::application g_app_simple_nanoui_example_application;
//#include "acme/primitive/collection/string_map.h"


//int __implement()
//{
//
//   auto papp = memory_new app_simple_nanoui_example::application();
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

   auto papplication = __new(app_simple_nanoui_example::application());

   int iExitCode = papplication->application_main();

   return iExitCode;

}



