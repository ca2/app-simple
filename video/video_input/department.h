#pragma once



namespace video_input
{


   class CLASS_DECL_APP_SIMPLE_VIDEO department :
      virtual public ::apex::department
   {

   public:


      department();
      virtual ~department();


      virtual ::e_status initialize(::layered * pobjectContext) override;


   };


} // namespace department



