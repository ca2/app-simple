#include "framework.h"
#include "main_frame.h"
#include "acme/platform/referencing_debugging.h"


namespace app_simple_form
{


   main_frame::main_frame()
   {

#if REFERENCING_DEBUGGING
      //m_bDefaultCreateToolbar = false;
      m_bIncludeCallStackTrace = true;
#endif

      window_enable_full_screen();

   }


   main_frame::~main_frame()
   {

   }


   long long main_frame::increment_reference_count()
   {

      return ::simple_main_frame::increment_reference_count();

//#if REFERENCING_DEBUGGING
//
//      critical_section_lock synchronouslock(&::system()->m_preferencingdebugging->m_criticalsection);
//
//#endif
//
//      auto c = ++m_countReference;
//
//#if REFERENCING_DEBUGGING
//
//      add_reference_item(true);
//
//#endif
//
//      return c;

   }


   long long main_frame::decrement_reference_count()
   {

      return ::simple_main_frame::decrement_reference_count();

   }


//   void main_frame::assert_ok() const
//   {
//
//      simple_frame_window::assert_ok();
//
//   }
//
//
//   void main_frame::dump(dump_context & dumpcontext) const
//   {
//
//      simple_frame_window::dump(dumpcontext);
//
//   }


   ::pointer < ::experience::frame > main_frame::frame_experience()
   {

      auto pframe = ::simple_main_frame::frame_experience(nullptr, "008", "LightBlue");

      return pframe;

   }


//   bool main_frame::has_pending_graphical_update()
//   {
//
//      return true;
//
//   }


   //bool main_frame::get_translucency(::user::enum_translucency & etranslucency, ::enum_element eelement, ::user::style_context * pcontext)
   //{

   //   if (m_bExplicitTranslucency)
   //   {

   //      etranslucency = m_etranslucency;

   //      return true;

   //   }

   //   //if (userstyle() != NULL)
   //   //{

   //   //   if (m_puserstyle->_001GetMainFrameTranslucency(etranslucency))
   //   //      return true;

   //   //}
   //   //etranslucency = ::user::e_translucency_present;

   //   ////      etranslucency = ::user::e_translucency_none;

   //   //return true;

   //   return ::user::style::get_translucency(etranslucency, eelement, pcontext);

   //}


} // namespace simple_form







