// Created by camilo on 2023-08-16 ~17:10 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/handler/item.h"

namespace app_simple_winnfsd_desktop
{

   class CLASS_DECL_APP_SIMPLE_WINNFSD_DESKTOP command :
      virtual public ::item
   {
   public:


      enum enum_subitem
      {

         e_subitem_command,

      };

      ::string m_strCommand;

      ::string m_strResult;

      virtual ::string get_text(::collection::index iSubItem);


   };

} // namespace app_simple_winnfsd_desktop