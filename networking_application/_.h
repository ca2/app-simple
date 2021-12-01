#pragma once


#include "base/_.h"


#ifdef _APP_SIMPLE_NETWORKING_APPLICATION_LIBRARY
#define CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION  CLASS_DECL_IMPORT
#endif


namespace app_simple_networking_application
{

   
   class application;
   class tab_view;
   class document;
   class impact;
   //class socket_thread;


} // namespace app_simple_networking_application



