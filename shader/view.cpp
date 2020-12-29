#include "framework.h"
#include <math.h>
#include "acme/const/id.h"


namespace simple_shader
{


   view::view()
   {

      m_iView = -1;

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
      ::user::interaction::install_simple_ui_default_mouse_handling(psender);
      MESSAGE_LINK(e_message_create,psender,this,&view::_001OnCreate);
      MESSAGE_LINK(e_message_destroy, psender, this, &view::_001OnDestroy);
      MESSAGE_LINK(e_message_key_down, psender, this, &view::_001OnKeyDown);

   }


   void view::_001OnCreate(::message::message * pmessage)
   {

      SCAST_PTR(::message::create,pcreate,pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      GetTopLevelFrame()->set_prodevian();

      auto pprocedureRedraw = __routine([this]()
         {

            set_need_redraw();

            post_redraw();

         });

      Application.add_routine(id_simple_checkbox, pprocedureRedraw);

      Application.add_routine(id_no_client_frame, pprocedureRedraw);

      auto estatus = __construct_new(m_prender);

      if(!estatus)
      {

         pcreate->set_fail();

         return;

      }

      m_prender->initialize_application_consumer();

      m_prender->m_pinteraction = this;

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

      m_prender->update_shader();


      {

         ::id id = id_simple_text;

         auto pproperty = Application.fetch_property(id);

         payload payload;

         if (Application.data_get(id, payload))
         {

            pproperty->convert(payload);

         }

         auto idRunnable = Application.translate_property_id(id);

         Application.add_routine(idRunnable, __routine([this, id]()
         {

            auto pproperty = fetch_property(id);

            m_prender->defer_load_fragment(pproperty->get_string());

         }));

      }


   }


   void view::_001OnDestroy(::message::message * pmessage)
   {

   }


   void view::_001OnKeyDown(::message::message* pmessage)
   {

      SCAST_PTR(::message::key, pkey, pmessage);

      if (pkey->m_ekey == ::user::key_s)
      {

         m_bSaveFrame = true;




      }


   }


   void view::on_subject(::promise::subject * psubject, ::promise::context * pcontext)
   {

      if (psubject->id() == id_simple_checkbox || psubject->id() == id_no_client_frame)
      {

         set_need_redraw();

      }

      ::user::impact::on_subject(psubject, pcontext);

   }


   ::user::document * view::get_document()
   {

      return ::user::impact::get_document();

   }


   bool view::keyboard_focus_is_focusable()
   {

      return true;

   }


   void view::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      if (m_bSaveFrame)
      {

         m_bSaveFrame = false;

         auto rectClient = get_client_rect();

         auto pimage = create_image(rectClient);

         ::draw2d::graphics_pointer pgraphics = pimage->get_graphics();

         m_prender->_001OnDraw(pgraphics);

         fork([this, pimage]()
            {

               save_image saveimage;

               saveimage.m_eformat = ::draw2d::format_png;

               string strDate = System.datetime().international().get_gmt_date_time(INTERNATIONAL_DATE_TIME_FORMAT_FOR_FILE);

               Application.image().save_image("image://app_simple_shader-" + strDate + ".png", pimage, &saveimage);

            });


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

      m_prender->on_layout(pgraphics);

   }


} // namespace simple_shader



