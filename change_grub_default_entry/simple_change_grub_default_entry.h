#pragma once


namespace simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_FORM simple_change_grub_default_entry :
      virtual public ::user::form_view
   {
   public:


      tab_view *                          m_ptabview;
      string                              m_strFont;
      int                                 m_iId;


      simple_change_grub_default_entry();
      virtual ~simple_change_grub_default_entry();

      virtual void assert_valid() const override;
      virtual void dump(dump_context & dumpcontext) const override;


      void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

#ifdef DEBUG
      virtual int64_t add_ref(OBJ_REF_DBG_PARAMS) override;
      virtual int64_t dec_ref(OBJ_REF_DBG_PARAMS) override;
#endif

      virtual void install_message_routing(::channel * psender) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

   };


} // namespace simple_change_grub_default_entry


