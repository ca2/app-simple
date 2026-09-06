#include "platform.h"
#include "window_list_box_impact.h"
#include "window_size_list_box_impact.h"
#include "document.h"
#include "application.h"
#include "acme/accessibility/accessibility.h"
#include "acme/accessibility/main_window.h"
#include "acme/constant/user_message.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "acme/platform/node.h"
#include "acme/prototype/mathematics/mathematics.h"
#include "acme/user/interface/message_box.h"
#include "aura/message/user.h"
#include "aura/graphics/draw2d/draw2d.h"


CLASS_DECL_AURA ::color::color dk_red(); // <3 tbs


namespace app_simple_window_size
{


   window_size_list_box_impact::window_size_list_box_impact()
   {

      m_pwindowlistboximpact = nullptr;
      m_enonclient -= ::user::e_non_client_background;
      m_iSequence = 0;
      m_bNeedFullRedrawOnResize = true;
      
      m_bDefaultClickHandling = true;
      
      m_bEmptyAreaIsClientArea = true;

   }


   window_size_list_box_impact::~window_size_list_box_impact()
   {

   }


#ifdef _DEBUG


   ::i64 window_size_list_box_impact::increment_reference_count()
   {

      return ::user::show < ::user::list_box >::increment_reference_count();

   }


   ::i64 window_size_list_box_impact::decrement_reference_count()
   {

      return ::user::show < ::user::list_box >::decrement_reference_count();

   }


#endif



   void window_size_list_box_impact::install_message_routing(::channel * psender)
   {

      ::user::show < ::user::list_box >::install_message_routing(psender);

      USER_MESSAGE_LINK(::user::e_message_create,psender,this,&window_size_list_box_impact::on_message_create);
      USER_MESSAGE_LINK(::user::e_message_destroy, psender, this, &window_size_list_box_impact::on_message_destroy);

   }


   void window_size_list_box_impact::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);

      //display();

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      m_statuscolorBackground = ::color::transparent;

      m_statuscolorBackground.m_estatus = ::success;

      update_window_size_list();


      //application()->show_about_box();
    

   }


   void window_size_list_box_impact::update_window_size_list()
   {

      _synchronous_lock synchronouslock(this->synchronization());

      m_sizea.clear();

      m_sizea.add({1280, 720});
      m_sizea.add({ 1920, 1080 });

      reset_content();

      int iIndex = 0;

      for (auto & size : m_sizea)
      {

         ::string strSize;

         strSize.formatf("%dx%d", size.cx, size.cy);

         add_item(strSize, iIndex);

         iIndex++;


      }

      
   }


   void window_size_list_box_impact::on_message_destroy(::message::message * pmessage)
   {

   }


   void window_size_list_box_impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      ::user::show < ::user::list_box >::handle(ptopic, phandlercontext);

   }


   document * window_size_list_box_impact::get_document()
   {

      return dynamic_cast < document * >(::user::show < ::user::list_box >::get_document());

   }


   void window_size_list_box_impact::_001OnClip(::draw2d::graphics_pointer & pdraw2dgraphics)
   {


   }


   void window_size_list_box_impact::_001OnDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      ::user::list_box::_001OnDraw(pdraw2dgraphics);

