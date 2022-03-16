#pragma once


#include "base/_.h"



#ifdef _APP_SIMPLE_APPLICATION_LIBRARY
#define CLASS_DECL_APP_SIMPLE_APPLICATION  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_APPLICATION  CLASS_DECL_IMPORT
#endif


namespace app_simple_application
{

   class application;
   class pane_impact;
   class document;
   class impact;

} // namespace flag


#include "application.h"



