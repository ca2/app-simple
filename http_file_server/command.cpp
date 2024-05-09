// From computer_list2.h by camilo on 2023-08-16 17:07 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "command.h"


namespace app_simple_http_file_server
{


      ::string command::get_text(::collection::index iSubItem)
      {

         switch (iSubItem)
         {
         case e_subitem_command:
            return m_strCommand;
         default:
            break;
         }

         return {};
      }


} // namespace app_simple_http_file_server



