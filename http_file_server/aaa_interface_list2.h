// From impact.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/prototype/collection/int_map.h"
#include "apex/platform/app_consumer.h"
#include "base/user/user/show.h"
#include "core/user/user/list2.h"


namespace app_simple_http_file_server
{


   class CLASS_DECL_APP_SIMPLE_HTTP_FILE_SERVER interface_list2 :
      virtual public ::app_consumer < application, ::user::show < ::user::list2 > >
   {
   public:


      ////::pointer<render>          m_prender;
      ////::index_map < ::networking::address_pointer >      m_mapaddress;
      //::index_map < ::networking::address_pointer >      m_mapaddress2;


      //::networking::address_pointer m_paddressNetworkInterface;
      //::string m_strNetworkInterfaceAddress;


      interface_list2();
      ~interface_list2() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();

      bool on_impact_update() override;


      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


      bool on_click(::item * pitem) override;


      

      //void network_interface_discovery(::collection::index iItem);


   };


} // namespace app_simple_http_file_server


