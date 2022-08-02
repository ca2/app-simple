#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif


namespace app_simple_box
{


   application::application()
   {
      
      m_bImaging = false;
      m_ptemplateAppSimpleBoxMain = nullptr;
      
      //m_bWriteText = false;
      
      m_strAppId = "app-simple/box";

      m_strAppName = "app-simple/box";

      m_strBaseSupportId = "app_simple_box";

   }


   application::~application()
   {


   }


   void application::init_instance()
   {

      set_local_data();

      ::factory::add_factory_item <::app_simple_box::document >();
      ::factory::add_factory_item <::app_simple_box::main_frame >();
      ::factory::add_factory_item <::app_simple_box::impact >();

      ::base::application::init_instance();

      //if (!::base::application::init_instance())
      //{

      //   return false;

      //}

      auto pdoctemplate = __new(::user::single_document_template(
         "main",
         __type(document),
         __type(main_frame),
         __type(impact)));

      m_ptemplateAppSimpleBoxMain = pdoctemplate;

      add_document_template(pdoctemplate);

      default_data_save_handling("simple_checkbox");

      default_data_save_handling("no_client_frame");

      default_data_save_handling("simple_text");

      //return true;

   }




   void application::on_request(::create * pcreate)
   {

      m_strAppName = "Simple Message Box!!";

      if (m_ptemplateAppSimpleBoxMain->get_document_count() <= 0)
      {

         m_ptemplateAppSimpleBoxMain->do_request(pcreate);

      }

   }


} // namespace app_simple_box



