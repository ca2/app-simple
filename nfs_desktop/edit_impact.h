#pragma once


#include "apex/platform/app_consumer.h"
#include "aqua/audio/text_to_speech_client.h"
#include "aura/user/user/plain_edit.h"
#include "base/user/user/show.h"


namespace app_simple_winnfsd_desktop
{


   using edit_impact_base = ::app_consumer < application, ::user::show < ::user::plain_edit > >;


   class CLASS_DECL_APP_SIMPLE_WINNFSD_DESKTOP edit_impact :
      virtual public edit_impact_base
   {
   public:


      ::pointer < main_impact >           m_pmainimpact;


      edit_impact();
      ~edit_impact() override;

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




