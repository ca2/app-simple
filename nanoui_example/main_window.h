// Created by camilo on 2022/03/18 03:45 AM <3ThomasBorregaardSorensen!! (Thomas Like number 5)
#pragma once
//Mummi at office during dawn
//youngmatti_
//VerFX
//strager
//j_blow
//rw_grim
//nanoui freelancing client


#include "aura/user/user/main_window.h"


namespace app_simple_nanoui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOUI_EXAMPLE main_window :
      virtual public ::user::main_window
   {
   public:


      int                                             m_iCloseButtonDraw;


      ::pointer_array < nanoui::Screen >             m_exampleapplicationa;
      int                                             m_iCurrentApplication;


      main_window();
      ~main_window() override;


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      long long increment_reference_count() override;
      long long decrement_reference_count() override;
#endif



      void install_message_routing(::channel * psender) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      virtual void set_current_application(int iIndex);

      virtual void next_application();

      virtual void previous_application();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


      bool keyboard_focus_is_focusable() override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      //virtual void _001DrawItem(::draw2d::graphics_pointer & pgraphics, ::item * pitem) override;


   };


} // namespace simple_application



