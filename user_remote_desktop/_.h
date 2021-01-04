#pragma once


#include "core/_.h"


#ifdef _APP_SIMPLE_VIDEO_LIBRARY
#define CLASS_DECL_APP_SIMPLE_VIDEO  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_VIDEO  CLASS_DECL_IMPORT
#endif


namespace simple_video
{

   
   class application;
   class tab_view;
   class document;
   class view;
   //class socket_thread;


} // namespace flag


namespace video_input
{

   class video_input;

} // namespace video_input

#include "video_input/_.h"


#include "render.h"



#include "application.h"



