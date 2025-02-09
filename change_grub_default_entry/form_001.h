#pragma once


#include "form.h"


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_CHANGE_GRUB_DEFAULT_ENTRY form_001 :
      virtual public form
   {
   public:


      ::pointer<::user::still>             m_pstill;
      ::pointer<::user::plain_edit>        m_pedit;
      //::pointer<::user::button>            m_pbuttonClear;
      ::pointer<::user::button>            m_pbuttonRestart;
      ::pointer<::user::list_box>          m_plistbox;


      form_001();
      ~form_001() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      virtual void install_message_routing(::channel * psender) override;

      ::file::path get_grub_folder_path();

      ::file::path get_grubenv_path(const ::file::path & pathGrubFolder);

      ::file::path get_grub_cfg_path(const ::file::path & pathGrubFolder);

      virtual ::e_status update_grub_entry_list(const ::file::path & pathGrubFolder);

      virtual string get_grub_saved_entry(const ::file::path& pathGrubFolder);

      virtual ::e_status set_grub_saved_entry(const ::file::path& pathGrubFolder, const ::string & strSavedEntry);

      DECLARE_MESSAGE_HANDLER(on_message_create);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::context * pcontext) override;


   };


} // namespace app_simple_change_grub_default_entry


