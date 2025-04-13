#include "framework.h"
#include "main_document.h"
//#include "computer_list2.h"
//#include "interface_list2.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/prototype/collection/_generic_array.h"
#include "apex/platform/system.h"
#include "apex/networking/networking.h"


namespace app_simple_winnfsd_desktop
{


   main_document::main_document()
   {

   }


   main_document::~main_document()
   {

   }


   bool main_document::on_new_document()
   {

      information() << "app_simple_winnfsd_desktop::document::on_new_document";

      return on_open_document("");

   }


   bool main_document::on_open_document(const ::payload & payloadFile)
   {

      information() << "app_simple_winnfsd_desktop::document::on_open_document";

      //m_pitemaInterface = system()->networking()->list_network_interfaces();

      //m_pitemaComputer = system()->networking()->list_computers();

      //id_update_all_impacts(id_update);

      return true;

   }


#ifdef _DEBUG


   long long main_document::increment_reference_count()
   {

      return  ::user::document::increment_reference_count();

   }

   long long main_document::decrement_reference_count()
   {

      return  ::user::document::decrement_reference_count();

   }


#endif


   void main_document::network_interface_discovery(::collection::index iItem)
   {

      //m_strNetworkInterfaceAddress.empty();

      //m_paddressNetworkInterface = m_pitemaInterface->element_at(iItem);

      //if (!m_paddressNetworkInterface)
      //{

      //   return;

      //}

      //m_strNetworkInterfaceAddress = m_paddressNetworkInterface->get_display_number();

      //auto pcomputerlist2 = get_typed_impact < computer_list2 >();

      //if (pcomputerlist2)
      //{

      //   pcomputerlist2->set_need_redraw();

      //   pcomputerlist2->post_redraw();

      //}

   }


} // namespace app_simple_winnfsd_desktop



