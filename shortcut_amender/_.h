#pragma once


#include "base/_.h"


#if defined(_app_simple_shortcut_amender_project)
#define CLASS_DECL_app_simple_shortcut_amender  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_app_simple_shortcut_amender  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_impact;

} // namespace user


namespace app_simple_shortcut_amender
{

   class application;
   class main_impact;
   class document;
   class impact;
   class tab_impact;

   class form_amender;

} // namespace flag



