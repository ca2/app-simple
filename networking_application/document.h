#pragma once


#include "acme/handler/item.h"
#include "base/user/user/document.h"


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_NETWORKING_APPLICATION document :
      public ::user::document
   {
   public:


      ::networking::address_pointer    m_paddressNetworkInterface;
      ::string                         m_strNetworkInterfaceAddress;
      ::pointer < ::item_array >       m_pitemaInterface;
      ::pointer < ::item_array >       m_pitemaComputer;


      document();
	   ~document() override;


	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;



      bool on_new_document() override;
      virtual bool on_open_document(const ::payload & payloadFile) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif

      //virtual void write(::binary_stream & stream) const override;

      void network_interface_discovery(::raw::index iItem);

   };


} // namespace app_simple_networking_application



