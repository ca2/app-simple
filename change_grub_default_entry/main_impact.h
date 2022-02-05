#pragma once


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_FORM main_impact:
      virtual public ::application_consumer < application, ::user::split_view >
   {
   public:


      //::userex::top_view *    m_ptopview;
      impact *                  m_pimpact;


      main_impact();
      ~main_impact() override;


      void assert_valid() const override;

      void dump(dump_context & dumpcontext) const override;

      void on_create_split_impact() override;

      virtual void handle(::topic * ptopic, ::context * pcontext) override;

      //virtual bool BaseOnControlEvent(::user::control_event * pevent);


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace app_simple_change_grub_default_entry





