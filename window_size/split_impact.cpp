// Created by camilo on 2026-09-06 01:08 <3ThomasBorregaardSørensen!! Mummi!! bilbo!!
#include "platform.h"
#include "application.h"
#include "split_impact.h"
#include "document.h"
#include "window_list_box_impact.h"
#include "window_size_list_box_impact.h"
#include "acme/constant/user_message.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "acme/platform/node.h"
#include "acme/prototype/mathematics/mathematics.h"
#include "acme/user/interface/message_box.h"
#include "aura/message/user.h"
#include "aura/graphics/draw2d/draw2d.h"


CLASS_DECL_AURA::color::color dk_red(); // <3 tbs


namespace app_simple_window_size
{


   split_impact::split_impact()
   {

      m_enonclient -= ::user::e_non_client_background;
      //m_iSequence = 0;
      m_bNeedFullRedrawOnResize = true;

      m_bDefaultClickHandling = true;

      m_bEmptyAreaIsClientArea = true;

   }


   split_impact::~split_impact()
   {

   }


#ifdef _DEBUG


   ::i64 split_impact::increment_reference_count()
   {

      return ::user::split_impact::increment_reference_count();

   }


   ::i64 split_impact::decrement_reference_count()
   {

      return ::user::split_impact::decrement_reference_count();

   }


#endif



   void split_impact::install_message_routing(::channel * psender)
   {

      ::user::split_impact::install_message_routing(psender);

      USER_MESSAGE_LINK(::user::e_message_create, psender, this, &split_impact::on_message_create);
      USER_MESSAGE_LINK(::user::e_message_destroy, psender, this, &split_impact::on_message_destroy);

   }


   void split_impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      //display();

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }


      //application()->show_about_box();


   }


   void split_impact::on_message_destroy(::message::message * pmessage)
   {

   }



   void split_impact::on_create_split_impact()
   {

      if (get_pane_count() > 0)
      {

         return;

      }


      SetPaneCount(2);

      SetSplitOrientation(e_orientation_vertical);

      auto preferredDensity = preferred_density();

      set_position_rate(0, 0.5);

      initialize_split_layout();

      m_pwindowlistboximpact = create_impact < window_list_box_impact >(nullptr, get_pane_holder(0), "window_list_box_impact");

      if (m_pwindowlistboximpact == nullptr)
      {

         output_error_message("Could not create window_list_box_impact");

      }



      m_pwindowsizelistboximpact = create_impact < window_size_list_box_impact >(nullptr, get_pane_holder(1), "window_list_box_impact");

      if (m_pwindowsizelistboximpact == nullptr)
      {

         output_error_message("Could not create window_size_list_box_impact");

      }

      m_pwindowsizelistboximpact->m_pwindowlistboximpact = m_pwindowlistboximpact;

   }



   void split_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      ::user::split_impact::handle(ptopic, phandlercontext);

   }


   document * split_impact::get_document()
   {

      return dynamic_cast <document *>(::user::split_impact::get_document());

   }




   bool split_impact::on_click(::item * pitem, ::user::mouse * pmouse)
   {

      //if (::is_set(pitem))
      //{

      //   if (pitem->m_item.m_eelement == ::e_element_client)
      //   {

      //      print_line("on_click : e_element_client");

      //      ::file::file_dialog_filter filter;

      //      filter.add({ "application.txt", "application.txt" });

      //      pick_single_file_to_open(filter, [this](::file::file_dialog * pdialog)
      //                       {

      //                          try
      //                          {

      //                             if (pdialog->m_patha.has_element())
      //                             {

      //                                auto memory = file()->as_memory(pdialog->m_patha.first());

      //                                auto size = memory.size();

      //                                informationf("got file with %d bytes", size);

      //                                file()->put_memory(m_papp->m_pathApplicationText, memory);

      //                             }

      //                          }
      //                          catch (...)
      //                          {

      //                             auto pmessagebox = message_box("No file loaded...");

      //                             pmessagebox->display(e_display_normal, {});

      //                          }

      //      });

      //      return true;

      //   }

      //}

      return ::user::split_impact::on_click(pitem, pmouse);

   }


} // namespace app_simple_window_size



