#pragma once


#include "apex/platform/app_consumer.h"
#include "aura/user/user/form_callback.h"
#include "berg/user/user/tab_impact.h"


namespace app_simple_os_drag_and_drop
{


   class CLASS_DECL_APP_SIMPLE_OS_DRAG_AND_DROP tab_impact :
      virtual public ::app_consumer < application, ::user::tab_impact >,
      virtual public ::user::form_callback
   {
   public:


      ::user::split_impact *                            m_ptopviewLast;
      impact *                                          m_pviewTopic;
      string                                          m_strTopicTitle;


      ::pointer<::user::document>                     m_pdocMenu;


      tab_impact();
      virtual ~tab_impact();


      void on_create_impact(::user::impact_data * pimpactdata) override;

      void install_message_routing(::channel * pchannel) override;

      // void assert_ok() const override;

      // void dump(dump_context & dumpcontext) const override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      bool BaseOnControlEvent(::user::form_window * pimpact,::user::control_event * pevent);
      void on_change_cur_sel() override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

   };


} // namespace app_simple_os_drag_and_drop













