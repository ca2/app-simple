#include "framework.h"
#include <math.h>
#include "acme/id.h"
#include "aura/graphics/draw2d/_draw2d.h"
#include "example1.h"
#include "example2.h"
#include "example_icons.h"


namespace app_simple_nanogui_example
{


   main_window::main_window()
   {

      //m_pexampleapplication = nullptr;
      m_flagNonClient -= non_client_background;
      m_bClickDefaultMouseHandling = true;
      m_bEditDefaultHandling = true;

   }


   main_window::~main_window()
   {

      

   }


#ifdef _DEBUG


   int64_t main_window::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::user::main_window::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t main_window::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::user::main_window::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void main_window::assert_ok() const
   {

      user::main_window::assert_ok();

   }


   void main_window::dump(dump_context & dumpcontext) const
   {

      user::main_window::dump(dumpcontext);

   }


   void main_window::install_message_routing(::channel * psender)
   {

      ::user::main_window::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&main_window::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &main_window::on_message_destroy);

   }


   void main_window::on_message_create(::message::message * pmessage)
   {

      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      //set_prodevian();

      m_exampleapplicationa.add(new ExampleApplication1(this));
      m_exampleapplicationa.add(new ExampleApplication2(this));
      m_exampleapplicationa.add(new ExampleApplicationIcons(this));
      //start(m_pexampleapplication, this);

      set_current_application(0);

   }


   void main_window::on_message_destroy(::message::message * pmessage)
   {

   }


   bool main_window::keyboard_focus_is_focusable() const
   {

      return true;

   }


   void main_window::handle(::topic * ptopic, ::context * pcontext)
   {

      ::user::main_window::handle(ptopic, pcontext);

   }


   void main_window::set_current_application(int iIndex)
   {

      m_iCurrentApplication = iIndex;

      m_exampleapplicationa[iIndex]->m_puserinteraction = this;

      auto papplication = m_exampleapplicationa[iIndex].get();

#if !defined(_UWP)

      int cx = papplication->m_size.x() + 20;
      int cy = papplication->m_size.y() + 48;

      get_top_level()->set_size(cx, cy);

#endif

      set_appearance(papplication);

      get_top_level()->set_need_layout();

      set_need_layout();

      set_need_redraw();

      post_redraw();

   }


   void main_window::next_application()
   {

      auto iNextApplication = m_iCurrentApplication + 1;

      if (iNextApplication >= m_exampleapplicationa.get_size())
      {

         iNextApplication = 0;

      }

      set_current_application(iNextApplication);

   }


   void main_window::previous_application()
   {

      auto iPreviousApplication = m_iCurrentApplication - 1;

      if (iPreviousApplication < 0)
      {

         iPreviousApplication =  (int) m_exampleapplicationa.get_upper_bound();

      }

      set_current_application(iPreviousApplication);

   }


   void main_window::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::main_window::_001OnDraw(pgraphics);

   }


   void main_window::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = get_client_rect();

      if(rectangleClient.is_empty())
      {

         return;

      }

      ::user::main_window::on_layout(pgraphics);

   }


} // namespace simple_application


