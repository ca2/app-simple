#include "framework.h"
#define APPLICATION_NAMESPACE app_core_
#include "__implement.h"


//app_simple_nanoui_example::application g_app_simple_nanoui_example_application;
//#include "acme/prototype/collection/string_map.h"


//int __implement()
//{
//
//   auto papp = ___new app_simple_nanoui_example::application();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}
//
//
//
void application_main(::platform::system * psystem)
{

   app_simple_nanoui_example::application application;

   application.application_main();

}



