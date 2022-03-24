// Created by camilo on 2022-03-23 11:55 PM <3ThomasBorregaardSørensen!! (Thomas likes number 5!!)
#include "framework.h"
#include <math.h>
#include "aura/graphics/draw2d/_draw2d.h"


CLASS_DECL_AURA::color::color dk_red(); // <3 tbs


namespace app_simple_drawing
{




   void render::_001OnDrawCirclePath(::draw2d::graphics_pointer & pgraphics)
   {

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->text_out(100, 50, "Circle Path (300, 300) - (800, 800) r = 250");

      ::rectangle_f64 r(300, 300, 800, 800);

      ::draw2d::path_pointer ppath;

      __construct(ppath);

      ppath->begin_figure();

      ppath->add_ellipse(r);

      ppath->close_figure();

      double radius = 100;

      ::draw2d::pen_pointer ppen;

      __construct(ppen);

      ppen->create_solid(5.0, ::color::green);

      ::draw2d::brush_pointer pbrush;

      __construct(pbrush);

      pbrush->CreateBoxGradientBrush(r.top_left(), r.size(), radius, ::dk_red(), ::color::transparent);

      pgraphics->fill(ppath, pbrush);

      pgraphics->draw(ppath, ppen);




   }


} // namespace simple_drawing



