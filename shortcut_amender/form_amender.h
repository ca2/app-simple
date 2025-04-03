#pragma once


#include "form.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender form_amender :
      virtual public ::app_simple_shortcut_amender::form
   {
   public:


      ::pointer<::user::still>             m_pstillTarget;
      ::pointer<::user::plain_edit>        m_peditTarget;


      form_amender();
      ~form_amender() override;


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      virtual void install_message_routing(::channel * psender) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnSendButton);
      DECLARE_MESSAGE_HANDLER(_001OnClearButton);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * pcontext) override;

      virtual string_array do_amender(const ::scoped_string & scopedstrTarget, const ::file::path & pathFolder, const ::scoped_string & scopedstrSource, bool bThumbnail);


   };


} // namespace simple_shortcut


