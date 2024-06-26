#pragma once


#include "apex/platform/app_consumer.h"
#include "apex/networking/netserver/socket.h"


namespace app_simple_http_folder_upload
{


   class application;
   class service;


   class CLASS_DECL_APP_SIMPLE_HTTP_FOLDER_UPLOAD socket :
      virtual public app_consumer < ::app_simple_http_folder_upload::application,  ::netserver::socket >
   {
   public:


      //bootstrap *          m_pbootstrap;


      socket();
      virtual ~socket();

      virtual void on_send_response() override;


   };


} // namespace app_simple_http_folder_upload


