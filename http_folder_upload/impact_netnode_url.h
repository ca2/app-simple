#pragma once


#include "apex/platform/app_consumer.h"
#include "aqua/audio/text_to_speech_client.h"
#include "aura/user/user/plain_edit.h"
#include "berg/user/user/show.h"


namespace app_simple_http_folder_upload
{


   using edit_impact_base = ::app_consumer < application, ::user::show < ::user::plain_edit > >;


   class CLASS_DECL_APP_SIMPLE_HTTP_FOLDER_UPLOAD impact_netnode_url :
      virtual public edit_impact_base
   {
   public:


      impact_path * m_pimpactpath;


      impact_netnode_url();
      ~impact_netnode_url() override;

      void install_message_routing(::channel * pchannel) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      void plain_edit_on_after_change_text(::draw2d::graphics_pointer & pointer, const ::action_context & action_context) override;


      void OnActivateImpact(bool bActivate, ::pointer<impact>pActivateImpact, ::pointer<impact>DeactiveImpact) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);

      DECLARE_MESSAGE_HANDLER(_001OnUpdateEditUndo);
      DECLARE_MESSAGE_HANDLER(_001OnUpdateEditRedo);

      DECLARE_MESSAGE_HANDLER(_001OnEditUndo);
      DECLARE_MESSAGE_HANDLER(_001OnEditRedo);


   };


} // namespace app_core_plain_text




