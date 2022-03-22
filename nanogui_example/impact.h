// Created by camilo on 2022/03/18 03:45 AM <3ThomasBorregaardSørensen!! (Thomas Like number 5)
#pragma once
//Mummi at office during dawn
//youngmatti_
//VerFX
//strager
//j_blow
//rw_grim
//nanogui freelancing client


namespace app_simple_nanogui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE impact :
      virtual public ::app_consumer < application, ::user::impact >
   {
   public:

      array < ::nanogui::ref < nanogui::Screen > > m_exampleapplicationa;
      int         m_iCurrentApplication;

      impact();
      ~impact() override;

      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif



      void install_message_routing(::channel * psender) override;

      void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      document * get_document();

      virtual void set_current_application(int iIndex);

      virtual void next_application();

      virtual void previous_application();

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


   };


} // namespace simple_application



