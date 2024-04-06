// From form_amender.h by camilo on 2023-03-15 18:48 <3ThomasBorregaardSorensen!!
#pragma once


#include "form.h"


namespace app_simple_shortcut_amender
{


   class CLASS_DECL_app_simple_shortcut_amender form_reset_icon :
      virtual public ::app_simple_shortcut_amender::form
   {
   public:




      form_reset_icon();
      ~form_reset_icon() override;


      //      // void assert_ok() const override;
      //      // void dump(dump_context & dumpcontext) const override;


#ifdef _DEBUG
      virtual int64_t increment_reference_count() override;
      virtual int64_t decrement_reference_count() override;
#endif

      virtual void install_message_routing(::channel * psender) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnSendButton);
      DECLARE_MESSAGE_HANDLER(_001OnClearButton);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::context * pcontext) override;

      virtual string_array reset_icon(const ::file::path & pathFolder, const ::scoped_string & scopedstrSource, bool bThumbnail);


   };


} // namespace simple_shortcut


