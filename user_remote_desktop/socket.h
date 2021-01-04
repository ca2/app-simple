// cs<3tbs!! 2020-11-28 21:16 BRT
#pragma once


namespace simple_video
{


   class CLASS_DECL_APP_SIMPLE_VIDEO socket :
      virtual public ::sockets::tcp_socket
   {
   public:


      socket(::sockets::base_socket_handler & h);
      virtual ~socket();


      virtual void on_read(const void * buf, memsize n) override;


   };


} //namespace simple_video



