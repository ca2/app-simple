#include "framework.h"
#include "application.h"
#include "acme/application.h"


//app_simple_change_grub_default_entry::application g_app_simple_change_grub_default_entry_application;


//int __implement()
//{
//
//   auto papp = ___new app_simple_change_grub_default_entry::application();
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

   app_simple_change_grub_default_entry::application application;

   application.application_main();

}



