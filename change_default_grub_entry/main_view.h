#pragma once


namespace simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_FORM main_view:
      virtual public ::application_consumer < application, ::user::split_view >
   {
   public:


      //::userex::top_view *    m_ptopview;
      view *                  m_pview;


      main_view();
      virtual ~main_view();


      virtual void assert_valid() const override;

      virtual void dump(dump_context & dumpcontext) const override;

      void on_create_split_impact() override;

      virtual void on_subject(::subject::subject * psubject, ::subject::context * pcontext) override;

      virtual bool BaseOnControlEvent(::user::control_event * pevent);


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace simple_change_grub_default_entry





