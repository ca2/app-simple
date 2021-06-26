#pragma once


namespace simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_FORM simple_change_grub_default_entry_001 :
      virtual public simple_change_grub_default_entry
   {
   public:


      __composite(::user::still)             m_pstill;
      __composite(::user::plain_edit)        m_pedit;
      //__composite(::user::button)            m_pbuttonClear;
      __composite(::user::button)            m_pbuttonRestart;
      __composite(::user::list_box)          m_plistbox;


      simple_change_grub_default_entry_001();
      virtual ~simple_change_grub_default_entry_001();

      virtual void assert_valid() const override;
      virtual void dump(dump_context & dumpcontext) const override;


#ifdef DEBUG
      virtual int64_t add_ref(OBJ_REF_DBG_PARAMS) override;
      virtual int64_t dec_ref(OBJ_REF_DBG_PARAMS) override;
#endif

      virtual void install_message_routing(::channel * psender) override;

      ::file::path get_grub_folder_path();

      ::file::path get_grubenv_path(const ::file::path & pathGrubFolder);

      ::file::path get_grub_cfg_path(const ::file::path & pathGrubFolder);

      virtual ::e_status update_grub_entry_list(const ::file::path & pathGrubFolder);

      virtual string get_grub_saved_entry(const ::file::path& pathGrubFolder);

      virtual ::e_status set_grub_saved_entry(const ::file::path& pathGrubFolder, const string & strSavedEntry);

      DECLARE_MESSAGE_HANDLER(on_message_create);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      virtual void on_control_event(::user::control_event * pevent) override;


   };


} // namespace simple_change_grub_default_entry


