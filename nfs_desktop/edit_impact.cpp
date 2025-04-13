#include "framework.h"
#include "edit_impact.h"
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


namespace app_simple_winnfsd_desktop
{


   edit_impact::edit_impact()
   {

      m_bMultiLine = false;

   }


   edit_impact::~edit_impact()
   {

   }



   void edit_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      edit_impact_base::handle(ptopic, phandlercontext);

   }


   void edit_impact::OnActivateImpact(bool bActivate, ::pointer<::user::impact>pActivateImpact, ::pointer<::user::impact>DeactiveImpact)
   {

      ::user::impact::OnActivateImpact(bActivate, pActivateImpact, DeactiveImpact);

      if (bActivate)
      {

         set_keyboard_focus();

      }

   }


   void edit_impact::_001OnUpdateEditUndo(::message::message * pmessage)
   {

      ::pointer<::message::command>pcommand(pmessage);

      _synchronous_lock synchronouslock(this->synchronization());

      _synchronous_lock slFile(m_ptree->m_peditfile->synchronization());

      pcommand->enable(m_ptree->m_peditfile->CanUndo());

   }


   void edit_impact::_001OnUpdateEditRedo(::message::message * pmessage)
   {

      ::pointer<::message::command>pcommand(pmessage);

      _synchronous_lock synchronouslock(this->synchronization());

      _synchronous_lock slFile(m_ptree->m_peditfile->synchronization());

      pcommand->enable(m_ptree->m_peditfile->GetRedoBranchCount() > 0);

   }


   void edit_impact::_001OnEditUndo(::message::message * pmessage)
   {

      edit_undo();

      pmessage->m_bRet = true;

   }


   void edit_impact::_001OnEditRedo(::message::message * pmessage)
   {

      edit_redo();

      pmessage->m_bRet = true;

   }


   void edit_impact::plain_edit_on_after_change_text(::draw2d::graphics_pointer & pgraphics, const ::action_context & context)
   {

      edit_impact_base::plain_edit_on_after_change_text(pgraphics, context);

      ::string str;

      get_text(str);

      get_app()->m_pathFolder = str;

   }


   void edit_impact::install_message_routing(::channel * pchannel)
   {

      edit_impact_base::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &edit_impact::on_message_create);

      add_command_prober("edit_undo", { this,  &edit_impact::_001OnUpdateEditUndo });
      add_command_handler("edit_undo", { this,  &edit_impact::_001OnEditUndo });
      add_command_prober("edit_redo", { this,  &edit_impact::_001OnUpdateEditRedo });
      add_command_handler("edit_redo", { this,  &edit_impact::_001OnEditRedo });


   }


   void edit_impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

   }


} // namespace app_simple_winnfsd_desktop



