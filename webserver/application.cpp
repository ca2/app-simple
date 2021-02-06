#include "framework.h"
#include "aura/application.h"
#include "aura/update.h"
#include "_webserver.h"



namespace simple_webserver
{


   application::application() :
      m_echeckSimple(topic(id_simple_checkbox)),
      m_echeckNoClientFrame(topic(id_no_client_frame)),
      m_strSimple(topic(id_simple_text)),
      m_strMainTitle(topic(id_main_title))
   {

      m_pstrHoverFontFamilyName = nullptr;

      auto pproperty1 = find_property(id_simple_checkbox);

      bool bCheckOk = false;

      if(pproperty1->m_etype == type_enum_check)
      {

         auto pproperty = pproperty1;

         if(pproperty->m_etype == type_enum_check)
         {

            auto & echeck = pproperty->m_echeck;

            if(echeck == check_undefined)
            {

               bCheckOk = true;

            }

         }

      }

      if(!bCheckOk)
      {

         message_box("simple_check_box is not ok");

      }

      m_ptemplateSimpleDrawingMain = nullptr;

      m_ptabview = nullptr;

      m_strAppId = "app-simple/drawing";

      m_strAppName = "app-simple/drawing";

      m_strBaseSupportId = "ca2_flag";

      m_bLicense = false;

      m_bMultiverseChat = true;

      m_strMainTitle = "Simple Drawing";

   }


   application::~application()
   {

   }


   ::e_status application::create_webserver()
   {

      auto estatus = __compose(m_psocketthread, __new(::netserver::socket_thread < socket >()));

      if (!estatus)
      {

         return estatus;

      }

      m_psocketthread->m_strIp = "127.0.0.1";
      m_psocketthread->m_iPort = 10009;
      m_psocketthread->m_strCat = "cat://"+file_as_string("C:\\sensitive\\sensitive\\certificate\\localwebserver.app\\localwebserver.cat");
      m_psocketthread->m_strCipherList = "ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-RSA-AES128-SHA:ECDHE-RSA-RC4-SHA:DHE-RSA-AES256-SHA:DHE-RSA-AES128-SHA:RSA:SHA:3DES:!aNULL:!eNULL:!EXP:!LOW:!MD5:@STRENGTH";
      m_psocketthread->m_iSsl = 1;

      if (!m_psocketthread->begin())
      {

         return ::error_failed;

      }

      //fork([this]()
        // {

            //::hyperlink::open_link("http://" + m_psocketthread->m_strIp + ":" + __str(m_psocketthread->m_iPort) + "/");
      ::hyperlink::open_link("https://localwebserver.app:" + __str(m_psocketthread->m_iPort) + "/");

         //});

      return estatus;

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

      create_factory <::simple_webserver::document >();
      create_factory <::simple_webserver::frame >();
      create_factory <::simple_webserver::main_frame >();
      create_factory <::user::button_view >();
      create_factory <::simple_webserver::view >();
      create_factory <::simple_webserver::tab_view >();

      default_toggle_check_handling(id_simple_checkbox);

      default_toggle_check_handling(id_no_client_frame);

      if (!::base::application::init_instance())
      {

         return false;

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

      ASSERT(false);

#else

      output_debug_string("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      m_bMultiverseChat = !is_true("no_hello_edit");

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

         pcreate->m_pcommandline->m_varQuery["document"].cast < document >()->get_typed_view < ::user::tab_view >()->top_level_frame()->sketch_prepare_window_maximize();

      }

      output_debug_string("\nfinished simple_webserver::on_request");

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


   __pointer(view) application::create_simple_drawing_view(::user::impact* pimpactParent, ::user::impact_data * pimpactdata)
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


   __namespace_application_factory("app-simple/webserver");


} // namespace simple_webserver



