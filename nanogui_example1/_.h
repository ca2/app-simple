#pragma once


#include "base/_.h"



#ifdef _APP_SIMPLE_NANOGUI_EXAMPLE1_LIBRARY
#define CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE1  CLASS_DECL_EXPORT
#define NANOGUI_EXPORT CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE1 CLASS_DECL_IMPORT
#define NANOGUI_EXPORT CLASS_DECL_IMPORT
#endif


namespace app_simple_nanogui_example1
{

   class application;
   class pane_impact;
   class document;
   class impact;

} // namespace flag


#include "application.h"



