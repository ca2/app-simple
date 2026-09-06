#pragma once


#include "apex/platform/app_consumer.h"
#include "axis/user/user/list_box.h"
#include "berg/user/user/show.h"


namespace app_simple_window_size
{


   class CLASS_DECL_APP_SIMPLE_WINDOW_SIZE window_size_list_box_impact :
      virtual public ::app_consumer < application, ::user::show < ::user::list_box > >
   {
   public:


      ::write_text::font_pointer       m_pfontThomasBS_;
      string                           m_strFont1;
      int                              m_iSequence;
      ::array < ::i32_size >           m_sizea;
      window_list_box_impact *         m_pwindowlistboximpact;

      window_size_list_box_impact();
      ~window_size_list_box_impact() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      virtual ::i64 increment_reference_count() override;
      virtual ::i64 decrement_reference_count() override;
#endif

      virtual ::i32_size current_window_size();
      

      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnClip(::draw2d::graphics_pointer & pdraw2dgraphics) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pdraw2dgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();

      void on_layout(::draw2d::graphics_pointer & pdraw2dgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      
      
      bool on_click(::item * pitem, ::user::mouse * pmouse) override;
      

      virtual void update_window_size_list();

   };


} // namespace app_simple_window_size


