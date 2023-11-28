#include "framework.h"
#include "application.h"
#include "__implement.h"


int __implement()
{

   auto papp = __new< app_simple_nanoui_example::application >();

   int iExitCode = papp->__implement();

   return iExitCode;

}



