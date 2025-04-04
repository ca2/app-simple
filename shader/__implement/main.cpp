#include "framework.h"
#define APPLICATION_NAMESPACE app_core_
#include "__implement.h"


//app_simple_shader::application g_app_simple_shader_application;

//int __implement()
//{
//
//   auto papp = ___new app_simple_shader::application();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}







void application_main(::platform::system * psystem)
{

   app_simple_shader::application application;

   application.application_main();

}
