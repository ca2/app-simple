#pragma once


#include "berg/_.h"


#if defined(_app_simple_build_plan_project)
#define CLASS_DECL_APP_SIMPLE_BUILD_PLAN  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_BUILD_PLAN  CLASS_DECL_IMPORT
#endif


namespace app_simple_build_plan
{


   class application;
   class tab_impact;
   class document;
   class impact;
   class render;
   class build_plan_layout;


} // namespace app_simple_build_plan



