#pragma once


#include "acme/primitive/collection/string_map.h"
#include "acme/primitive/geometry2d/angle.h"
#include "acme/primitive/geometry2d/rectangle.h"
//#include "acme/primitive/geometry2d/_geometry2d.h"


namespace app_simple_os_drag_and_drop
{


   class CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP simple_os_drag_and_drop :
      virtual public ::object
   {
   public:


      rectangle_i32                          m_rectangle;
      ::user::impact *                       m_pimpact;
      string                                 m_strFont;
      int                                    m_iDragAndDrop;
      string_map < ::image::image_pointer >         m_pimagemap;


      simple_os_drag_and_drop();
      ~simple_os_drag_and_drop() override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif

      virtual void initialize_drag_and_drop(int iDragAndDrop);

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics);

      virtual void _001OnDraw1Through3(::draw2d::graphics_pointer & pgraphics);

      virtual void _001OnDrawArcs(::draw2d::graphics_pointer & pgraphics, bool bPath);

      virtual void draw_arc(::draw2d::graphics_pointer & pgraphics, rectangle_i32 & r, ::angle_f32 angleStart, ::angle_f32 angleAngle, bool bPath);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics);

   };


} // namespace app_simple_os_drag_and_drop


