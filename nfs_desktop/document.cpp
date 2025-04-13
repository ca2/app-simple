// From document.cpp by camilo on 2023-08-16 17:21 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "command.h"
#include "document.h"
//#include "computer_list2.h"
//#include "interface_list2.h"
#include "application.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/prototype/collection/_generic_array.h"
#include "apex/platform/node.h"
#include "apex/platform/system.h"
#include "apex/networking/networking.h"


namespace app_simple_winnfsd_desktop
{


   document::document()
   {

      m_iCurrentCommand = -1;

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

      __construct_new(m_pitemaCommand);

      auto lines = file_system()->lines(payloadFile);

      for (auto & line : lines)
      {

         auto pcommand = __create_new< command>();

         pcommand->m_strCommand = line;

         m_pitemaCommand->add(pcommand);

      }

      if (m_pitemaCommand->has_element())
      {

         m_iCurrentCommand = 0;

      }

      fork([this]()
         {

            run();

         });
      
      return true;

   }


#ifdef _DEBUG


   long long document::increment_reference_count()
   {

      return  ::user::document::increment_reference_count();

   }

   long long document::decrement_reference_count()
   {

      return  ::user::document::decrement_reference_count();

   }


#endif


   void document::run()
   {

      for (m_iCurrentCommand = 0; m_iCurrentCommand < m_pitemaCommand->size(); m_iCurrentCommand++)
      {

         ::pointer < command > pcommand = m_pitemaCommand->element_at(m_iCurrentCommand);

         ::string strCommand = pcommand->m_strCommand;

         id_update_all_impacts(id_update);


         if (strCommand.case_insensitive_begins_eat("select first network adapter"))
         {

            ::string str = node()->get_output("netsh interface show interface", 5_minute);

            ::string_array stra;

            stra.add_lines(str);

            for (auto & line : stra)
            {

               line.trim();

               if (line.case_insensitive_begins_eat("Enabled"))
               {

                  line.trim();

                  if (line.case_insensitive_begins_eat("Connected"))
                  {

                     line.trim();

                     if (line.case_insensitive_begins_eat("Dedicated"))
                     {

                        line.trim();

                        if (!line.case_insensitive_contains("vmware"))
                        {


                           if (line.has_character())
                           {

                              ::string strAdapter(line);

                              m_strCurrentAdapter = strAdapter;

                              pcommand->m_strResult = "Set current adapter to : " + strAdapter;

                              break;

                           }


                        }

                     }

                  }


               }

               information() << "Selected Adapter: " << m_strCurrentAdapter;

            }


         }
         else if (strCommand.case_insensitive_begins_eat("set ip address "))
         {

            ::string strCmd;

            strCmd = "netsh interface ip set address \"" + m_strCurrentAdapter + "\" static " + strCommand;

            ::string str = node()->get_output(strCmd, 5_minute);

            information() << str;

         }
         else if (strCommand.case_insensitive_begins_eat("set dns server "))
         {

            ::string_array stra;

            stra.explode(" ", strCommand);

            if (stra.size() == 1)
            {

               ::string strCmd;

               strCmd = "netsh interface ip set dnsserver \"" + m_strCurrentAdapter + "\" static " + strCommand + " validate=no";

               ::string str = node()->get_output(strCmd, 5_minute);

               information() << str;

            }
            else
            {

               for (int i = 1; i <= stra.size(); i++)
               {

                  ::string strDnsServer = stra[i - 1];

                  ::string strCmd;

                  if (i == 1)
                  {

                     strCmd = "netsh interface ip set dnsserver \"" + m_strCurrentAdapter + "\" static " + strDnsServer + " validate=no";


                  }
                  else
                  {

                     strCmd = "netsh interface ipv4 add dnsservers \"" + m_strCurrentAdapter + "\" address=\"" + strDnsServer + "\" index=" + ::as_string(i) + " validate=no";

                  }

                  ::string str = node()->get_output(strCmd, 5_minute);

                  information() << str;

               }


            }

         }

         id_update_all_impacts(id_update);

         preempt(5_s);

      }


      id_update_all_impacts(id_update);


   }


} // namespace app_simple_winnfsd_desktop



