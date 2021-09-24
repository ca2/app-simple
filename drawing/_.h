#pragma once


#include "base/_.h"


#ifdef _APP_SIMPLE_DRAWING_LIBRARY
#define CLASS_DECL_APP_SIMPLE_DRAWING  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APP_SIMPLE_DRAWING  CLASS_DECL_IMPORT
#endif


namespace simple_drawing
{

   class application;
   class tab_view;
   class document;
   class impact;

} // namespace flag



class object_properties :
   virtual public property_object
{
public:


   ::object * m_pobject;


   object_properties(::object * pobject)
   {

      initialize(pobject);

      m_pobject = pobject;

   }


   ::property_object * parent_property_set_holder() const override
   {

      return m_pobject;

   }

};


#include "render.h"



#include "application.h"



