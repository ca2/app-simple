#include "framework.h"
#include "application.h"
#include "__implement.h"


int __implement()
{

   auto papp = memory_new app_simple_change_grub_default_entry::application();

   int iExitCode = papp->__implement();

   return iExitCode;

}


