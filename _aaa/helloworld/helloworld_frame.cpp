#include "framework.h"

#include <math.h>


namespace helloworld
{


   frame::frame(::particle * pparticle) :
      ::object(papp),
      simple_frame_window(papp)
   {

      window_enable_full_screen();

      m_bWindowFrame = !papp->m_bExperienceMainFrame;

   }


   frame::~frame()
   {

   }


   void frame::assert_ok() const
   {

	   simple_frame_window::assert_ok();

   }


   void frame::dump(dump_context & dumpcontext) const
   {

	   simple_frame_window::dump(dumpcontext);

   }


   ::experience::frame * frame::frame_experience()
   {

      auto pframe = papp->experience().frame_experience(NULL, "001");

      pframe->set_style("StyleLightBlue");

      return pframe;

   }


   bool frame::get_translucency(::user::ETranslucency & etranslucency)
   {

      etranslucency = ::user::TranslucencyPresent;

      return true;

   }


   bool frame::has_pending_graphical_update()
   {

      return true;

   }


} // namespace helloworld



