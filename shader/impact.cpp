#include "framework.h"
#include <math.h>
#include "acme/constant/id.h"
#include "aura/graphics/draw2d/_draw2d.h"
#include "aura/graphics/draw2d/save_image.h"


namespace app_simple_shader
{


   impact::impact()
   {

      m_iView = -1;

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
      MESSAGE_LINK(e_message_key_down, psender, this, &impact::on_message_key_down);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      payload(FONTSEL_IMPACT) = true;

      top_level_frame()->set_prodevian();

      auto pprocedureRedraw = __routine([this]()
         {

            set_need_redraw();

            post_redraw();

         });

      auto papplication = get_application();

      papplication->add_routine(id_simple_checkbox, pprocedureRedraw);

      papplication->add_routine(id_no_client_frame, pprocedureRedraw);

      //auto estatus = 
      
      __construct_new(m_prender);

      //if(!estatus)
      //{

      //   pcreate->set_fail();

      //   return;

      //}

      //m_prender->initialize_application_consumer();

      m_prender->m_pinteraction = this;

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

      m_prender->update_shader();


      {

         ::id id = id_simple_text;

         auto pproperty = papplication->fetch_property(id);

         ::payload payload;

         if (papplication->data_get(id, payload))
         {

            pproperty->convert(payload);

         }

         auto idRunnable = papplication->translate_property_id(id);

         papplication->add_routine(idRunnable, __routine([this, id]()
         {

            auto pproperty = fetch_property(id);

            m_prender->defer_load_fragment(pproperty->string());

         }));

      }


   }


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::on_message_key_down(::message::message* pmessage)
   {

      auto pkey = pmessage->m_union.m_pkey;

      if (pkey->m_ekey == ::user::e_key_s)
      {

         m_bSaveFrame = true;




      }


   }


   void impact::handle(::subject * psubject, ::context * pcontext)
   {

      if (psubject->id() == id_simple_checkbox || psubject->id() == id_no_client_frame)
      {

         set_need_redraw();

      }

      ::user::impact::handle(psubject, pcontext);

   }


   ::user::document * impact::get_document()
   {

      return ::user::impact::get_document();

   }


   bool impact::keyboard_focus_is_focusable() const
   {

      return true;

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (m_bSaveFrame)
      {

         m_bSaveFrame = false;

         auto rectangleClient = get_client_rect();

         auto pimage = m_pcontext->context_image()->create_image(rectangleClient);

         ::draw2d::graphics_pointer pgraphics = pimage->get_graphics();

         m_prender->_001OnDraw(pgraphics);

         fork([this, pimage]()
            {

               save_image saveimage;

               saveimage.m_eformat = ::draw2d::format_png;

               auto psystem = m_psystem;

               auto pdatetime = psystem->datetime();

               string strDate = pdatetime->international().get_date_time(INTERNATIONAL_DATE_TIME_FORMAT_FOR_FILE);

               auto pcontext = m_pcontext;

               auto pcontextimage = pcontext->context_image();

               pcontextimage->save_image("image://app_simple_shader-" + strDate + ".png", pimage, &saveimage);

            });


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

      m_prender->on_layout(pgraphics);

   }


} // namespace simple_shader



