#include "framework.h"
#include "application.h"
#include "__implement.h"


int __implement()
{

   auto papp = ___new app_simple_nanoui_example::application();

   int iExitCode = papp->__implement();

   return iExitCode;

}



