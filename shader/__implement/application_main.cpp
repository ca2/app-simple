#include "framework.h"
#include "application.h"
#include "__implement.h"


//app_simple_shader::application g_app_simple_shader_application;

//int __implement()
//{
//
//   auto papp = __new< app_simple_shader::application >();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}







::i32 application_main(::platform::platform * pplatform)
{

   auto papplication = __allocate< app_simple_shader::application >();

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}
