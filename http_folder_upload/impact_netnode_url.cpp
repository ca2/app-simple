#include "framework.h"
#include "impact_netnode_url.h"
#include "tab_impact.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/handler/topic.h"
#include "acme/filesystem/file/file.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "apex/filesystem/file/edit_file.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "aura/graphics/draw2d/draw2d.h"
#include "aura/message/user.h"
#include "aura/user/user/scroll_state.h"
#include "aura/user/user/plain_text_tree.h"
#include "aqua/audio/sound_track_player.h"
#include "aqua/audio/speaker.h"
#include "aqua/multimedia/multimedia.h"
#include "apex/database/_binary_stream.h"


namespace app_simple_http_folder_upload
{


   impact_netnode_url::impact_netnode_url()
   {

      m_bMultiLine = false;
      m_pimpactpath = nullptr;

   }


   impact_netnode_url::~impact_netnode_url()
   {

   }



   void impact_netnode_url::handle(::topic * ptopic, ::context * pcontext)
   {

      edit_impact_base::handle(ptopic, pcontext);

   }


   void impact_netnode_url::OnActivateImpact(bool bActivate, ::pointer<::user::impact>pActivateImpact, ::pointer<::user::impact>DeactiveImpact)
   {

      ::user::impact::OnActivateImpact(bActivate, pActivateImpact, DeactiveImpact);

      if (bActivate)
      {

         set_keyboard_focus();

      }

   }


   void impact_netnode_url::_001OnUpdateEditUndo(::message::message * pmessage)
   {

      ::pointer<::message::command>pcommand(pmessage);

      _synchronous_lock synchronouslock(this->synchronization());

      _synchronous_lock slFile(m_ptree->m_peditfile->synchronization());

      pcommand->enable(m_ptree->m_peditfile->CanUndo());

   }


   void impact_netnode_url::_001OnUpdateEditRedo(::message::message * pmessage)
   {

      ::pointer<::message::command>pcommand(pmessage);

      _synchronous_lock synchronouslock(this->synchronization());

      _synchronous_lock slFile(m_ptree->m_peditfile->synchronization());

      pcommand->enable(m_ptree->m_peditfile->GetRedoBranchCount() > 0);

   }


   void impact_netnode_url::_001OnEditUndo(::message::message * pmessage)
   {

      edit_undo();

      pmessage->m_bRet = true;

   }


   void impact_netnode_url::_001OnEditRedo(::message::message * pmessage)
   {

      edit_redo();

      pmessage->m_bRet = true;

   }


   void impact_netnode_url::plain_edit_on_after_change_text(::draw2d::graphics_pointer & pgraphics, const ::action_context & context)
   {

      edit_impact_base::plain_edit_on_after_change_text(pgraphics, context);

      ::string str;

      _001GetText(str);

      get_app()->m_pathUrl = str;

      get_app()->datastream()->set("url", str);

   }


   void impact_netnode_url::install_message_routing(::channel * pchannel)
   {

      edit_impact_base::install_message_routing(pchannel);

      MESSAGE_LINK(MESSAGE_CREATE, pchannel, this, &impact_netnode_url::on_message_create);


   }


   void impact_netnode_url::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      ::string strUrl;

      get_app()->datastream()->get("url", strUrl);

      _001SetText(strUrl, ::e_source_initialize);


   }


} // namespace app_simple_http_folder_upload



