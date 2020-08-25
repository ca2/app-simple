#include "framework.h"
#include "aura/id.h"
#include <math.h>


CLASS_DECL_AURA COLORREF dk_red(); // <3 tbs


namespace simple_drawing
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


   int64_t render::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t render::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void render::on_layout(::draw2d::graphics_pointer & pgraphics)
   {


   }


   void render::initialize_simple_drawing(int iDrawing)
   {

      initialize_application_consumer();

      m_iDrawing = iDrawing;

      COLORREF crText = ARGB(255, 55, 210, 120);

      if (m_iDrawing == 1)
      {

         crText = ARGB(127, 0, 127, 200);

      }
      else if (m_iDrawing == 3)
      {

         crText = ARGB(255, 180, 180, 180);

      }

      color color(crText);

      string strDataId;

      strDataId = m_pview->m_id;

      //m_hlsText.m_dH = 0.1;
      //m_hlsText.m_dL = 0.5;
      //m_hlsText.m_dS = 0.9;

      //Application.data_set(strDataId, m_hlsText);

      if(!Application.data_get(strDataId +".color", m_hlsText))
      {

         m_hlsText = color.get_hls();

      }

   }


   void render::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (ThisApp.m_echeckNoClientFrame != ::check_checked)
      {

         ::rect rect(m_rect);

         pgraphics->set_alpha_mode(::draw2d::alpha_mode_blend);

         for (index i = 0; i < 5; i++)
         {

            pgraphics->draw_rect(rect, ARGB(127, 225, 225, 225));

            rect.deflate(1, 1);

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


   ::estatus render::set_font(const string & strFont)
   {

      if (strFont.is_empty())
      {

         return error_invalid_argument;

      }

      string strDataId;

      strDataId = m_pview->m_id;

      if (!Application.data_set(strDataId + ".font_family", m_strFont1))
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

         if (!Application.data_get(strDataId + ".font_family", m_strFont1)
            || m_strFont1.is_empty())
         {

            m_strFont1 = FONT_SANS_EX;

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


} // namespace simple_drawing



