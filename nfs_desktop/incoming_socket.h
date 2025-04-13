#pragma once


#include "application.h"
#include "apex/platform/app_consumer.h"
#include "apex/networking/sockets/httpd/incoming_socket.h"


namespace app_simple_winnfsd_desktop
{


   class application;
   class service;


   class CLASS_DECL_APP_SIMPLE_WINNFSD_DESKTOP incoming_socket :
      virtual public app_consumer < ::app_simple_winnfsd_desktop::application, ::httpd::incoming_socket >
   {
   public:


      //bootstrap * m_pbootstrap;


      incoming_socket();
      ~incoming_socket() override;

      //virtual void on_send_response() override;


   };


} // namespace app_simple_winnfsd_desktop


