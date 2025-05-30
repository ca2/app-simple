#pragma once


#include "base/user/user/split_impact.h"


namespace app_simple_nfs_desktop
{


   class CLASS_DECL_APP_SIMPLE_NFS_DESKTOP main_impact :
      virtual public ::user::split_impact
   {
   public:


      ::pointer < interface_list2 >       m_pinterfacelist2;
      ::pointer < computer_list2 >        m_pcomputerlist2;


      main_impact();
      ~main_impact() override;

      document * get_document();

      virtual void on_create_split_impact() override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

   };


} // namespace app_simple_nfs_desktop


