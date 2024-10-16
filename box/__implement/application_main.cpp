#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_box::application g_app_simple_box_application;


//int __implement()
//{
//
//   auto papp = __new app_simple_box::application();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}



void application_main()
{

   auto papplication = __new app_simple_box::application();

   papplication->application_main(pplatform);

}




