#pragma once


#include "berg/_.h"
//#include "berg/user/simple/_component.h"



#if defined(_app_simple_os_drag_and_drop_project)
#define CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP  CLASS_DECL_IMPORT
#endif


namespace user
{

   typedef ::user::show < ::user::button > button_impact;

} // namespace user


namespace app_simple_os_drag_and_drop
{

   class application;
   class main_impact;
   class document;
   class impact;

} // namespace flag


#undef APP_TYPE
#define APP_TYPE ::app_simple_os_drag_and_drop::application


#include "simple_os_drag_and_drop.h"


#include "document.h"
#include "impact.h"
#include "main_impact.h"
#include "frame.h"
#include "main_frame.h"

#include "tab_impact.h"


#include "application.h"



