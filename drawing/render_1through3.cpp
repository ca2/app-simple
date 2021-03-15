#include "framework.h"
#include <math.h>


CLASS_DECL_AURA color32_t dk_red(); // <3 tbs


namespace simple_drawing
{


   void render::_001OnDraw1Through3(::draw2d::graphics_pointer & pgraphics)
   {

      string strFontFamily = get_font();

      ::draw2d::pen_pointer pen(e_create);

      ::draw2d::brush_pointer brush(e_create);

      if (m_iDrawing == 3)
      {

         if (!m_pimage1)
         {

            m_pimage1.create();

            fork([this]()
               {

                  m_pimage1 = papplication->image().get_image("matter://pat1.jpg");

                  if (::is_ok(m_pimage1))
                  {

                     __construct(m_pimage2);

                     m_pimage2->copy_from(m_pimage1);

                     if (::is_ok(m_pimage2))
                     {

                        m_pimage2->transform(image_grayscale);

                        m_pview->set_need_redraw();

                        m_pview->post_redraw();

                     }

                  }

               });

         }

      }

      rectangle_i32 rectangle;

      int iSize = minimum(m_rectangle.width(), m_rectangle.height());

      iSize = iSize * 3 / 4;

      rectangle.set_size(iSize, iSize);

      rectangle.Align(e_align_center, m_rectangle);

      rectangle.offset_x(-iSize / 5 * 3);

      rectangle.offset_x(iSize / 5 * m_iDrawing);
      
      ::size_f64 size(0., 0.);
      
      bool bDrawText = true;
      
      string strTitle;
      
      ::write_text::font_pointer font1(e_create);

      ::write_text::font_pointer font2(e_create);

      if(bDrawText)
      {

         font1->create_pixel_font(strFontFamily, 100.0, 800);

         pgraphics->set(font1);

         strTitle = ThisApp.m_strMainTitle;

         size = pgraphics->GetTextExtent(strTitle);

         if (!size.is_empty())
         {

            int iHeight = rectangle.height();

            double dMaxDimension = size.get_maximum_dimension();

            ::write_text::font_pointer font2(e_create);

            if (m_iDrawing == 1)
            {

               float fSize = (float) (iHeight * 80.0 / dMaxDimension);

               font2->create_pixel_font(strFontFamily, fSize, 800);

            }
            else
            {

               float fSize = (float) (iHeight * 160.0 / dMaxDimension);

               font2->create_pixel_font(strFontFamily, fSize, 800);

            }

         }

         pgraphics->set(font2);

         size = pgraphics->GetTextExtent(strTitle);
            
      }

      auto& echeckSimple = ThisApp.m_echeckSimple;

      if (__bool(echeckSimple))
      {

         pen->create_null();

      }
      else
      {

         pen->create_solid(4.0, argb(255, 50, 180, 255));

      }

      if (m_iDrawing == 3 && ::is_ok(m_pimage1))
      {

         brush->CreatePatternBrush(m_pimage1);

      }
      else
      {

         if (__bool(ThisApp.m_echeckSimple))
         {

            brush->create_solid(argb(255, 255, 255, 200));

         }
         else
         {

            brush->CreateLinearGradientBrush(rectangle.top_left(), rectangle.bottom_right(), argb(255, 255, 255, 200), argb(255, 255, 125, 100));

         }

      }

      pgraphics->set(pen);

      pgraphics->set(brush);

      pgraphics->ellipse(rectangle);

      ::rectangle_i32 rectText;

      rectText.set_size(size);

      rectText.inflate(10, 10);

      rectText.Align(e_align_center, rectangle);

      pgraphics->set_alpha_mode(::draw2d::alpha_mode_blend);

      if (m_iDrawing == 1)
      {

         brush->create_solid(m_hlsText);

      }
      else if (m_iDrawing == 3)
      {

         if (__bool(ThisApp.m_echeckSimple))
         {

            brush->create_solid(m_hlsText);

         }
         else
         {

            if (::is_ok(m_pimage2))
            {

               brush->CreatePatternBrush(m_pimage2);

            }
            else
            {

               brush->create_solid(m_hlsText);

            }

         }

      }
      else
      {

         if (__bool(ThisApp.m_echeckSimple))
         {

            brush->create_solid(m_hlsText);

         }
         else
         {

            brush->CreateLinearGradientBrush(rectText.top_left(), rectText.bottom_right(), m_hlsText, argb(255, 255, 255, 200));

         }

      }

      pgraphics->set(brush);

      if(bDrawText)
      {
      
         pgraphics->draw_text(strTitle, rectText, e_align_center);
         
      }

   }


} // namespace simple_drawing



