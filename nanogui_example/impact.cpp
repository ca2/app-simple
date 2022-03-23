#include "framework.h"
#include <math.h>
#include "acme/id.h"
#include "aura/graphics/draw2d/_draw2d.h"
#include "example1.h"
#include "example2.h"
#include "example_icons.h"


namespace app_simple_nanogui_example
{


   impact::impact()
   {

      //m_pexampleapplication = nullptr;
      m_flagNonClient -= non_client_background;
      m_bClickDefaultMouseHandling = true;

   }


   impact::~impact()
   {

      

   }


#ifdef _DEBUG


   int64_t impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


   int64_t impact::decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS_DEF)
   {

      return ::user::impact::increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_ARGS);

   }


#endif


   void impact::assert_ok() const
   {

      user::box::assert_ok();

   }


   void impact::dump(dump_context & dumpcontext) const
   {

      user::box::dump(dumpcontext);

   }


   void impact::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      MESSAGE_LINK(e_message_create,psender,this,&impact::on_message_create);
      MESSAGE_LINK(e_message_destroy, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {


      __pointer(::message::create) pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      m_exampleapplicationa.add(new ExampleApplication1(this));
      m_exampleapplicationa.add(new ExampleApplication2(this));
      m_exampleapplicationa.add(new ExampleApplicationIcons(this));
      //start(m_pexampleapplication, this);

      set_current_application(0);

   }


   void impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void impact::handle(::topic * ptopic, ::context * pcontext)
   {

      ::user::impact::handle(ptopic, pcontext);

   }


   document * impact::get_document()
   {

      return dynamic_cast < document * >(::user::impact::get_document());

   }


   void impact::set_current_application(int iIndex)
   {

      m_iCurrentApplication = iIndex;

      m_exampleapplicationa[iIndex]->m_puserinteraction = this;

      auto papplication = m_exampleapplicationa[iIndex].get();

      m_pappearance = papplication;

      int cx = papplication->m_size.x() + 20;
      int cy = papplication->m_size.y() + 48;

      get_top_level()->set_size(cx, cy);

      get_top_level()->set_need_layout();

      set_need_layout();

      set_need_redraw();

      post_redraw();

   }


   void impact::next_application()
   {

      auto iNextApplication = m_iCurrentApplication + 1;

      if (iNextApplication >= m_exampleapplicationa.get_size())
      {

         iNextApplication = 0;

      }

      set_current_application(iNextApplication);

   }


   void impact::previous_application()
   {

      auto iPreviousApplication = m_iCurrentApplication - 1;

      if (iPreviousApplication < 0)
      {

         iPreviousApplication = m_exampleapplicationa.get_upper_bound();

      }

      set_current_application(iPreviousApplication);

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {


   }


   void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      auto rectangleClient = get_client_rect();

      if(rectangleClient.is_empty())
      {

         return;

      }

      ::user::impact::on_layout(pgraphics);

   }


} // namespace simple_application



