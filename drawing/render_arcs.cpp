#include "framework.h"
#include "render.h"
#include "application.h"
#include <math.h>
#include "aura/graphics/draw2d/graphics.h"
#include "aura/graphics/draw2d/draw2d.h"
#include "aura/graphics/draw2d/pen.h"


CLASS_DECL_ACME ::color::color dk_red(); // <3 tbs


namespace app_simple_drawing
{


   void render::draw_arc(::draw2d::graphics_pointer & pgraphics, int_rectangle& r, ::double_angle angleStart, ::double_angle angleAngle, bool bPath)
   {

      auto psystem = system();

      auto pdraw2d = psystem->draw2d();

      auto pwritetext = pdraw2d->write_text();

      auto pfont = pwritetext->create_font();

      string strFontFamily = get_font();

      pfont->create_font(strFontFamily, 14_px, e_font_weight_light);

      ::color::color color(m_hlsText);

      pgraphics->set_text_color(color);

      pgraphics->set(pfont);

      string str1;

      str1.formatf("Start: %0.0f", angleStart.degree());

      string str2;

      str2.formatf("Angle: %0.0f", angleAngle.degree());

      auto size1 = pgraphics->get_text_extent(str1);

      size1.cx() += 32;

      size1.cy() += 4;

      auto size2 = pgraphics->get_text_extent(str2);

      size2.cx() += 32;

      size2.cy() += 4;

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      ::int_size size;

      size = size1.maximum(size2);

      ::int_rectangle rectangleBack(r);

      rectangleBack.deflate(2, 2);

      rectangleBack.bottom() = rectangleBack.top() + size.cy() * 2 + 4 * 3;

      pgraphics->fill_rectangle(rectangleBack, argb(127, 80, 80, 80));

      pgraphics->text_out(rectangleBack.left() + 4, rectangleBack.top() + 4, str1);

      pgraphics->text_out(rectangleBack.left() + 4, rectangleBack.top() + size.cy() + 8, str2);

      auto ppen = __øcreate < ::draw2d::pen >();

      auto pbrush = __øcreate < ::draw2d::brush >();

      pbrush->create_null();

      pgraphics->set(pbrush);

      if (get_app()->m_checkSimple.is_checked())
      {

         if (angleAngle < 0.0)
         {

            ppen->create_solid(4.0, argb(255, 120, 120, 120));

         }
         else
         {

            ppen->create_solid(4.0, argb(255, 255, 255, 255));

         }

      }
      else
      {

         if (angleAngle < 0.0)
         {

            if (bPath)
            {

               ppen->create_solid(4.0, dk_red());

            }
            else
            {

               ppen->create_solid(4.0, argb(255, 255, 230, 155));

            }

         }
         else
         {

            if (bPath)
            {

               ppen->create_solid(4.0, argb(255, 255, 255, 255));

            }
            else
            {

               ppen->create_solid(4.0, argb(255, 50, 180, 255));

            }

         }

      }

      pgraphics->set(ppen);

      pgraphics->clear_current_point();

      pgraphics->arc(r, angleStart, angleAngle);

   }


   void render::_001OnDrawArcs(::draw2d::graphics_pointer & pgraphics, bool bPath)
   {

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      ::array < ::double_angle > angleaStart;

      ::array < ::double_angle > angleaAngle;

      auto a = 0.0_degree;
      angleaStart.add(a);
      angleaAngle.add(100.0_degree);

      angleaStart.add(90.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(180.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(270.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(-90.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(-180.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(-270.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(45.0_degree);
      angleaAngle.add(100.0_degree);

      angleaStart.add(0.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(90.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(180.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(270.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(-90.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(-180.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(-270.0_degree);
      angleaAngle.add(-100.0_degree);

      angleaStart.add(45.0_degree);
      angleaAngle.add(-100.0_degree);

      ::int_rectangle rClient(m_rectangle);

      if (get_app()->m_checkSimple.is_checked())
      {

         pgraphics->fill_rectangle(rClient, argb(127, 192, 192, 192));

      }
      else
      {

         pgraphics->fill_rectangle(rClient, argb(127, 120, 120, 120));

      }

      int iColumnCount = 8;

      int_rectangle r;

      r.top() = 0;

      r.left() = 0;

      r.bottom() = rClient.center().y();

      int i = 0;

      int iColumnWidth = rClient.width() / iColumnCount;

      for (i = 0; i < iColumnCount && i < angleaStart.get_size(); i++)
      {

         r.right() = r.left() + iColumnWidth;

         draw_arc(pgraphics, r, angleaStart[i], angleaAngle[i], bPath);

         r.left() = r.right();

      }

      r.top() = r.bottom();

      r.left() = 0;

      r.bottom() = rClient.bottom();

      for (; i < iColumnCount * 2 && i < angleaStart.get_size(); i++)
      {

         r.right() = r.left() + iColumnWidth;

         draw_arc(pgraphics, r, angleaStart[i], angleaAngle[i], bPath);

         r.left() = r.right();

      }

   }


} // namespace simple_drawing



