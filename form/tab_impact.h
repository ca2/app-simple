#pragma once


#include "base/user/user/tab_impact.h"
#include "aura/user/user/form_callback.h"


namespace app_simple_form
{


   class CLASS_DECL_APP_SIMPLE_FORM tab_impact :
      virtual public ::user::tab_impact,
      virtual public ::user::form_callback
   {
   public:


      ::user::split_impact *                            m_ptopviewLast;
      impact *                                          m_pimpactLast;
      string                                          m_strTopicTitle;


      ::pointer<::user::document>                            m_pdocMenu;


      tab_impact();
      ~tab_impact() override;


      void on_create_impact(::user::impact_data * pimpactdata) override;

      void install_message_routing(::channel * pchannel) override;

      // void assert_ok() const override;

      // void dump(dump_context & dumpcontext) const override;

      DECLARE_MESSAGE_HANDLER(on_message_create);

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      void on_change_cur_sel() override;


   };


} // namespace simple_form













