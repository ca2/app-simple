#include "framework.h"
#include "render.h"
#include <math.h>
#include "aura/graphics/draw2d/graphics.h"
#include "aura/graphics/draw2d/pen.h"
#include "aura/graphics/draw2d/brush.h"
#include "application.h"


CLASS_DECL_ACME ::color::color dk_red(); // <3 tbs


namespace app_simple_drawing
{


   void render::_001OnDrawBoxGradient(::draw2d::graphics_pointer & pgraphics)
   {

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->text_out(100, 50, "Round Rectangle (100, 100) - (900, 500) r = 100");

      ::double_rectangle r(100, 100, 900, 500);

      double greekdeltax = m_rectangle.width() / 1000.0;

      double greekdeltay = m_rectangle.height() / 600.0;

      double d = minimum(greekdeltax, greekdeltay);

      r *= d;

      double radius = 100 * d;

      ::draw2d::pen_pointer ppen;

      __øconstruct(ppen);

      auto echeckSimple = get_app()->m_checkSimple.echeck();

      if (echeckSimple.is_checked())
      {

         ppen->create_null();

      }
      else
      {

         ppen->create_solid(5.0, ::color::green);

      }

      ::draw2d::brush_pointer pbrush;

      __øconstruct(pbrush);

      pbrush->CreateBoxGradientBrush(r.top_left(), r.size(), radius, ::dk_red(), ::color::transparent);

      pgraphics->fill_round_rectangle(r, pbrush, radius);

      pgraphics->::draw2d::graphics::draw_round_rectangle(r, ppen, radius);

      draw_text(pgraphics);

   }


} // namespace simple_drawing



