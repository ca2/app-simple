#include "framework.h"
#include "aura/application.h"
#include "aura/update.h"
#include "_video.h"
#include "video_input/_.h"



namespace simple_video
{


   application::application()
   {

      create_factory < ::video_input::video_input >();

      m_ptemplateSimpleDrawingMain = nullptr;

      m_ptabview = nullptr;

      m_strAppId = "app-simple/video";

      m_strAppName = "app-simple/video";

      m_strBaseSupportId = "ca2_flag";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   ::e_status application::create_video()
   {

      //auto estatus = __compose(m_psocketthread, __new(::netserver::socket_thread < socket >()));

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //m_psocketthread->m_strIp = "127.0.0.1";
      //m_psocketthread->m_iPort = 10009;

      //if (!m_psocketthread->begin())
      //{

      //   return ::error_failed;

      //}

      ////fork([this]()
      //  // {

      //      ::hyperlink::open_link("http://" + m_psocketthread->m_strIp + ":" + __str(m_psocketthread->m_iPort) + "/");

      //   //});

      //return estatus;

      return ::success;

   }


   ::type application::get_pane_view_type() const
   {

      return __type(tab_view);

   }


 /*  string application::get_hover_font() const
   {

      return "Helvetica";

   }*/


   ::e_status application::init_instance()
   {

      set_local_data();

      create_factory <::simple_video::document >();
      create_factory <::simple_video::frame >();
      create_factory <::simple_video::main_frame >();
      create_factory <::user::button_view >();
      create_factory <::simple_video::view >();
      create_factory <::simple_video::tab_view >();
      create_factory <::video_input::department >();




      default_toggle_check_handling(id_simple_checkbox);

      default_toggle_check_handling(id_no_client_frame);

      if (!::base::application::init_instance())
      {

         return false;

      }

      auto estatus = __compose(m_pdepartment);

      if (!estatus)
      {

         return estatus;

      }

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(main_frame),
                               get_pane_view_type()));

      m_ptemplateSimpleDrawingMain = pdoctemplate;

      add_document_template(pdoctemplate);

      default_data_save_handling(id_simple_checkbox);

      default_data_save_handling(id_no_client_frame);

      default_data_save_handling(id_simple_text);

      return true;

   }


   void application::term_application()
   {

      ::base::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

#if 0

#ifdef _DEBUG

      output_debug_string("_DEBUG build? (basis)");

      ASSERT(FALSE);

#else

      output_debug_string("RELEASE build? (stage)");

      ASSERT(FALSE);

#endif

#endif

      if (m_ptemplateSimpleDrawingMain->get_document_count() == 0)
      {

         if(pcreate->m_bMakeVisible)
         {

            INFO("pcreate->m_bMakeVisible");

         }
         else
         {

            INFO("NOT pcreate->m_bMakeVisible");

         }

         m_ptemplateSimpleDrawingMain->do_request(pcreate);

      }

      if (is_true("wfi_maximize"))
      {

         pcreate->m_pcommandline->m_varQuery["document"].cast < document >()->get_typed_view < ::user::tab_view >()->GetTopLevelFrame()->sketch_prepare_window_maximize();

      }

      output_debug_string("\nfinished simple_video::on_request");

   }


   string application::preferred_experience()
   {

      return ::aura::application::preferred_experience();

   }


#ifdef _DEBUG


   int64_t application::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t application::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   __pointer(view) application::create_simple_video_view(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
   {

      return pimpactParent->create_view < view >(pimpactdata);

   }


   ::id application::translate_property_id(const ::id & id)
   {

      if(id == "simple_checkbox")
      {

         return id_simple_checkbox;

      }
      else if(id == "simple_text")
      {

         return id_simple_text;

      }
      else if (id == "no_client_frame")
      {

         return id_no_client_frame;

      }

      return id;

   }


   __namespace_application_factory("app-simple/video");


} // namespace simple_video



