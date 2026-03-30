// From app_simple_application/impact.cpp to app_simple_about_the_operationg_system/main_impact.cpp by
//    camilo on 2026-03-30 17:49 <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "main_impact.h"
#include "document.h"
#include "acme/constant/user_message.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/platform/node.h"
#include "acme/prototype/mathematics/mathematics.h"
#include "application.h"
#include "aura/graphics/draw2d/draw2d.h"
#include "aura/message/user.h"


CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


namespace app_simple_about_the_operating_system
{


   main_impact::main_impact()
   {

      m_flagNonClient -= e_non_client_background;
      m_iSequence = 0;
      m_bNeedFullRedrawOnResize = true;

      m_bDefaultClickHandling = true;

      m_bEmptyAreaIsClientArea = true;
   }


   main_impact::~main_impact() {}


#ifdef _DEBUG


   long long main_impact::increment_reference_count() { return ::user::impact::increment_reference_count(); }


   long long main_impact::decrement_reference_count() { return ::user::impact::decrement_reference_count(); }


#endif


   void main_impact::install_message_routing(::channel *psender)
   {

      ::user::impact::install_message_routing(psender);

      USER_MESSAGE_LINK(::user::e_message_create, psender, this, &impact::on_message_create);
      USER_MESSAGE_LINK(::user::e_message_destroy, psender, this, &impact::on_message_destroy);
   }


   void main_impact::on_message_create(::message::message *pmessage)
   {

      ::pointer<::message::create> pcreate(pmessage);

      // display();

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;
      }


      // application()->show_about_box();
   }


   void main_impact::on_message_destroy(::message::message *pmessage) {}


   void main_impact::handle(::topic *ptopic, ::handler_context *phandlercontext)
   {

      ::user::impact::handle(ptopic, phandlercontext);
   }


   document *main_impact::get_document() { return dynamic_cast<document *>(::user::impact::get_document()); }


   void main_impact::_001OnClip(::draw2d::graphics_pointer &pgraphics) {}


   void main_impact::_001OnDraw(::draw2d::graphics_pointer &pgraphics)
   {

      auto rectangleX = this->rectangle();

      if (rectangleX.is_empty())
      {

         return;
      }

      //      if (pgraphics->payload("set_transparent") == "set_transparent")
      //      {
      //
      //         information() << "set_transparent called";
      //
      //      }
      //      else
      //      {
      //
      //         information() << "set_transparent NOT called!!";
      //
      //      }

      ::double_rectangle rectangleClipBox;

      // pgraphics->reset_clip();

      // pgraphics->get_clip_box(rectangleClipBox);

      auto matrix = pgraphics->m_matrix;

      // auto origin = pgraphics->origin();

      auto opacity = ::opacity(48);

      pgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);

      pgraphics->fill_rectangle(rectangleX, argb(208, 0, 0, 0));

      ::color::color color_dk(dk_red());

#ifdef DEBUG_WORK

      ::int_rectangle rectangleDryProWithLove_Work(5, 5, 1915, 1075);

      pgraphics->fill_rectangle(rectangleDryProWithLove_Work, argb(255, 150, 200, 255));

#endif

      pgraphics->set_text_color(color_dk);

      auto psystem = system();

      auto pnode = psystem->draw2d();

      auto pwritetext = pnode->write_text();

      auto fontsize = ::write_text::font_size(48.0 * rectangleX.height() / 1'080, e_unit_pixel);

      m_pfontThomasBS_ = pwritetext->font("Fira Code", fontsize);

      pgraphics->set(m_pfontThomasBS_);

      pgraphics->set_text_rendering_hint(write_text::e_rendering_anti_alias);

      pgraphics->set_alpha_mode(draw2d::e_alpha_mode_blend);

      _synchronous_lock synchronouslockDocument(get_document()->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);

      auto stra = m_papp->get_operating_system_information_lines();

      double x = 0.;

      double y = 0.;

      ::int_point point;

      string strText;

      m_iSequence++;

      strText.formatf("psimpleapplication->m_pimpact->_001OnDraw(pgraphics); %d", m_iSequence);

      auto size = pgraphics->get_text_extent(strText);

      bool bFixedPosition = true;

      if (bFixedPosition)
      {

         point = {10, 10};
      }
      else
      {

         point.x = mathematics()->random(0, (int)(rectangleX.width() - size.cx));
         point.y = mathematics()->random(0, (int)(rectangleX.height() - size.cy * 2));
      }

      ::color::color color;

      opacity = ::opacity(208);

      for (auto &strItem: stra)
      {

         
            color = color::white;

         color &= opacity;

         pgraphics->set_text_color(color);

         pgraphics->text_out(point.x, point.y + y, strItem);

         auto s = pgraphics->get_text_extent(strItem);

         
         y += size.cy;


      }

      pgraphics->set_smooth_mode(::draw2d::e_smooth_mode_none);
   }


   void main_impact::on_layout(::draw2d::graphics_pointer &pgraphics)
   {

      auto rectangleX = this->rectangle();

      if (rectangleX.is_empty())
      {

         return;
      }

      ::user::impact::on_layout(pgraphics);

      setup_default_client_area_user_item();
   }


   bool main_impact::on_click(::item *pitem, ::user::mouse *pmouse)
   {

      //if (::is_set(pitem))
      //{

      //   if (pitem->m_item.m_eelement == ::e_element_client)
      //   {

      //      print_line("on_click : e_element_client");

      //      ::file::file_dialog_filter filter;

      //      filter.add({"application.txt", "application.txt"});

      //      pick_single_file_to_open(filter,
      //                               [this](::file::file_dialog *pdialog)
      //                               {
      //                                  try
      //                                  {

      //                                     if (pdialog->m_patha.has_element())
      //                                     {

      //                                        auto memory = file()->as_memory(pdialog->m_patha.first());

      //                                        auto size = memory.size();

      //                                        informationf("got file with %d bytes", size);

      //                                        file()->put_memory(m_papp->m_pathApplicationText, memory);
      //                                     }
      //                                  }
      //                                  catch (...)
      //                                  {

      //                                     auto pmessageboxpayload = message_box("No file loaded...");

      //                                     post(pmessageboxpayload);
      //                                  }
      //                               });

      //      return true;
      //   }
      //}

      return ::user::impact::on_click(pitem, pmouse);
   }


} // namespace app_simple_application
