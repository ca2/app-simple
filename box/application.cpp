#include "framework.h"
#include "apex/future.h"
#include "aura/application.h"


namespace simple_message_box
{


   application::application()
   {
      
      m_bImaging = false;
      
      m_bWriteText = false;
      
      m_strAppId = "app-simple/box";

      m_strAppName = "app-simple/box";

      m_strBaseSupportId = "app_simple_box";

   }


   application::~application()
   {


   }


   void application::on_request(::create * pcreate)
   {

      m_strAppName = "Simple Message Box!!";

      show_message_box();

      //add_process(e_process_finish, __process([=](const ::payload & payload)
      //   {

      //      auto pprocessa = processa(e_process_finish);

      //      if (payload == e_dialog_result_no)
      //      {

      //      }
      //      else
      //      {

      //         finish();

      //      }

      //   }));

      //::id id(e_process_finish);

      //::payload payload(e_dialog_result_no);

      //send_payload(id, payload);

   }


   void application::show_message_box()
   {

      message_box(
         "Simple Message Box!! (message_box).<br><br>Finish?",
         nullptr,
         e_message_box_yes_no | e_message_box_icon_information
      )->then([this](auto future)
      {

         if (future->m_edialogresult == e_dialog_result_yes)
         {

            _001TryCloseApplication();

         }
         else
         {

            show_message_box();

         }

      });

      



   }


   __namespace_application_factory("app-simple/box");


} // namespace simple_message_box





