#include "framework.h"
#include <math.h>
#include "acme/const/id.h"


namespace simple_drawing
{


   view::view()
   {

      value(FONTSEL_IMPACT) = true;

      m_flagNonClient.remove(non_client_background);

      m_flagNonClient.remove(non_client_focus_rect);

   }


   view::~view()
   {

   }


   void view::assert_valid() const
   {

      user::box::assert_valid();

   }


   void view::dump(dump_context & dumpcontext) const
   {

      user::box::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t view::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return  ::user::impact::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t view::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return  ::user::impact::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void view::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&view::_001OnCreate);
      MESSAGE_LINK(e_message_destroy, psender, this, &view::_001OnDestroy);

   }


   void view::_001OnCreate(::message::message * pmessage)
   {

      SCAST_PTR(::message::create,pcreate,pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }


      Application.add_update(id_simple_checkbox, this);

      Application.add_update(id_no_client_frame, this);

      auto estatus = __construct_new(m_prender);

      if(!estatus)
      {

         pcreate->set_fail();

         return;

      }

      m_prender->m_pview = this;

      string strId = get_document()->m_pimpactsystem->m_strMatter;

      string strText;

      if(GetTypedParent<::user::split_view>() != nullptr)
      {

         if(GetTypedParent<::user::split_view>()->get_child_by_id("top_edit_view") != nullptr)
         {

            auto pinteraction = GetTypedParent<::user::split_view>()->get_child_by_id("top_edit_view");

            pinteraction->_001SetText(strText,::source_initialize);

         }

      }

   }


   void view::_001OnDestroy(::message::message * pmessage)
   {

   }


   void view::on_apply(::action * paction)
   {

      if (paction->id() == id_simple_checkbox
         || paction->id() == id_no_client_frame)
      {

         set_need_redraw();

      }

      ::user::impact::on_apply(paction);
   }


   ::user::document * view::get_document()
   {

      return ::user::impact::get_document();

   }


   void view::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (ThisApp.m_echeckNoClientFrame != ::check_checked)
      {

         ::rect rect = get_client_rect();

         for (index i = 0; i < 11; i++)
         {

            pgraphics->draw_rect(rect, ARGB(180, 80, 80, 80));

            rect.deflate(1, 1);

         }

      }

      m_prender->_001OnDraw(pgraphics);

   }


   void view::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectClient = get_client_rect();

      if(rectClient.is_empty())
      {

         return;

      }

      m_prender->m_rect = rectClient;

   }


} // namespace simple_drawing



