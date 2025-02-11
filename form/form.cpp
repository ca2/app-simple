#include "framework.h"
#include "form.h"
#include "acme/constant/message.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/message/user.h"


namespace app_simple_form
{


   form::form()
   {


//      ON_WM_RBUTTONUP
//      {
//         //auto pmouse = pmessage->m_union.m_pmouse;
//         //::karaoke::lyric_impact_lines & lyriclines = GetLyricLines();
//         //index iLine;
//         //index iToken;
//         //character_count iChar;
//         //class int_point ptCursor;
//         //ptCursor = pmouse->m_pt;
//         //if (m_lyrictemplatelines.hit_test(ptCursor, iLine, iToken, iChar)
//         //   == ::user::e_line_hit_link)
//         //{
//         //   string str;
//         //   lyriclines.GetLink(str, iLine, iToken, iChar);
//         //   m_strCurrentLink = str;
//         //   //::user::menu menu(this);
//         //}
//         //else
//         {
//            //            bool bTemporary =get_task()->m_bTemporary;
//            //            get_task()->m_bTemporary = true;
//            string strMatter = directory()->matter("popup_lyricview.xml");
//            ::file::path path = m_papplication->defer_process_matter_path(strMatter);
//            //::pointer<::message::mouse> p=pmouse->
//            //main_async([this,p]()
//            //{
//
//            // g_track_popup_lyricview(this, pmouse);
//
//            // });
////               get_task()->m_bTemporary = bTemporary;
//         }
//
//         pmouse->m_bRet = true;
//
//      };

   }


   form::~form()
   {

   }


//   void form::assert_ok() const
//   {
//
//      ::user::form_impact::assert_ok();
//
//   }
//
//
//   void form::dump(dump_context & dumpcontext) const
//   {
//
//      ::user::form_impact::dump(dumpcontext);
//
//   }


#ifdef _DEBUG


   long long form::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   long long form::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   void form::install_message_routing(::channel * psender)
   {

      ::user::form_impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &form::on_message_create);

   }


   void form::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleX = this->rectangle();

      pgraphics->fill_rectangle(rectangleX, ::color::white);

   }


   void form::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

   }


   void form::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_impact::on_layout(pgraphics);

   }


} // namespace simple_form



