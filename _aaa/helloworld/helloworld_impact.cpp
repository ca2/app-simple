#include "framework.h"

#include <math.h>


namespace helloworld
{


   impact::impact(::particle * pparticle) :
      ::object(papp)
   {


   }


   impact::~impact()
   {

   }


   void impact::assert_ok() const
   {

      ::user::impact::assert_ok();

   }


   void impact::dump(dump_context & dumpcontext) const
   {

      ::user::impact::dump(dumpcontext);

   }


   void impact::install_message_handling(::message::dispatch * pdispatch)
   {

      ::user::impact::install_message_handling(pdispatch);

      IGUI_WIN_MSG_LINK(e_message_create,pdispatch,this,&impact::on_message_create);

   }


   void impact::on_message_create(signal_details * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if(pcreate->m_bRet)
         return;

   }


   void impact::on_update(::user::impact * pimpact, ::user::e_update eupdate, ::particle * pparticle)
   {

      __UNREFERENCED_PARAMETER(pSender);
      __UNREFERENCED_PARAMETER(lHint);
      __UNREFERENCED_PARAMETER(ptopic);

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      int_rectangle rectangleX;

      GetClientRect(rectangleX);

      ::write_text::font_pointer font(this_create);

      pfont->create_point_font(pnode->font_name(e_font_sans), minimum(rectangleX.height() / 5.0, rectangleX.width() / 10.0), 800);

      pgraphics->SelectObject(font);

      pgraphics->draw_text("Hello World!!", rectangleX, e_align_center);

   }



} // namespace helloworld



