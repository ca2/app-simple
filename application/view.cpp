#include "framework.h"
#include <math.h>
#include "acme/const/id.h"


CLASS_DECL_AURA color32_t dk_red(); // <3 tbs


//#define DEBUG_WORK


namespace simple_application
{


   view::view()
   {

      m_flagNonClient -= non_client_background;

   }


   view::~view()
   {

   }


#ifdef _DEBUG


   int64_t view::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::user::impact::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t view::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::user::impact::add_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void view::assert_valid() const
   {

      user::box::assert_valid();

   }


   void view::dump(dump_context & dumpcontext) const
   {

      user::box::dump(dumpcontext);

   }


   void view::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&view::_001OnCreate);
      MESSAGE_LINK(e_message_destroy, psender, this, &view::_001OnDestroy);

   }


   void view::_001OnCreate(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      m_pfontThomasBS_ = ::write_text::point_font("Fira Code", 24);

   }


   void view::_001OnDestroy(::message::message * pmessage)
   {

   }


   void view::on_subject(::promise::subject * psubject, ::promise::context * pcontext)
   {

      ::user::impact::on_subject(psubject, pcontext);

   }


   ::user::document * view::get_document()
   {

      return ::user::impact::get_document();

   }


   void view::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      //pgraphics->fill_rectangle(rectd_dim(100, 100, 100, 100), color::magenta);

      //return;

      ::rectangle_i32 rectClient;

      get_client_rect(rectClient);

      if (rectClient.is_empty())
      {

         return;

      }

      pgraphics->set_alpha_mode(::draw2d::alpha_mode_blend);

      ::color::color color_dk(dk_red());

      color_dk.alpha = 127;

#ifdef DEBUG_WORK

      ::rectangle_i32 rectDryProWithLove_Work(100, 100, 200, 200);

      pgraphics->fill_rectangle(rectDryProWithLove_Work, argb(255, 150, 200, 255));

#endif

      pgraphics->set_text_color(color_dk);

      pgraphics->set(m_pfontThomasBS_);

      //pgraphics->text_out({ 10, 10 }, "psimpleapplication->m_pview->_001OnDraw(pgraphics);");
      
      string strText = "psimpleapplication->m_pview->_001OnDraw(pgraphics);";

      auto size = pgraphics->GetTextExtent(strText);

      ::point_i32 point;

      bool bFixedPosition = true;

      if (bFixedPosition)
      {

         point = { 10, 10 };

      }
      else
      {
       
         point.x = __random(0, (int)(rectClient.width() - size.cx));
         point.y = __random(0, (int)(rectClient.height() - size.cy));

      }

      pgraphics->text_out(point.x, point.y, strText);

   }


   void view::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectClient = get_client_rect();

      if(rectClient.is_empty())
      {

         return;

      }

      ::user::impact::on_layout(pgraphics);

   }


} // namespace simple_application



