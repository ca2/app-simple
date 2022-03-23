#include "framework.h"
#include <math.h>
#include "aura/graphics/draw2d/_draw2d.h"


CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


namespace app_simple_drawing
{




   void render::_001OnDrawBoxGradient(::draw2d::graphics_pointer & pgraphics)
   {

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      ::rectangle_f64 r(100, 100, 900, 500);

      double radius = 100;

      ::draw2d::brush_pointer pbrush;

      __construct(pbrush);

      pbrush->CreateBoxGradientBrush(r.top_left(), r.size(), radius, ::dk_red(), ::color::transparent);

      pgraphics->set(pbrush);

      pgraphics->fill_round_rect(r, pbrush, radius);




   }


} // namespace simple_drawing



