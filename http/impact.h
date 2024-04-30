// From impact.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/primitive/collection/int_map.h"
#include "apex/platform/app_consumer.h"
#include "base/user/user/impact.h"


namespace app_simple_http
{


   class CLASS_DECL_APP_SIMPLE_HTTP impact :
      virtual public ::app_consumer < application, ::user::impact >
   {
   public:


      ::pointer<main_impact>          m_pmainimpact;

      ::string m_strRequestResult;


      impact();
      ~impact() override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      document * get_document();

      bool on_impact_update() override;

      virtual void open_url(const ::scoped_string & scopedstrUrl);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


      bool on_click(::item * pitem) override;


      //void network_interface_discovery(::raw::index iItem);


   };


} // namespace app_simple_http


