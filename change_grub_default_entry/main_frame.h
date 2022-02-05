#pragma once


namespace app_simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_FORM main_frame :
      virtual public simple_main_frame
   {
   public:


      main_frame();
      virtual ~main_frame();


      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;


      virtual ::experience::frame * frame_experience() override;

   };


} // namespace app_simple_change_grub_default_entry












