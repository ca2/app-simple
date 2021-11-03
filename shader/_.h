#pragma once


#include "app/shader/_.h"
#include "core/_.h"


#ifdef _APP_SIMPLE_SHADER_LIBRARY
#define CLASS_DECL_APP_SIMPLE_SHADER  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_SHADER  CLASS_DECL_IMPORT
#endif


namespace app_simple_shader
{

   class application;
   class tab_view;
   class document;
   class impact;

} // namespace flag


namespace opengl
{


   class opengl;
   class shader;
   class buffer;
   class program;


} // namespace opengl





