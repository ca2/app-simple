#include "framework.h"
#include "application.h"
#include "__implement.h"


//app_simple_change_grub_default_entry::application g_app_simple_change_grub_default_entry_application;


//int __implement()
//{
//
//   auto papp = __new app_simple_change_grub_default_entry::application();
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

   auto papplication = __new app_simple_change_grub_default_entry::application();

   int iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}



