#include "framework.h"
#include "application.h"
#include "__implement.h"


int __implement()
{

   auto papp = new app_simple_application::application();

   int iExitCode = papp->__implement();

   return iExitCode;

}



