#pragma once


#include "base/_.h"
#include "base/user/simple/_simple.h"


#ifdef _APP_SIMPLE_FORM_LIBRARY
#define CLASS_DECL_APP_SIMPLE_FORM  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_FORM  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace simple_change_grub_default_entry
{

   class application;
   class main_view;
   class document;
   class view;
   class tab_view;

} // namespace flag


#undef APP_TYPE
#define APP_TYPE ::simple_change_grub_default_entry::application


#include "simple_change_grub_default_entry.h"
#include "simple_change_grub_default_entry_001.h"
#include "simple_change_grub_default_entry_002.h"


#include "document.h"
#include "view.h"
#include "main_view.h"
#include "frame.h"
#include "main_frame.h"

#include "tab_view.h"


#include "application.h"



