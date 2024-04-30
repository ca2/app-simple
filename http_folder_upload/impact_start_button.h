#pragma once


#include "apex/platform/app_consumer.h"
#include "aqua/audio/text_to_speech_client.h"
#include "aura/user/user/plain_edit.h"
#include "base/user/user/show.h"


namespace app_simple_http_folder_upload
{


   using button_impact_base = ::app_consumer < application, ::user::show < ::user::button > >;


   class CLASS_DECL_APP_SIMPLE_HTTP_FOLDER_UPLOAD impact_start_button :
      virtual public button_impact_base
   {
   public:


      impact_path * m_pimpactpath;


      impact_start_button();
      ~impact_start_button() override;

      void install_message_routing(::channel * pchannel) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      bool on_click(::item * pitem) override;

      void OnActivateImpact(bool bActivate, ::pointer<impact>pActivateImpact, ::pointer<impact>DeactiveImpact) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);


   };


} // namespace app_core_plain_text




