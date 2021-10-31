#pragma once


#include "app-simple/drawing/_app_simple_drawing.h"
#include "core/user/userex/_userex.h"


#ifdef _APP_SIMPLE_NOTIFY_DRAWING_LIBRARY
#define CLASS_DECL_APP_SIMPLE_NOTIFY_DRAWING  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_NOTIFY_DRAWING  CLASS_DECL_IMPORT
#endif



namespace user
{

   typedef ::user::show < ::user::button > button_view;

} // namespace user


namespace notify_drawing
{

   class application;
   class impact;

} // namespace flag


#undef APP_TYPE
#define APP_TYPE ::notify_drawing::application


#include "impact.h"
#include "main_frame.h"



