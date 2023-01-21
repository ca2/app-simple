#include "framework.h"
#include "impact.h"
#include "document.h"
#include "application.h"
#include "acme/constant/message.h"
#include "acme/primitive/mathematics/_random.h"
#include "aura/message/user.h"
#include "aura/graphics/draw2d/draw2d.h"


CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


//#define DEBUG_WORK


namespace app_simple_application
{


   impact::impact()
   {

      m_flagNonClient -= e_non_client_background;
      m_iSequence = 0;

   }


   impact::~impact()
   {

   }


#ifdef _DEBUG


   int64_t impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


//   void impact::assert_ok() const
//   {
//
//      user::box::assert_ok();
//
//   }
//
//
//   void impact::dump(dump_context & dumpcontext) const
//   {
//
//      user::box::dump(dumpcontext);
//
//   }


   void impact::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(MESSAGE_CREATE,psender,this,&impact::on_message_create);
      MESSAGE_LINK(MESSAGE_DESTROY, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }
      
      auto psystem = acmesystem()->m_paurasystem;
      
      auto pnode = psystem->draw2d();
      
      auto pwritetext = pnode->write_text();

      m_pfontThomasBS_ = pwritetext->point_font("Fira Code", 24);

   }


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::handle(::topic * ptopic, ::context * pcontext)
   {

      ::user::impact::handle(ptopic, pcontext);

   }


   document * impact::get_document()
   {

      return dynamic_cast < document * >(::user::impact::get_document());

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      //pgraphics->fill_rectangle(rectangle_f64_dimension(100, 100, 100, 100), color::magenta);

      //return;

      ::rectangle_i32 rectangleClient;

      client_rectangle(rectangleClient);

      if (rectangleClient.is_empty())
      {

         return;

      }

      //pgraphics->fill_rectangle(rectangle_f64_dimension(100, 100, 100, 100), color::magenta);

      //return;


      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->fill_rectangle(rectangleClient, argb(128, 128, 128, 128));

      //return;

      ::color::color color_dk(dk_red());

      color_dk.alpha = 127;

#ifdef DEBUG_WORK

      ::rectangle_i32 rectangleDryProWithLove_Work(5, 5, 1915, 1075);

      pgraphics->fill_rectangle(rectangleDryProWithLove_Work, argb(255, 150, 200, 255));

#endif

      pgraphics->set_text_color(color_dk);

      pgraphics->set(m_pfontThomasBS_);

      pgraphics->set_text_rendering_hint(write_text::e_rendering_anti_alias);

      pgraphics->set_alpha_mode(draw2d::e_alpha_mode_blend);

      //pgraphics->text_out({ 10, 10 }, "psimpleapplication->m_pimpact->_001OnDraw(pgraphics);");

      ::synchronous_lock synchronouslockDocument(get_document()->synchronization());
      
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

      string strText;

      m_iSequence++;
      
      strText.format("psimpleapplication->m_pimpact->_001OnDraw(pgraphics); %d", m_iSequence);

      auto size = pgraphics->get_text_extent(strText);

      bool bFixedPosition = true;

      if (bFixedPosition)
      {

         point = { 10, 10 };

      }
      else
      {
       
         point.x =   random(0, (int)(rectangleClient.width() - size.cx));
         point.y =   random(0, (int)(rectangleClient.height() - size.cy*2));

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
         
         auto s = pgraphics->get_text_extent(strItem);

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
//      size = pgraphics->get_text_extent("TBS_");
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

      pgraphics->set_smooth_mode(::draw2d::e_smooth_mode_none);

      //pgraphics->fill_inset_rectangle({ 100, 200, 200, 300 }, argb(127, 255, 255, 0));

      //pgraphics->draw_inset_rectangle({ 100, 200, 200, 300 }, argb(127, 0, 255, 255));

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = client_rectangle();

      if(rectangleClient.is_empty())
      {

         return;

      }

      ::user::impact::on_layout(pgraphics);

   }


} // namespace simple_application



