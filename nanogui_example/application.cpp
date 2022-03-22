#include "framework.h"
#include "base/user/user/_user.h"
#include "aura/update.h"


namespace app_simple_nanogui_example
{


   application::application()
   {

      //os_message_box("Message", "Title", e_message_box_yes_no_cancel);

      //m_bLocalization = true;
      
      m_ppaneimpact = nullptr;

      m_strAppId = "app-simple/nanogui_example1";

      m_strAppName = "app-simple/nanogui_example1";

      m_strBaseSupportId = "app_simple_nanogui_example";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   void application::init_instance()
   {

      set_local_data();

      ::factory::add_factory_item <::app_simple_nanogui_example::document >();
      //::factory::add_factory_item <::app_simple_nanogui_example::simple_frame >();
      ::factory::add_factory_item <::app_simple_nanogui_example::impact >();
      ::factory::add_factory_item <::user::box >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
                               "main",
                               __type(document),
                               __type(simple_frame_window),
                               __type(impact)));

      __compose(m_ptemplateSimpleDrawingMain, pdoctemplate);

      auto psession = get_session();

      auto puser = psession->user();

      puser->document_manager()->add_document_template(pdoctemplate);

      //return true;

   }


   void application::term_application()
   {

      ::base::application::term_application();

   }


   void application::on_request(::create * pcreate)
   {

      if (m_ptemplateSimpleDrawingMain->get_document_count() == 0)
      {

         if(pcreate->m_bMakeVisible)
         {

            INFORMATION("pcreate->m_bMakeVisible");

         }
         else
         {

            INFORMATION("NOT pcreate->m_bMakeVisible");

         }

         m_ptemplateSimpleDrawingMain->do_request(pcreate);

         auto pdocument =  m_ptemplateSimpleDrawingMain->get_document();

         auto pimpact = pdocument->get_view();

         auto pframe = pimpact->get_top_level();

         pframe->place({ 50, 50, 1440 + 50, 900 + 50 });

         pframe->display();

         pframe->set_need_layout();

         pframe->set_need_redraw();

         pframe->post_redraw();



      }

      if (is_true("wfi_maximize"))
      {

         pcreate->m_pcommandline->payload("document").cast < document >()->get_type_impact < ::user::tab_view >()->top_level_frame()->sketch_prepare_window_maximize();

      }

      output_debug_string("\nfinished simple_application::on_request");

   }


   string application::preferred_experience()
   {

      return "nanogui";

   }


#ifdef _DEBUG


   int64_t application::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t application::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::object::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


} // namespace simple_application



