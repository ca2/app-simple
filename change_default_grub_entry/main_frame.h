#pragma once


namespace simple_change_grub_default_entry
{


   class CLASS_DECL_APP_SIMPLE_FORM main_frame :
      virtual public simple_main_frame
   {
   public:


      main_frame();
      virtual ~main_frame();


      virtual void assert_valid() const override;
      virtual void dump(dump_context & dumpcontext) const override;


      virtual ::experience::frame * experience_get_frame() override;

   };


} // namespace simple_change_grub_default_entry












