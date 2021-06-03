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

      MESSAGE_LINK(e_message_create,psender,this,&view::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &view::_001OnDestroy);

   }


   void view::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }
      
      auto psystem = m_psystem->m_paurasystem;
      
      auto pnode = psystem->draw2d();
      
      auto pwritetext = pnode->write_text();

      m_pfontThomasBS_ = pwritetext->point_font("Fira Code", 24);

   }


   void view::_001OnDestroy(::message::message * pmessage)
   {

   }


   void view::on_subject(::subject::subject * psubject, ::subject::context * pcontext)
   {

      ::user::impact::on_subject(psubject, pcontext);

   }


   document * view::get_document()
   {

      return dynamic_cast < document * >(::user::impact::get_document());

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
      
      string_array & stra = get_document()->m_straLine;
      
//      stra.add("<3");
//      stra.add("T");
//      stra.add("+");
//      stra.add("homasBS_!!");
//      stra.add(">");
      
      bool bWhite  = true;
      
      double x = 0.;
      
      double y = 0.;
      
      ::point_i32 point;

      string strText = "psimpleapplication->m_pview->_001OnDraw(pgraphics);";

      auto size = pgraphics->GetTextExtent(strText);

      bool bFixedPosition = true;

      if (bFixedPosition)
      {

         point = { 10, 10 };

      }
      else
      {
       
         point.x = __random(0, (int)(rectClient.width() - size.cx));
         point.y = __random(0, (int)(rectClient.height() - size.cy*2));

      }
      
      for(auto & strItem : stra)
      {
         
         if(strItem.is_empty())
         {
            
            x = 0;
            
            y += size.cy;
            
            bWhite = true;
         
            continue;
         
         }
         
         if(bWhite)
         {
            
            pgraphics->set_text_color(color::white);
            
         }
         else
         {
            
            pgraphics->set_text_color(color_dk);
            
         }
         
         pgraphics->text_out(point.x + x, point.y + y, strItem);
         
         auto s = pgraphics->GetTextExtent(strItem);

         x += s.cx;
         
         bWhite = !bWhite;
         
      }
//      string strText = "<3";
//
//
//
//
//
//
//      point.x += size.cx;
//
//      pgraphics->set_text_color(color_dk);
//
//      size = pgraphics->GetTextExtent("TBS_");
//
//      pgraphics->text_out(point.x, point.y, strText);
//
//      point.x += size.cx;
//
//      pgraphics->set_text_color(color_dk);
//
//      pgraphics->set_text_color(color::white);
//
//      pgraphics->text_out(point.x, point.y, strText);
//
      
      pgraphics->set_text_color(color_dk);



      pgraphics->text_out(point.x, point.y + y + size.cy, strText);

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



