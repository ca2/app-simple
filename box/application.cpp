#include "framework.h"
#include "apex/future.h"
#include "aura/application.h"


namespace simple_message_box
{


   application::application()
   {

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

      add_process(e_future_finish, __process([=](const payload& payload)
         {

            auto pprocessa = processa(e_future_finish);

            if (payload == IDNO)
            {

               message_box(
                  "Simple Message Box!! (message_box).<br><br>Finish?",
                  nullptr,
                  e_message_box_yes_no | e_message_box_icon_information,
                  pprocessa->first());

            }
            else
            {

               finish(get_context());

            }

         }));

      send_payload(e_future_finish, IDNO);

   }


   __namespace_application_factory("app-simple/box");


} // namespace simple_message_box





