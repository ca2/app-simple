#include "framework.h"
#include <math.h>


CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


namespace simple_webserver
{


   void render::draw_arc(::draw2d::graphics_pointer & pgraphics, rectangle_i32& r, angle angleStart, angle angleAngle, bool bPath)
   {

      ::write_text::font_pointer font(e_create);

      string strFontFamily = get_font();

      font->create_pixel_font(strFontFamily, 14.0, e_font_weight_light);

      ::color::color color(m_hlsText);

      pgraphics->set_text_color(color);

      pgraphics->set(font);

      string str1;

      str1.Format("Start: %0.0f", angleStart.degree());

      string str2;

      str2.Format("Angle: %0.0f", angleAngle.degree());

      auto size1 = pgraphics->get_text_extent(str1);

      size1.cx += 32;

      size1.cy += 4;

      auto size2 = pgraphics->get_text_extent(str2);

      size2.cx += 32;

      size2.cy += 4;

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      ::size_i32 size;

      size = size1.maximum(size2);

      ::rectangle_i32 rectBack(r);

      rectBack.deflate(2, 2);

      rectBack.bottom = rectBack.top + size.cy * 2 + 4 * 3;

      pgraphics->fill_rectangle(rectBack, argb(127, 80, 80, 80));

      pgraphics->text_out(rectBack.left + 4, rectBack.top + 4, str1);

      pgraphics->text_out(rectBack.left + 4, rectBack.top + size.cy + 8, str2);

      ::draw2d::pen_pointer pen(e_create);

      ::draw2d::brush_pointer brush(e_create);

      brush->create_null();

      pgraphics->set(brush);

      if (__bool(m_papplication->m_echeckSimple))
      {

         if (angleAngle < 0.0)
         {

            pen->create_solid(4.0, argb(255, 120, 120, 120));

         }
         else
         {

            pen->create_solid(4.0, argb(255, 255, 255, 255));

         }

      }
      else
      {

         if (angleAngle < 0.0)
         {

            if (bPath)
            {

               pen->create_solid(4.0, dk_red());

            }
            else
            {

               pen->create_solid(4.0, argb(255, 255, 230, 155));

            }

         }
         else
         {

            if (bPath)
            {

               pen->create_solid(4.0, argb(255, 255, 255, 255));

            }
            else
            {

               pen->create_solid(4.0, argb(255, 50, 180, 255));

            }

         }

      }

      pgraphics->set(pen);

      pgraphics->clear_current_point();

      pgraphics->Arc(r, angleStart, angleAngle);

   }


   void render::_001OnDrawArcs(::draw2d::graphics_pointer & pgraphics, bool bPath)
   {

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      ::array < angle > angleaStart;

      ::array < angle > angleaAngle;

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

      ::rectangle_i32 rClient(m_rectangle);

      if (__bool(m_papplication->m_echeckSimple))
      {

         pgraphics->fill_rectangle(rClient, argb(127, 192, 192, 192));

      }
      else
      {

         pgraphics->fill_rectangle(rClient, argb(127, 120, 120, 120));

      }

      int iColumnCount = 8;

      rectangle_i32 r;

      r.top = 0;

      r.left = 0;

      r.bottom = rClient.center().y;

      int i = 0;

      int iColumnWidth = rClient.width() / iColumnCount;

      for (i = 0; i < iColumnCount && i < angleaStart.get_size(); i++)
      {

         r.right = r.left + iColumnWidth;

         draw_arc(pgraphics, r, angleaStart[i], angleaAngle[i], bPath);

         r.left = r.right;

      }

      r.top = r.bottom;

      r.left = 0;

      r.bottom = rClient.bottom;

      for (; i < iColumnCount * 2 && i < angleaStart.get_size(); i++)
      {

         r.right = r.left + iColumnWidth;

         draw_arc(pgraphics, r, angleaStart[i], angleaAngle[i], bPath);

         r.left = r.right;

      }

   }


} // namespace simple_webserver



