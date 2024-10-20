#include "framework.h"
#include "application.h"
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







void application_main()
{

   auto papplication = ___new app_simple_shader::application();

   papplication->application_main();

}
