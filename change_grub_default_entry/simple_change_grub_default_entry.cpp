#include "framework.h"
#include <math.h>


namespace simple_change_grub_default_entry
{


   simple_change_grub_default_entry::simple_change_grub_default_entry()
   {


//      ON_WM_RBUTTONUP
//      {
//         //auto pmouse = pmessage->m_pmouse;
//         //::karaoke::lyric_view_lines & lyriclines = GetLyricLines();
//         //index iLine;
//         //index iToken;
//         //strsize iChar;
//         //class point_i32 ptCursor;
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
//            string strMatter = pcontext->m_papexcontext->dir().matter("popup_lyricview.xml");
//            ::file::path path = pcontext->m_papexcontext->defer_process_path(strMatter);
//            //__pointer(::message::mouse) p=pmouse->
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


   simple_change_grub_default_entry::~simple_change_grub_default_entry()
   {

   }


   void simple_change_grub_default_entry::assert_valid() const
   {

      ::user::form_view::assert_valid();

   }


   void simple_change_grub_default_entry::dump(dump_context & dumpcontext) const
   {

      ::user::form_view::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t simple_change_grub_default_entry::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t simple_change_grub_default_entry::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void simple_change_grub_default_entry::install_message_routing(::channel * psender)
   {

      ::user::form_view::install_message_routing(psender);

      MESSAGE_LINK(e_message_create, psender, this, &simple_change_grub_default_entry::on_message_create);

   }


   void simple_change_grub_default_entry::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

//      auto rectangleClient = get_client_rect();
//
//      pgraphics->fill_rectangle(rectangleClient, argb(127, 245, 250, 255));

   }


   void simple_change_grub_default_entry::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

   }


   void simple_change_grub_default_entry::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::form_view::on_layout(pgraphics);

   }


} // namespace simple_change_grub_default_entry



