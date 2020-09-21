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

      add(e_future_finish, [=](const var& var)
         {

            auto pcallbacks = futures(e_future_finish);

            if (var == "no")
            {

               message_box(
                  "Simple Message Box!! (message_box).<br><br>Finish?",
                  nullptr,
                  message_box_yes_no | message_box_icon_information,
                  pcallbacks->first());

            }
            else
            {

               set_finish();

            }

         });

      send(e_future_finish, "no");

   }


   __namespace_application_factory("app-simple/box");


} // namespace simple_message_box





