#pragma once


#include "berg/_.h"


#if defined(_app_simple_box_project)
#define CLASS_DECL_APP_SIMPLE_BOX  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_BOX  CLASS_DECL_IMPORT
#endif


namespace app_simple_box
{

   
   class application;
   class document;
   class impact;


} // namespace app_simple_box



