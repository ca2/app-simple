// Created by camilo on 2026-09-06 01:03 <3ThomasBorregaardSørensen!! Mummi!! bilbo!!
#pragma once


#include "berg/user/user/split_impact.h"
#include "apex/platform/app_consumer.h"


namespace app_simple_window_size
{


   class CLASS_DECL_APP_SIMPLE_WINDOW_SIZE split_impact :
      virtual public ::app_consumer < application, ::user::split_impact >
   {
   public:


      ::pointer < window_list_box_impact > m_pwindowlistboximpact;
      ::pointer < window_size_list_box_impact > m_pwindowsizelistboximpact;


      split_impact();
      ~split_impact() override;



#ifdef _DEBUG
      virtual ::i64 increment_reference_count() override;
      virtual ::i64 decrement_reference_count() override;
#endif

      virtual void install_message_routing(::channel * psender) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);

      void on_create_split_impact() override;


      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();



      bool on_click(::item * pitem, ::user::mouse * pmouse) override;


   };


} // namespace app_simple_window_size


