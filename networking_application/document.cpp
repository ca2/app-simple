#include "framework.h"
#include "document.h"
#include "computer_list2.h"
#include "interface_list2.h"
#include "application.h"
#include "acme/primitive/collection/_generic_array.h"
#include "apex/platform/system.h"
#include "apex/networking/networking.h"


namespace app_simple_networking_application
{


   document::document()
   {

   }


   document::~document()
   {

   }




   bool document::on_new_document()
   {

      return on_open_document("");

   }


   bool document::on_open_document(const ::payload & payloadFile)
   {

      m_pitemaInterface = acmesystem()->m_papexsystem->networking()->list_network_interfaces();

      m_pitemaComputer = acmesystem()->m_papexsystem->networking()->list_computers();

      return true;

   }


#ifdef _DEBUG


   int64_t document::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::document::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }

   int64_t document::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return  ::user::document::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void document::network_interface_discovery(::index iItem)
   {

      m_strNetworkInterfaceAddress.empty();

      m_paddressNetworkInterface = m_pitemaInterface->element_at(iItem);

      if (!m_paddressNetworkInterface)
      {

         return;

      }

      m_strNetworkInterfaceAddress = m_paddressNetworkInterface->get_display_number();

      auto pcomputerlist2 = get_typed_impact < computer_list2 >();

      if (pcomputerlist2)
      {

         pcomputerlist2->set_need_redraw();

         pcomputerlist2->post_redraw();

      }

   }


} // namespace app_simple_networking_application



