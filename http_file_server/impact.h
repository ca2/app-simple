// From impact.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/prototype/collection/int_map.h"
#include "apex/platform/app_consumer.h"
#include "base/user/user/impact.h"


namespace app_simple_http_file_server
{


   class CLASS_DECL_APP_SIMPLE_HTTP_FILE_SERVER impact :
      virtual public ::app_consumer < application, ::user::impact >
   {
   public:


      ::pointer<main_impact>          m_pmainimpact;

      ::string m_strRequestResult;


      impact();
      ~impact() override;


#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();

      bool on_impact_update() override;

      virtual void open_url(const ::scoped_string & scopedstrUrl);

      void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


      bool on_click(::item * pitem, ::user::mouse * pmouse) override;


      //void network_interface_discovery(::collection::index iItem);


   };


} // namespace app_simple_http_file_server


