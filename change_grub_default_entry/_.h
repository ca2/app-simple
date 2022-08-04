#pragma once


#include "base/_.h"



#ifdef _APP_SIMPLE_FORM_LIBRARY
#define CLASS_DECL_APP_SIMPLE_FORM  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_FORM  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace app_simple_change_grub_default_entry
{

   class application;
   class main_impact;
   class document;
   class impact;
   class tab_impact;

} // namespace flag

