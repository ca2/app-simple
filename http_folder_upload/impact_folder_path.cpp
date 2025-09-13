#include "framework.h"
#include "impact_folder_path.h"
#include "tab_impact.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/handler/topic.h"
#include "acme/filesystem/file/file.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_system.h"
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


   impact_folder_path::impact_folder_path()
   {

      m_bMultiLine = false;
      m_pimpactpath = nullptr;

   }


   impact_folder_path::~impact_folder_path()
   {

   }



   void impact_folder_path::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      edit_impact_base::handle(ptopic, phandlercontext);

   }


   void impact_folder_path::OnActivateImpact(bool bActivate, ::pointer<::user::impact>pActivateImpact, ::pointer<::user::impact>DeactiveImpact)
   {

      ::user::impact::OnActivateImpact(bActivate, pActivateImpact, DeactiveImpact);

      if (bActivate)
      {

         set_keyboard_focus();

      }

   }


   void impact_folder_path::_001OnUpdateEditUndo(::message::message * pmessage)
   {

      ::pointer<::message::command>pcommand(pmessage);

      _synchronous_lock synchronouslock(this->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);

      _synchronous_lock slFile(m_ptree->m_peditfile->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);

      pcommand->enable(m_ptree->m_peditfile->CanUndo());

   }


   void impact_folder_path::_001OnUpdateEditRedo(::message::message * pmessage)
   {

      ::pointer<::message::command>pcommand(pmessage);

      _synchronous_lock synchronouslock(this->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);

      _synchronous_lock slFile(m_ptree->m_peditfile->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);

      pcommand->enable(m_ptree->m_peditfile->GetRedoBranchCount() > 0);

   }


   void impact_folder_path::_001OnEditUndo(::message::message * pmessage)
   {

      edit_undo();

      pmessage->m_bRet = true;

   }


   void impact_folder_path::_001OnEditRedo(::message::message * pmessage)
   {

      edit_redo();

      pmessage->m_bRet = true;

   }


   void impact_folder_path::plain_edit_on_after_change_text(::draw2d::graphics_pointer & pgraphics, const ::action_context & context)
   {

      edit_impact_base::plain_edit_on_after_change_text(pgraphics, context);

      ::string str;

      get_text(str);

      get_app()->m_pathFolder = str;

      get_app()->datastream()->set("folder", str);

   }


   void impact_folder_path::install_message_routing(::channel * pchannel)
   {

      edit_impact_base::install_message_routing(pchannel);

      USER_MESSAGE_LINK(::user::e_message_create, pchannel, this, &impact_folder_path::on_message_create);


   }


   void impact_folder_path::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      ::string strFolder;

      get_app()->datastream()->get("folder", strFolder);

      set_text(strFolder, ::e_source_initialize);

   }


} // namespace app_simple_http_folder_upload



