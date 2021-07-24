#include "framework.h"
#include "aura/id.h"
#include <math.h>


CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


namespace simple_webserver
{



   render::render() :
      m_strHoverFontFamilyName(topic(id_hover_font_family_name))
   {

      m_iDrawing = 1;

   }


   render::~render()
   {

   }


#ifdef _DEBUG


   int64_t render::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t render::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void render::on_layout(::draw2d::graphics_pointer & pgraphics)
   {


   }


   void render::initialize_simple_drawing(int iDrawing)
   {

      //initialize_application_consumer();

      m_iDrawing = iDrawing;

      color32_t crText = argb(255, 55, 210, 120);

      if (m_iDrawing == 1)
      {

         crText = argb(127, 0, 127, 200);

      }
      else if (m_iDrawing == 3)
      {

         crText = argb(255, 180, 180, 180);

      }

      ::color::color color(crText);

      string strDataId;

      strDataId = m_pview->m_id;

      //m_hlsText.m_dH = 0.1;
      //m_hlsText.m_dL = 0.5;
      //m_hlsText.m_dS = 0.9;

      //m_papplication->data_set(strDataId, m_hlsText);

      auto m_papplication = get_application();

      if(!m_papplication->data_get(strDataId +".color", m_hlsText))
      {

         m_hlsText = color.get_hls();

      }

   }


   void render::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (m_papplication->m_echeckNoClientFrame != ::check_checked)
      {

         ::rectangle_i32 rectangle(m_rectangle);

         pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

         for (index i = 0; i < 5; i++)
         {

            pgraphics->draw_rectangle(rectangle, argb(127, 225, 225, 225));

            rectangle.deflate(1, 1);

         }

      }

      if(m_iDrawing <= 3)
      {

         _001OnDraw1Through3(pgraphics);

      }
      else if(m_iDrawing == 4)
      {

         _001OnDrawArcs(pgraphics, false);

      }
      else
      {

         _001OnDrawArcs(pgraphics, true);

      }

   }


   ::e_status render::set_font(const string & strFont)
   {

      if (strFont.is_empty())
      {

         return error_invalid_argument;

      }

      string strDataId;

      strDataId = m_pview->m_id;

      auto m_papplication = get_application();

      if (!m_papplication->data_set(strDataId + ".font_family", m_strFont1))
      {

         return error_failed;

      }

      m_strFont1 = strFont;

      return ::success;

   }


   string render::get_font()
   {

      string strFont;

      strFont = m_strHoverFontFamilyName;

      if (strFont.has_char())
      {

         return strFont;

      }

      if (m_strFont1.is_empty())
      {

         string strDataId;

         strDataId = m_pview->m_id;

         if (!m_papplication->data_get(strDataId + ".font_family", m_strFont1)
            || m_strFont1.is_empty())
         {

            m_strFont1 = m_psystem->m_pnode->font_name(e_font_sans_ex);

         }

      }

      return m_strFont1;

   }



   //string application::get_main_title() const
   //{

   //   string strSimple(m_strSimple);

   //   if (strSimple.trimmed().has_char())
   //   {

   //      return m_strSimple;

   //   }
   //   else
   //   {

   //      return m_strMainTitle;

   //   }

   //}


} // namespace simple_webserver



