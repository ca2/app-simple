#include "framework.h"
#include <math.h>
#include "acme/const/id.h"


namespace simple_webserver
{


   view::view()
   {

      payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(non_client_background);

      m_flagNonClient.erase(non_client_focus_rect);

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

      //initialize_application_composer();

      m_papplication->create_webserver();

      m_papplication->delivery_for(id_simple_checkbox, this);

      m_papplication->delivery_for(id_no_client_frame, this);

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

            pinteraction->_001SetText(strText,::e_source_initialize);

         }

      }

   }


   void view::_001OnDestroy(::message::message * pmessage)
   {

   }


   void view::on_subject(::subject::subject * psubject, ::subject::context * pcontext)
   {

      if (psubject->id() == id_simple_checkbox
         || psubject->id() == id_no_client_frame)
      {

         set_need_redraw();

      }

      ::user::impact::on_subject(psubject, pcontext);
   }


   ::user::document * view::get_document()
   {

      return ::user::impact::get_document();

   }


   void view::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (m_papplication->m_echeckNoClientFrame != ::check_checked)
      {

         ::rectangle_i32 rectangle = get_client_rect();

         for (index i = 0; i < 11; i++)
         {

            pgraphics->draw_rectangle(rectangle, argb(180, 80, 80, 80));

            rectangle.deflate(1, 1);

         }

      }

      m_prender->_001OnDraw(pgraphics);

   }


   void view::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = get_client_rect();

      if(rectangleClient.is_empty())
      {

         return;

      }

      m_prender->m_rectangle = rectangleClient;

   }


} // namespace simple_webserver



