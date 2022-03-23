#pragma once


#include "base/_.h"



#ifdef _APP_SIMPLE_NANOGUI_EXAMPLE_LIBRARY
#define CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE  CLASS_DECL_EXPORT
#define NANOGUI_EXPORT CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE CLASS_DECL_IMPORT
#endif


namespace app_simple_nanogui_example
{

   class application;
   class pane_impact;
   class document;
   class impact;
   class ExampleApplication1;

} // namespace flag


#include "application.h"



