// From document.h by camilo on 2023-08-16 17:21 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/handler/item.h"
#include "base/user/user/document.h"


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION command_document :
      public ::user::document
   {
   public:


      ::pointer <::item_array >        m_pitemaCommand;
      ::index                          m_iCurrentCommand;

      ::string                         m_strCurrentAdapter;


      command_document();
      ~command_document() override;


      // void assert_ok() const override;
      // void dump(dump_context & dumpcontext) const override;



      bool on_new_document() override;
      virtual bool on_open_document(const ::payload & payloadFile) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif


      void run() override;

   };


} // namespace app_simple_networking_application



