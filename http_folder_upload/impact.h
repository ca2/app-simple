// From impact.cpp by camilo on 2023-08-12 20:49 <3ThomasBorregaardSorensen!!
#pragma once

#include "acme/filesystem/filesystem/listing.h"
#include "acme/primitive/collection/int_map.h"
#include "apex/platform/app_consumer.h"
#include "aura/user/user/scroll.h"
#include "base/user/user/show.h"


namespace app_simple_http_folder_upload
{


   class CLASS_DECL_APP_SIMPLE_HTTP_FOLDER_UPLOAD impact :
      virtual public ::app_consumer < application, ::user::scroll_impact >
   {
   public:


      ::pointer<main_impact>          m_pmainimpact;

      ::string m_strRequestResult;

      bool  m_bRunningSynchronization;

      ::file::listing m_listing;


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

      virtual void start_synchronization();

      virtual void do_synchronization();


      //void network_interface_discovery(::collection::index iItem);


   };


} // namespace app_simple_http_folder_upload