//      auto rectangleX = this->rectangle();
//
//      if (rectangleX.is_empty())
//      {
//
//         return;
//
//      }
//
////      if (pdraw2dgraphics->payload("set_transparent") == "set_transparent")
////      {
////
////         information() << "set_transparent called";
////
////      }
////      else
////      {
////
////         information() << "set_transparent NOT called!!";
////
////      }
//
//      ::f64_rectangle rectangleClipBox;
//
//      //pdraw2dgraphics->reset_clip();
//
//      //pdraw2dgraphics->get_clip_box(rectangleClipBox);
//
//      auto matrix = pdraw2dgraphics->m_matrix;
//
//      //auto origin = pdraw2dgraphics->origin();
//
//      auto opacity = ::opacity(48);
//
//      pdraw2dgraphics->set_alpha_mode(::draw2d::e_alpha_mode_blend);
//
//      pdraw2dgraphics->fill_rectangle(rectangleX, argb(108, 128, 128, 128));
//
//      ::color::color color_dk(dk_red());
//
//#ifdef DEBUG_WORK
//
//      ::i32_rectangle rectangleDryProWithLove_Work(5, 5, 1915, 1075);
//
//      pdraw2dgraphics->fill_rectangle(rectangleDryProWithLove_Work, argb(255, 150, 200, 255));
//
//#endif
//
//      pdraw2dgraphics->set_solid_color(color_dk);
//
//      auto psystem = system();
//
//      auto pnode = psystem->draw2d();
//
//      auto pwritetext = pnode->write_text();
//
//      auto fontsize = ::write_text::font_size(48.0 * rectangleX.height() / 1'080, e_unit_pixel);
//
//      m_pfontThomasBS_ = pwritetext->font("Fira Code", fontsize);
//
//      pdraw2dgraphics->set(m_pfontThomasBS_);
//
//      pdraw2dgraphics->set_text_rendering_hint(write_text::e_rendering_anti_alias);
//
//      pdraw2dgraphics->set_alpha_mode(draw2d::e_alpha_mode_blend);
//
//      _synchronous_lock synchronouslockDocument(get_document()->synchronization(), DEFAULT_SYNCHRONOUS_LOCK_SUFFIX);
//      
//      string_array_base & stra = get_document()->m_straLine;
//      
//      bool bWhite  = true;
//      
//      ::f64 x = 0.;
//      
//      ::f64 y = 0.;
//      
//      ::i32_point point;
//
//      string strText;
//
//      m_iSequence++;
//      
//      strText.formatf("psimpleapplication->m_pimpact->_001OnDraw(pdraw2dgraphics); %d", m_iSequence);
//
//      auto size = pdraw2dgraphics->get_text_extent(strText);
//
//      bool bFixedPosition = true;
//
//      if (bFixedPosition)
//      {
//
//         point = { 10, 10 };
//
//      }
//      else
//      {
//       
//         point.x = mathematics()->random(0, (int)(rectangleX.width() - size.cx));
//         point.y = mathematics()->random(0, (int)(rectangleX.height() - size.cy * 2));
//
//      }
//
//      ::color::color color;
//
//      opacity = ::opacity(96);
//
//      for(auto & strItem : stra)
//      {
//         
//         if(strItem.is_empty())
//         {
//            
//            x = 0;
//            
//            y += size.cy;
//            
//            bWhite = true;
//         
//            continue;
//         
//         }
//
//         if(bWhite)
//         {
//            
//            color = color::white;
//            
//         }
//         else
//         {
//            
//            color = color_dk;
//            
//         }
//
//         color &= opacity;
//
//         pdraw2dgraphics->set_solid_color(color);
//
//         pdraw2dgraphics->text_out(point.x + x, point.y + y, strItem);
//         
//         auto s = pdraw2dgraphics->get_text_extent(strItem);
//
//         x += s.cx;
//         
//         bWhite = !bWhite;
//         
//      }
//
//      color = color_dk;
//      
//      color &= opacity;
//
//      pdraw2dgraphics->set_solid_color(color);
//
//      pdraw2dgraphics->text_out(point.x, point.y + y + size.cy, strText);
//
//      pdraw2dgraphics->set_smooth_mode(::draw2d::e_smooth_mode_none);
//
   }


   void window_size_list_box_impact::on_layout(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      auto rectangleX = this->rectangle();

      if(rectangleX.is_empty())
      {

         return;

      }

      ::user::show < ::user::list_box >::on_layout(pdraw2dgraphics);
      
      setup_default_client_area_user_item();

   }



   ::i32_size window_size_list_box_impact::current_window_size()
   {

      _synchronous_lock synchronouslock(this->synchronization());

      auto atomCurrent = get_current_item_id();

      auto iIndex = atomCurrent.as_i64();

      if (iIndex < 0 || iIndex >= m_sizea.size())
      {

         return {};

      }

      return m_sizea[iIndex];

   }


   bool window_size_list_box_impact::on_click(::item * pitem, ::user::mouse * pmouse)
   {

      if (::is_item_set(pitem))
      {

         auto pmainwindow = m_pwindowlistboximpact->current_main_window();

         if (pmainwindow)
         {

            auto size = current_window_size();

            if (size.is_set())
            {

               pmainwindow->set_size(size);

            }

         }

         //if (pitem->m_item.m_eelement == ::e_element_client)
         //{

         //   print_line("on_click : e_element_client");
         //   
         //   ::file::file_dialog_filter filter;
         //   
         //   filter.add({"application.txt", "application.txt"});
         //   
         //   pick_single_file_to_open(filter, [ this ] (::file::file_dialog * pdialog)
         //                    {
         //      
         //      try 
         //      {

         //         if (pdialog->m_patha.has_element())
         //         {

         //            auto memory = file()->as_memory(pdialog->m_patha.first());

         //            auto size = memory.size();

         //            informationf("got file with %d bytes", size);

         //            file()->put_memory(m_papp->m_pathApplicationText, memory);

         //         }

         //      } 
         //      catch (...) 
         //      {

         //         auto pmessagebox = message_box("No file loaded...");

         //         pmessagebox->display(e_display_normal, {});

         //      }
         //      
         //   });

         //   return true;

         //}

      }

      return ::user::show < ::user::list_box >::on_click(pitem, pmouse);

   }


} // namespace app_simple_window_size



