#include "framework.h"
#include <math.h>
#include "acme/constant/id.h"


namespace simple_webserver
{


   impact::impact()
   {

      payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(non_client_background);

      m_flagNonClient.erase(non_client_focus_rect);

   }


   impact::~impact()
   {

   }


   void impact::assert_valid() const
   {

      user::box::assert_valid();

   }


   void impact::dump(dump_context & dumpcontext) const
   {

      user::box::dump(dumpcontext);

   }


#ifdef _DEBUG


   int64_t impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void impact::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&impact::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      //initialize_application_composer();

      m_papplication->create_webserver();

      {

         auto psubject = m_papplication->subject(id_simple_checkbox);

         psubject->add_listener(this);

      }

      {

         auto psubject = m_papplication->subject(id_no_client_frame);

         psubject->add_listener(this);

      }

      auto estatus = __construct_new(m_prender);

      if(!estatus)
      {

         pcreate->set_fail();

         return;

      }

      m_prender->m_pimpact = this;

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


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::on_subject(::subject::subject * psubject, ::subject::context * pcontext)
   {

      if (psubject->id() == id_simple_checkbox
         || psubject->id() == id_no_client_frame)
      {

         set_need_redraw();

      }

      ::user::impact::on_subject(psubject, pcontext);
   }


   ::user::document * impact::get_document()
   {

      return ::user::impact::get_document();

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (m_papplication->m_echeckNoClientFrame != ::check_checked)
      {

         ::rectangle_i32 rectangle = get_client_rect();

         for (index i = 0; i < 11; i++)
         {

            pgraphics->draw_inset_rectangle(rectangle, argb(180, 80, 80, 80));

            rectangle.deflate(1, 1);

         }

      }

      m_prender->_001OnDraw(pgraphics);

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = get_client_rect();

      if(rectangleClient.is_empty())
      {

         return;

      }

      m_prender->m_rectangle = rectangleClient;

   }


} // namespace simple_webserver


