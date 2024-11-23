#include "framework.h"
#include "simple_os_drag_and_drop.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/graphics/draw2d/pen.h"
#include "aura/graphics/draw2d/brush.h"
#include "aura/graphics/image/context.h"
#include "aura/graphics/write_text/font.h"



CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


namespace app_simple_os_drag_and_drop
{



   simple_os_drag_and_drop::simple_os_drag_and_drop()
   {

      m_iDragAndDrop = 1;

   }


   simple_os_drag_and_drop::~simple_os_drag_and_drop()
   {

   }


#ifdef _DEBUG


   huge_integer simple_os_drag_and_drop::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   huge_integer simple_os_drag_and_drop::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void simple_os_drag_and_drop::initialize_drag_and_drop(int iDragAndDrop)
   {

      m_iDragAndDrop = iDragAndDrop;

   }

   void simple_os_drag_and_drop::on_layout(::draw2d::graphics_pointer & pgraphics)
   {


   }


   void simple_os_drag_and_drop::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      //informationf("simple_os_drag_and_drop::_001OnDraw (%d, %d)", m_rectangle.width(), m_rectangle.height());

      if(m_iDragAndDrop <= 3)
      {

         _001OnDraw1Through3(pgraphics);

      }
      else if(m_iDragAndDrop == 4)
      {

         _001OnDrawArcs(pgraphics, false);

      }
      else
      {

         _001OnDrawArcs(pgraphics, true);

      }

   }


   void simple_os_drag_and_drop::_001OnDraw1Through3(::draw2d::graphics_pointer & pgraphics)
   {

      auto ppen = __øcreate < ::draw2d::pen > ();

      auto pbrush = __øcreate < ::draw2d::brush >();

      auto pfont = __øcreate < ::write_text::font > ();

      auto psystem = system();

      auto pnode = psystem->node();

      pfont->create_font(e_font_sans_ex, 100.0_px, 800);

      pgraphics->set(pfont);

      ppen->create_solid(4.0, argb(255, 50, 180, 255));

      int_rectangle rectangle;

      int iSize = minimum(m_rectangle.width(), m_rectangle.height());

      iSize = iSize * 3 / 4;

      rectangle.set_size(iSize, iSize);

      rectangle.Align(e_align_center, m_rectangle);

      rectangle.offset_x(-iSize/5 * 3);

      rectangle.offset_x(iSize/5 * m_iDragAndDrop);

      auto papp = get_app();

      if(m_iDragAndDrop == 3)
      {

         pbrush->CreatePatternBrush(image()->get_image("matter://pat1.jpg"));

      }
      else
      {

         pbrush->CreateLinearGradientBrush(rectangle.top_left(), rectangle.bottom_right(), argb(255, 255, 255, 200), argb(255, 255, 125, 100));

      }

      pgraphics->set(ppen);

      pgraphics->set(pbrush);

      pgraphics->ellipse(rectangle);

      if(m_iDragAndDrop >= 2)
      {

         ::int_rectangle rectangleText(rectangle);

         rectangleText.inflate(100, 100);

         pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

         if(m_iDragAndDrop == 3)
         {

            if(m_pimagemap["pat1grayed"]->is_null())
            {

               auto pimage1 = image()->get_image("matter://pat1.jpg");
               
               /**pimage1 += { success, [this](auto & result)
               {
                  
                  ::image::image_pointer pimage = result;

                  m_pimpact->set_need_redraw();

                  ::image::image_pointer pimpl = pimage->clone();

                  ::image::image_pointer imageClone = pimpl;

                  m_pimagemap["pat1grayed"] = imageClone;

                  m_pimagemap["pat1grayed"]->saturation(0->0);

                  m_pimpact->set_need_redraw();
                  
                  m_pimpact->post_redraw();

                  return ::success;

               }};*/

            }

            pbrush->CreatePatternBrush(m_pimagemap["pat1grayed"]);

         }
         else
         {

            pbrush->CreateLinearGradientBrush(rectangleText.top_left(), rectangleText.bottom_right(), argb(255, 55, 210, 120), argb(255, 255, 255, 200));

         }

         pgraphics->set(pbrush);

         //pgraphics->draw_text("Simple Drawing", rectangleText, e_align_center);

      }

   }


   void simple_os_drag_and_drop::_001OnDrawArcs(::draw2d::graphics_pointer & pgraphics, bool bPath)
   {

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      ::array < float_angle > angleaStart;

      ::array < float_angle > angleaAngle;

      angleaStart.add(0.0_degree);
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

      pgraphics->fill_rectangle(rClient, argb(255, 192, 192, 185));

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


   void simple_os_drag_and_drop::draw_arc(::draw2d::graphics_pointer & pgraphics, int_rectangle & r, float_angle angleStart, float_angle angleAngle, bool bPath)
   {


      auto pfont = __øcreate < ::write_text::font > ();

      auto psystem = system();

      auto pnode = psystem->node();

      pfont->create_font(e_font_sans, 14.0_px, e_font_weight_light);

      pgraphics->set_text_color(argb(255, 0, 0, 0));

      pgraphics->set(pfont);

      string str;

      str.formatf("Start: %0.0f", angleStart.degree());

      pgraphics->text_out(r.left(), r.top(), str);

      str.formatf("Angle: %0.0f", angleAngle.degree());

      pgraphics->text_out(r.left(), r.top() + 20, str);

      auto ppen = __øcreate < ::draw2d::pen > ();

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

      pgraphics->set(ppen);

      pgraphics->arc(r, angleStart, angleAngle);


   }



} // namespace app_simple_os_drag_and_drop


