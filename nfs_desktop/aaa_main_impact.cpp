#include "framework.h"
#include "main_impact.h"
#include "interface_list2.h"
#include "computer_list2.h"
#include "document.h"
#include "application.h"
#include "acme/constant/id.h"


namespace app_simple_winnfsd_desktop
{


   main_impact::main_impact()
   {

      m_flagNonClient.add(e_non_client_background);
      m_flagNonClient.add(e_non_client_focus_rect);

   }


   main_impact::~main_impact()
   {

   }


   void main_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      ::user::split_impact::handle(ptopic, phandlercontext);

      ::user::split_impact::handle(ptopic, phandlercontext);

   }


   document * main_impact::get_document()
   {

      return dynamic_cast <document *> (::user::impact::get_document());

   }


   void main_impact::on_create_split_impact()
   {

      if (get_pane_count() > 0)
      {

         return;

      }

      int iPane;

      SetPaneCount(2);

      SetSplitOrientation(e_orientation_vertical);

      //auto preferredDensity = preferred_density();

      set_position_rate(0,0.5);

      initialize_split_layout();

      m_pinterfacelist2 = create_impact < interface_list2 >(nullptr, get_pane_holder(0), "interface_list2");

      if (m_pinterfacelist2 == nullptr)
      {

         output_error_message("Could not create interface_list2");

      }

      iPane = 1;

      m_pcomputerlist2 = create_impact < computer_list2 >(nullptr, get_pane_holder(iPane), "computer_list2");

      if (m_pcomputerlist2 == nullptr)
      {

         output_error_message("Could not create computer_list2");

      }


   }



} // namespace app_simple_winnfsd_desktop



