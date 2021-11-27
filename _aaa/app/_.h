#pragma once


#include "aura/_.h"


#ifdef _APP_SIMPLE_APP_LIBRARY
#define CLASS_DECL_APP_SIMPLE_APP  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_APP  CLASS_DECL_IMPORT
#endif


namespace simple_app
{

   class application;
   class window;

} // namespace flag


#include "application.h"



