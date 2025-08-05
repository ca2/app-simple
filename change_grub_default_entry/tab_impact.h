#pragma once


#include "berg/user/user/tab_impact.h"
#include "aura/user/user/form_callback.h"


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_CHANGE_GRUB_DEFAULT_ENTRY tab_impact :
      virtual public ::user::tab_impact,
      virtual public ::user::form_callback
   {
   public:


      ::user::split_impact *                            m_ptopviewLast;
      impact *                                          m_pimpactLast;
      string                                          m_strTopicTitle;


      ::pointer<::user::document>                            m_pdocMenu;


      tab_impact();
      virtual ~tab_impact();


      void on_create_impact(::user::impact_data * pimpactdata) override;

      void install_message_routing(::channel * pchannel) override;

      // void assert_ok() const override;

      // void dump(dump_context & dumpcontext) const override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      bool BaseOnControlEvent(::user::form_window * pimpact,::user::control_event * phappening);
      void on_change_cur_sel() override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

   };


} // namespace app_simple_change_grub_default_entry













