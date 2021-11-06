// cs<3tbs!! 2020-11-28 21:16 BRT
#pragma once


namespace simple_webserver
{


   class CLASS_DECL_APP_SIMPLE_WEBSERVER socket :
      virtual public ::netserver::socket
   {
   public:


      socket();
      virtual ~socket();


      virtual void on_send_response() override;

   };


} //namespace simple_webserver



