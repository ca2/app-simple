#pragma once


#include "base/_.h"
#include "base/user/simple/_simple.h"



#ifdef _APP_SIMPLE_OS_DRAG_AND_DROP_LIBRARY
#define CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace simple_os_drag_and_drop
{

   class application;
   class main_impact;
   class document;
   class impact;

} // namespace flag


#undef APP_TYPE
#define APP_TYPE ::simple_os_drag_and_drop::application


#include "simple_os_drag_and_drop.h"


#include "document.h"
#include "impact.h"
#include "main_impact.h"
#include "frame.h"
#include "main_frame.h"

#include "tab_view.h"


#include "application.h"



