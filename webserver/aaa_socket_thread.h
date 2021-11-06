// cs<3tbs!! 2020-11-28 21:20 BRT
#pragma once


namespace simple_webserver
{


   class CLASS_DECL_APP_SIMPLE_WEBSERVER socket_thread :
      virtual public ::netserver::socket_thread < socket >
   {
   public:


      socket_thread();
      virtual ~socket_thread();


   };


} // namespace simple_webserver



