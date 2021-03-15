#include "framework.h"


namespace simple_app
{


   window::window()
   {


   }


   window::~window()
   {

   }


   void window::install_message_routing(::channel* pchannel)
   {

      ::user::interaction::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_close, pchannel, this, &window::_001OnClose);
      MESSAGE_LINK(e_message_display_change, pchannel, this, &window::_001OnDisplayChange);

   }


   void window::assert_valid() const
   {

      ::user::interaction::assert_valid();

   }


   void window::dump(dump_context & dumpcontext) const
   {

      ::user::interaction::dump(dumpcontext);

   }


   void window::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      pgraphics->set_alpha_mode(::draw2d::alpha_mode_blend);

      ::rectangle_i32 rectClient;

      get_client_rect(rectClient);

      auto pstyle = get_style(pgraphics);

      auto colorBackground = get_color(pstyle, ::user::e_element_background);

      pgraphics->fill_rectangle(rectClient, argb(127, 255, 255, 255));

      double dBase = (double) rectClient.minimum_signed_absolute_dimension() / 17.0;

      double x = dBase * 3;

      double y = dBase * 3;

      pgraphics->fill_solid_rect_dim(x, y, dBase * 5.0, dBase * 5.0, argb(127, 40, 150, 235));

      pgraphics->fill_solid_rect_dim(x + dBase * 6.0, y, dBase * 5.0, dBase * 5.0, argb(127, 40, 150, 235));

      pgraphics->fill_solid_rect_dim(x, y + dBase * 6.0, dBase * 11.0, dBase * 5.0, argb(127, 255, 110, 150));

      rectClient.deflate(dBase);

      for (int i = 0; i < dBase; i++)
      {

         pgraphics->draw_rectangle(rectClient, argb(255, 127, 127, 127));

         rectClient.deflate(1, 1);

      }

   }


   void window::_001OnClose(::message::message* pmessage)
   {

      papplication->close(::aura::end_app);

   }


   void window::_001OnDisplayChange(::message::message* pmessage)
   {

      ::rectangle_i32 rectWindow;

      _001InitialFramePosition(rectWindow, { 0.05, 0.05, 0.4, 0.4 });

      display(e_display_normal);

      place(rectWindow);

      set_need_layout();

      set_need_redraw();

      post_redraw();

   }



} // namespace simple_app



