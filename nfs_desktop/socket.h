#pragma once


#include "apex/platform/app_consumer.h"
#include "apex/networking/netserver/socket.h"


namespace app_simple_winnfsd_desktop
{


   class application;
   class service;


   class CLASS_DECL_APP_SIMPLE_WINNFSD_DESKTOP socket :
      virtual public app_consumer < ::app_simple_winnfsd_desktop::application,  ::netserver::socket >
   {
   public:


      //bootstrap *          m_pbootstrap;


      socket();
      virtual ~socket();

      virtual void on_send_response() override;


   };


} // namespace app_simple_winnfsd_desktop


