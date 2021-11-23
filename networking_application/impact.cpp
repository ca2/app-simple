#include "framework.h"
#include <math.h>
#include "acme/constant/id.h"


namespace app_simple_networking_application
{


   impact::impact()
   {

      //payload(FONTSEL_IMPACT) = true;

      m_flagNonClient.erase(non_client_background);

      m_flagNonClient.erase(non_client_focus_rect);

      m_bClickDefaultMouseHandling = true;

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

      m_papplication->create_networking_application();

      {

         auto psignal = m_papplication->get_signal(id_simple_checkbox);

         psignal->add_handler(this);

      }

      {

         auto psignal = m_papplication->get_signal(id_no_client_frame);

         psignal->add_handler(this);

      }


      string strId = get_document()->m_pimpactsystem->m_id;

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


   void impact::handle(::subject * psubject, ::context * pcontext)
   {

      if (psubject->id() == id_simple_checkbox
         || psubject->id() == id_no_client_frame)
      {

         set_need_redraw();

      }

      ::user::impact::handle(psubject, pcontext);
   }


   ::user::document * impact::get_document()
   {

      return ::user::impact::get_document();

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::rectangle_i32 rectangleClient;


      get_client_rect(rectangleClient);


      pgraphics->fill_rectangle(rectangleClient, color::white);

   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = get_client_rect();

      if(rectangleClient.is_empty())
      {

         return;

      }

   }


   bool impact::on_click(const ::item& item)
   {

      auto phyperlink = __create_new <::hyperlink >();

      phyperlink->m_strLink.format("http://127.0.0.1:%d/", get_application()->networking_application()->m_iPort);

      phyperlink->run();

      return true;

   }


} // namespace app_simple_networking_application



