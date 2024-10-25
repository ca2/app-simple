#include "framework.h"
#include "impact_start_button.h"
#include "tab_impact.h"
#include "main_impact.h"
#include "impact.h"
#include "impact_path.h"
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


namespace app_simple_http_folder_upload
{


   impact_start_button::impact_start_button()
   {

      m_bEmptyAreaIsClientArea = true;
      m_pimpactpath = nullptr;

   }


   impact_start_button::~impact_start_button()
   {

   }



   void impact_start_button::handle(::topic * ptopic, ::context * pcontext)
   {

   }


   void impact_start_button::OnActivateImpact(bool bActivate, ::pointer<::user::impact>pActivateImpact, ::pointer<::user::impact>DeactiveImpact)
   {

      ::user::impact::OnActivateImpact(bActivate, pActivateImpact, DeactiveImpact);

      if (bActivate)
      {

         set_keyboard_focus();

      }

   }




   void impact_start_button::install_message_routing(::channel * pchannel)
   {

      button_impact_base::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &impact_start_button::on_message_create);



   }


   void impact_start_button::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      set_window_text("Start");
 


   }

   bool impact_start_button::on_click(::item * pitem)
   {

      enable_window(false);

      auto pimpactpath = m_pimpactpath;

      if (pimpactpath)
      {

         auto pmainimpact = pimpactpath->m_pmainimpact;

         if (pmainimpact)
         {

            auto pimpact = pmainimpact->m_pimpact;

            if (pimpact)
            {

               pimpact->start_synchronization();

            }

         }

      }

      return true;


   }


} // namespace app_simple_http_folder_upload



