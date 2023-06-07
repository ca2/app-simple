#pragma once


#include "acme/primitive/collection/int_map.h"
#include "apex/platform/app_consumer.h"
#include "base/user/user/impact.h"


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION impact :
      virtual public ::app_consumer < application, ::user::impact >
   {
   public:


      //::pointer<render>          m_prender;
      ::index_map < ::networking::address_pointer >      m_mapaddress;
      ::index_map < ::networking::address_pointer >      m_mapaddress2;


      ::networking::address_pointer m_paddressNetworkInterface;
      ::string m_strNetworkInterfaceAddress;


      impact();
      ~impact() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      ::user::document * get_document();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


      bool on_click(::item * pitem) override;


      void network_interface_discovery(::index iItem);


   };


} // namespace app_simple_networking_application


