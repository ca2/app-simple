#include "framework.h"



#ifndef CUBE


#ifdef UNIVERSAL_WINDOWS
[Session::MTAThread]
#endif
BOOL WINAPI DllMain(HINSTANCE hInstance, unsigned int dwReason, LPVOID lpReserved)
{

   __UNREFERENCED_PARAMETER(hInstance);
   __UNREFERENCED_PARAMETER(lpReserved);


   if (dwReason == DLL_PROCESS_ATTACH)
   {

      ::OutputDebugStringW(L"app_love_as_a_service_helloworld.dll :: initializing!\n");
      
   }
   else if (dwReason == DLL_PROCESS_DETACH)
   {

      ::OutputDebugStringW(L"app_love_as_a_service_helloworld.dll :: terminating!\n");

   }

   return 1;

}


#endif



