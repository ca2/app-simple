#include "framework.h"
#include "impact.h"
#include "application.h"
#include "render.h"
#include "document.h"
#include "build_plan_layout.h"
#include "acme/constant/id.h"
#include "acme/constant/user_message.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "acme/handler/handler.h"
#include "acme/prototype/datetime/datetime.h"
#include "apex/handler/signal.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/graphics/draw2d/graphics_pointer.h"
#include "aura/graphics/image/context.h"
#include "aura/graphics/image/drawing.h"
#include "aura/graphics/write_text/font.h"
#include "aura/graphics/write_text/font_family.h"
#include "aura/message/user.h"
#include "aura/user/user/plain_edit.h"
#include "berg/user/user/impact_system.h"
#include "berg/user/user/split_impact.h"


namespace app_simple_build_plan
{


   impact::impact()
   {

      m_enonclient.erase(::user::e_non_client_background);

      m_enonclient.erase(::user::e_non_client_focus_rect);

   }


   impact::~impact()
   {

   }


#ifdef _DEBUG


   ::i64 impact::increment_reference_count()
   {

      return  ::user::impact::increment_reference_count();

   }


   ::i64 impact::decrement_reference_count()
   {

      return  ::user::impact::decrement_reference_count();

   }


#endif


   void impact::install_message_routing(::channel * psender)
   {

      ::user::impact::install_message_routing(psender);

      USER_MESSAGE_LINK(::user::e_message_create,psender,this,&impact::on_message_create);
      USER_MESSAGE_LINK(::user::e_message_destroy, psender, this, &impact::on_message_destroy);

   }


   void impact::on_message_create(::message::message * pmessage)
   {

      payload("font_selection_impact") = true;

      ::pointer<::message::create> pcreate(pmessage);

      pcreate->previous();

      if (pcreate->m_bRet)
      {

         return;

      }

      m_papp->m_propertylistenera.add(this);

//
//      m_papp->fork([this]()
//      {
//            ::string strId = 
//
//
//});

      //{

      //   auto psignal = get_app()->get_signal("simple_checkbox");

      //   psignal->add_handler(this);

      //}

      //{

      //   auto psignal = get_app()->get_signal("no_client_frame");

      //   psignal->add_handler(this);

      //}

      //auto estatus = 
      
      //construct_newø(m_prender);

      //if(!estatus)
      //{

      //   pcreate->set_fail();

      //   return;

      //}
            //m_prender->m_pimpact = this;

      auto pdocument = get_document();

      auto pimpactsystem = pdocument->m_pimpactsystem;

      string strId = pimpactsystem->id();

      string strText;

      if(get_typed_parent<::user::split_impact>() != nullptr)
      {

         if(get_typed_parent<::user::split_impact>()->get_child_by_id("top_edit_impact") != nullptr)
         {

            auto pinteraction = get_typed_parent<::user::split_impact>()->get_child_by_id("top_edit_impact");

            pinteraction->set_text(strText,::e_source_initialize);

         }

      }

   }

   //::string impact::string_column::get_row_payload(int iLine)
   //{

   //   return m_str2a[iLine]->element_at(m_iaCurrent[iLine]);

   //}

   //void impact::string_column::add_row(::collection::index iLine,
   //                                    berg::form_handler *pformhandler, ::user::line_layout *plinelayout,
   //                                    const ::scoped_string &scopedstr, const ::procedure & procedureUpdate, bool bStatus, 
   //   bool bSimplified)
   //{

   //   ::pointer<::user::still> peditStart;

   //   if (bSimplified)
   //   {

   //      if (!bStatus)
   //      {

   //         throw ::exception(error_bad_argument);

   //      }

   //      peditStart = pformhandler->create_clickable_label(plinelayout, "");

   //   }
   //   else
   //   {

   //      peditStart = pformhandler->create_label(plinelayout);

   //   }

   //   auto pstraStart = m_str2a.main_add();

   //   if (bStatus)
   //   {
   //      auto pfont = createø<::write_text::font>();
   //      pfont->create_font(e_font_sans_ui, 16_px, e_font_weight_bold);
   //      peditStart->m_pfont = pfont;
   //      pstraStart->add("todo");
   //      pstraStart->add("running");
   //      pstraStart->add("skipped");
   //      pstraStart->add("blocked");
   //      pstraStart->add("ok");
   //      auto iFind = pstraStart->case_insensitive_find_first(scopedstr);
   //      if (iFind < 0)
   //         iFind = 0;
   //      peditStart->m_statuscolorBackground.m_estatus = ::success;
   //      peditStart->m_statuscolorBackground = m_coloraBackground[iFind];
   //      peditStart->m_statuscolorText.m_estatus = ::success;
   //      peditStart->m_statuscolorText = m_coloraText[iFind];
   //      peditStart->set_window_text(pstraStart->element_at(iFind));
   //      m_iaCurrent.add(iFind);
   //      peditStart->m_sizeFixed = {80, 28};

   //   }
   //   else
   //   {

   //      pstraStart->add(scopedstr);
   //      peditStart->set_window_text(scopedstr);
   //      m_iaCurrent.add(0);
   //      peditStart->m_sizeFixed = {160, 28};

   //               peditStart->m_statuscolorText = ::argb(255, 255, 255, 255);

   //      //peditStart->m_statuscolorBackground = ::argb(160, 40, 40, 40);

   //   }

   //         auto &iIndex = m_iaCurrent[iLine];


   //   peditStart->m_ealignText = ::e_align_left_center;

   //   ::pointer<::user::still> pbuttonUpdateStart;

   //   ::pointer<::user::still> pbuttonBackStart;

   //   ::pointer<::user::still> pbuttonForwardStart;

   //   if (!bSimplified)
   //   {

   //      pbuttonBackStart = pformhandler->create_clickable_label(plinelayout, "⏴");

   //   }

   //   if (!bStatus)
   //   {

   //      pbuttonUpdateStart = pformhandler->create_clickable_label(plinelayout, "✔");
   //   }

   //   if (!bSimplified)
   //   {
   //      pbuttonForwardStart = pformhandler->create_clickable_label(plinelayout, "⏵");
   //   }

   //   
   //   if (pbuttonBackStart)
   //   {



   //      pbuttonBackStart->m_callbackOnClick =
   //         [this, peditStart, iLine, pbuttonBackStart, pbuttonForwardStart, procedureUpdate](auto, auto, auto)
   //      {
   //         auto &iIndex = m_iaCurrent[iLine];
   //         if (iIndex > 0)
   //         {
   //            iIndex--;
   //            pbuttonForwardStart->enable_window(true);
   //            peditStart->set_window_text(m_str2a[iLine]->element_at(iIndex));
   //            if (iIndex <= 0)
   //            {

   //               pbuttonBackStart->enable_window(false);
   //            }
   //            if (procedureUpdate)
   //            {
   //               procedureUpdate();
   //            }
   //         }

   //         return true;
   //      };

   //      // pbuttonBackStart->m_sizeFixed = {28, 28};

   //      pbuttonBackStart->enable_window(iIndex > 0);

   //      pbuttonBackStart->m_bDefaultClickHandling = true;
   //   }

   //   if (pbuttonUpdateStart)
   //   {

   //      pbuttonUpdateStart->m_callbackOnClick =
   //         [this, peditStart, pbuttonBackStart, pbuttonForwardStart, iLine, procedureUpdate](auto, auto, auto)
   //      {
   //         ::earth::time time;

   //         time.Now();

   //         auto &iIndex = m_iaCurrent[iLine];

   //         iIndex = m_str2a[iLine]->size();

   //         auto &strDate = m_str2a[iLine]->atø(iIndex);

   //         pbuttonBackStart->enable_window(true);

   //         pbuttonForwardStart->enable_window(false);

   //         strDate = datetime()->date_time_text(time, ::time::local_offset());

   //         peditStart->set_window_text(strDate);
   //         if (procedureUpdate)
   //         {

   //            procedureUpdate();
   //         }

   //         return true;
   //      };

   //      // pbuttonUpdateStart->m_sizeFixed = {28, 28};

   //      pbuttonUpdateStart->m_bDefaultClickHandling = true;
   //   }


   //   if (pbuttonForwardStart)
   //   {

   //               pbuttonForwardStart->m_callbackOnClick =
   //         [this, peditStart, iLine, pbuttonBackStart, pbuttonForwardStart, procedureUpdate](auto, auto, auto)
   //      {
   //         auto &iIndex = m_iaCurrent[iLine];
   //         if (iIndex < m_str2a[iLine]->get_upper_bound())
   //         {
   //            iIndex++;
   //            pbuttonBackStart->enable_window(true);
   //            peditStart->set_window_text(m_str2a[iLine]->element_at(iIndex));
   //            if (iIndex >= m_str2a[iLine]->get_upper_bound())
   //            {

   //               pbuttonForwardStart->enable_window(false);
   //            }
   //            if (procedureUpdate)
   //            {
   //               procedureUpdate();
   //            }
   //         }

   //         return true;
   //      };

   //      pbuttonForwardStart->m_bDefaultClickHandling = true;
   //      // pbuttonForwardStart->m_sizeFixed = {28, 28};

   //      pbuttonForwardStart->enable_window(iIndex < m_str2a[iLine]->get_upper_bound());
   //   }

   //   

   //   if (bSimplified)
   //   {

   //      if (peditStart)
   //      {

   //         peditStart->m_callbackOnClick = [this, peditStart, iLine, procedureUpdate](auto, auto, auto)
   //         {
   //            auto &iIndex = m_iaCurrent[iLine];
   //            if (iIndex >= m_str2a[iLine]->get_upper_bound())
   //            {
   //               iIndex = 0;
   //            }
   //            else
   //            {
   //               iIndex++;
   //            }
   //            peditStart->m_statuscolorBackground.m_estatus = ::success;
   //            peditStart->m_statuscolorBackground  = m_coloraBackground[iIndex];
   //            peditStart->m_statuscolorText.m_estatus = ::success;
   //            peditStart->m_statuscolorText = m_coloraText[iIndex];
   //            peditStart->set_window_text(m_str2a[iLine]->element_at(iIndex));

   //            if (procedureUpdate)
   //            {
   //               procedureUpdate();
   //            }

   //            return true;
   //         };
   //      }

   //   }

   //}


   //void impact::update_build_plan_from_storage()
   //{



   //}

   void impact::initialize_simple_build_plan(const ::scoped_string &scopedstr)
   {


      m_strId = scopedstr;


      m_plinelayout = create_line_layout(this, e_orientation_vertical);

      auto playoutMiniToolbar = create_line_layout(m_plinelayout, e_orientation_horizontal);

      auto pbuttonUpdate = create_button(playoutMiniToolbar, "Update");

      pbuttonUpdate->set_size({200, 32});

      //auto pbuttonSend = create_button(playoutMiniToolbar, "Send");

      //pbuttonSend->set_size({200, 32});

      ::string strId(scopedstr);


      pbuttonUpdate->m_callbackOnClick = [this](auto, auto, auto)
      {
         replace_build_plan();
         return true;
      };

      //if (m_pthreadAutoWrite)
      //{

      //   m_pthreadAutoWrite->set_finish();

      //}
      //
      //      m_pthreadAutoWrite = m_papp->fork(
      //   [this, strId]()
      //      {

      //         while (::task_get_run())
      //         {

      //            preempt(1_s);

      //            m_pbu
      //            if (m_bModified)
      //            {

      //               

      //            }

      //            }

      //
      //});


      //pbuttonSend->m_callbackOnClick = [this](auto, auto, auto)
      //{
      //   m_pbuildplanlayout->write_build_plan();


      //   return true;
      //};


      replace_build_plan();

      

   }



   void impact::replace_build_plan() {
   
   
   
            try
      {

         if (m_pbuildplanlayout)
         {

            m_pbuildplanlayout->destroy_window();
         }
      }
      catch (...)
      {
      }

      m_pbuildplanlayout = create_newø<build_plan_layout>();

      m_pbuildplanlayout->m_strId = m_strId;

      m_pbuildplanlayout->line_layout::create_line_layout(m_plinelayout, e_orientation_vertical);

      m_pbuildplanlayout->m_bLockGraphicalUpdate = true;

      m_pbuildplanlayout->update_build_plan_from_build_plan_spreadsheet_export();

      m_pbuildplanlayout->m_bLockGraphicalUpdate = false;

      m_pbuildplanlayout->start_auto_write_task();

   }

   //   ::file::path path = "G:/application/app-simple/build_plan/" + strId + "_build_plan.comma_separated";

   //   
   //   ::pointer_array<string_array> str2aCommaSeparated;
   //   
   //   try
   //   {

   //      str2aCommaSeparated = file()->as_comma_separated(path);
   //   }
   //   catch (...)
   //   {


   //   }

   //   

   //   ::string_array straLines;

   //   straLines.add("2026-06-14 16:35:00");

   //   construct_newø(m_pcolumnDateStart);

   //   construct_newø(m_pcolumnDateEnd);

   //   construct_newø(m_pcolumnStatus);
   //   auto pfontHost = createø<::write_text::font>();
   //   pfontHost->create_font(e_font_sans_ui, 16_px, e_font_weight_normal, false, true);


   //   m_pcolumnStatus->m_coloraBackground.add(argb(60, 255, 255, 255));
   //   m_pcolumnStatus->m_coloraBackground.add(hex_color(180, 0xe69138));
   //   m_pcolumnStatus->m_coloraBackground.add(argb(60, 255, 255, 255));
   //   m_pcolumnStatus->m_coloraBackground.add(argb(60, 255, 255, 255));
   //   m_pcolumnStatus->m_coloraBackground.add(hex_color(180, 0x6aa84f));
   //   m_pcolumnStatus->m_coloraText.add(hex_color(180, 0x4a86e8));
   //   m_pcolumnStatus->m_coloraText.add(::color::white);
   //   m_pcolumnStatus->m_coloraText.add(hex_color(180, 0xa2c4c9));
   //   m_pcolumnStatus->m_coloraText.add(hex_color(180, 0xe06666));
   //   m_pcolumnStatus->m_coloraText.add(::color::white);


   //   int iLine = 0;

   //   for (auto pstraLine: str2aCommaSeparated)
   //   {

   //      auto &straLine = *pstraLine;

   //      ::string strOperatingSystem = straLine[2];

   //      strOperatingSystem.trim();

   //      if (strOperatingSystem.is_empty())
   //      {

   //         break;

   //      }

   //      ::string strArch = straLine[3];

   //      auto playoutLine = create_line_layout(playoutMain, e_orientation_horizontal);

   //      ::string strStart= straLine[5];
   //      ::string strEnd = straLine[6];
   //      ::string strStatus = straLine[7];
   //      ::string strHost = straLine[8];
   //      ::string strComment = straLine[11];

   //      ::pointer < ::user::still > pstillOsIcon;
   //      ::pointer<::user::still> pstillOperatingAmbientIcon;

   //      ::string strOsIconUrl;
   //      ::string strOperatingAmbientIconUrl;

   //      ::f32 fScale = 1.0;
   //      ::f32 fScaleOperatingAmbient = 1.0;
   //      if (strOperatingSystem.case_insensitive_begins("kubuntu") || strOperatingSystem.case_insensitive_contains("kde"))
   //      {

   //         strOperatingAmbientIconUrl = "https://ca2.site/image/operating-ambient/64/kde.png";

   //      }
   //      else if (strOperatingSystem.case_insensitive_begins("xubuntu") ||
   //               strOperatingSystem.case_insensitive_contains("xfce"))
   //      {

   //         strOperatingAmbientIconUrl = "https://ca2.site/image/operating-ambient/64/xfce.png";

   //      }
   //      else if (strOperatingSystem.case_insensitive_begins("lubuntu") ||
   //               strOperatingSystem.case_insensitive_contains("lxqt"))
   //      {

   //         strOperatingAmbientIconUrl = "https://ca2.site/image/operating-ambient/64/lxqt.png";
   //         fScaleOperatingAmbient = 0.8;
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("gnome") ||
   //               strOperatingSystem.case_insensitive_contains("ubuntu") ||
   //                  strOperatingSystem.case_insensitive_contains("fedora workstation")
   //          )
   //      {

   //         strOperatingAmbientIconUrl = "https://ca2.site/image/operating-ambient/64/gnome.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("opensuse"))
   //      {

   //         strOperatingAmbientIconUrl = "https://ca2.site/image/operating-ambient/64/kde.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("debian"))
   //      {

   //         strOperatingAmbientIconUrl = "https://ca2.site/image/operating-ambient/64/gnome.png";
   //      }
   //      if (strOperatingSystem.case_insensitive_contains("windows"))
   //      {

   //         if (strOperatingSystem.contains(" 11"))
   //         {

   //            strOsIconUrl = "https://ca2.site/image/operating-system/48/windows11.png";
   //            fScale = 0.8;
   //         }
   //         else
   //         {
   //            strOsIconUrl = "https://ca2.site/image/operating-system/48/windows10.png";

   //         }
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("ubuntu"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/ubuntu.png";

   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("fedora"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/fedora.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("opensuse"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/opensuse.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("manjaro"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/manjaro.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("debian"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/debian.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("freebsd"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/freebsd.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("netbsd"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/netbsd.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("openbsd"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/openbsd.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("macos"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/macos.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("ios"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/ios.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("android"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/android.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("raspberry pi os"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/raspberry_pi_os.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("ghostbsd"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/ghostbsd.png";
   //      }
   //      else if (strOperatingSystem.case_insensitive_contains("dragonfly bsd"))
   //      {

   //         strOsIconUrl = "https://ca2.site/image/operating-system/48/dragonflybsd.png";
   //      }


   //      if (strOperatingAmbientIconUrl.has_character())
   //      {
   //         pstillOperatingAmbientIcon = create_icon_label(playoutLine);

   //         pstillOperatingAmbientIcon->set_still_type(::user::e_still_image);
   //         auto pimage = image()->load_image(strOperatingAmbientIconUrl);

   //         if (fScaleOperatingAmbient < 0.99f)
   //         {

   //            auto pimage1 = pimage;

   //            pimage = image()->create_image({48, 48});

   //            ::f64 w = 48.0;
   //            ::f64 h = 48.0;

   //            ::f64 wScaled = (w * fScaleOperatingAmbient);
   //            ::f64 hScaled = (h * fScaleOperatingAmbient);

   //            ::f64 xOffset = (w - wScaled) / 2.0;
   //            ::f64 yOffset = (h - hScaled) / 2.0;

   //            auto pimage2 = pimage1->get_resized_image({(::i32)wScaled, (::i32)hScaled});

   //            ::image::image_source imagesource(pimage2);

   //            ::image::image_drawing_options imagedrawingoptions(
   //               ::f64_rectangle_dimension(xOffset, yOffset, wScaled, hScaled));

   //            ::image::image_drawing imagedrawing(imagedrawingoptions, imagesource);

   //            pgraphicsImage->draw(imagedrawing);
   //         }


   //         pstillOperatingAmbientIcon->m_pimage = pimage;


   //         //pstillOperatingAmbientIcon->m_statuscolorBackground = ::argb(128, 25, 25, 25);

   //         pstillOperatingAmbientIcon->m_statuscolorBackground = ::color::transparent;



   //      }
   //      else
   //      {

   //         pstillOperatingAmbientIcon = create_label(playoutLine);
   //         pstillOperatingAmbientIcon->set_window_text(" ");

   //      }

   //               pstillOperatingAmbientIcon->m_sizeFixed = {24, 24};


   //      if (strOsIconUrl.has_character())
   //      {

   //         pstillOsIcon = create_icon_label(playoutLine);

   //         pstillOsIcon->set_still_type(::user::e_still_image);
   //         auto pimage = image()->load_image(strOsIconUrl);

   //         if (fScale < 0.99f)
   //         {

   //            auto pimage1 = pimage;

   //            pimage = image()->create_image({48, 48});

   //            ::f64 w = 48.0;
   //            ::f64 h = 48.0;

   //            ::f64 wScaled = (w * fScale);
   //            ::f64 hScaled = (h * fScale);

   //            ::f64 xOffset = (w - wScaled) / 2.0;
   //            ::f64 yOffset = (h - hScaled) / 2.0;

   //            auto pimage2 = pimage1->get_resized_image({ (::i32)wScaled, (::i32)hScaled});

   //            ::image::image_source imagesource(pimage2);

   //            ::image::image_drawing_options imagedrawingoptions(::f64_rectangle_dimension(
   //               xOffset,
   //               yOffset,
   //               wScaled,
   //               hScaled));

   //            ::image::image_drawing imagedrawing(imagedrawingoptions, imagesource);

   //            pgraphicsImage->draw(imagedrawing);


   //         }

   //         
   //         pstillOsIcon->m_pimage = pimage;


   //         pstillOsIcon->m_statuscolorBackground = ::color::transparent;


   //      }
   //      else
   //      {

   //         pstillOsIcon = create_label(playoutLine);
   //         pstillOsIcon->set_window_text(" ");

   //      }

   //      pstillOsIcon->m_sizeFixed = {24, 24};

   //      auto peditOs = create_label(playoutLine);

   //      peditOs->set_window_text(strOperatingSystem);

   //      peditOs->m_sizeFixed = {300, 28};

   //      peditOs->m_ealignText = ::e_align_left_center;

   //      peditOs->m_statuscolorText = ::argb(255, 255, 255, 255);

   //      //peditOs->m_statuscolorBackground = ::argb(160, 40, 40, 40);


   //      auto plabelArch = create_label(playoutLine);

   //      plabelArch->set_window_text(strArch);

   //      plabelArch->m_sizeFixed = {50, 28};

   //      plabelArch->m_ealignText = ::e_align_left_center;
   //      
   //      plabelArch->m_statuscolorText = ::argb(255, 255, 255, 255);

   //      //plabelArch->m_statuscolorBackground = ::argb(160, 40, 40, 40);

   //      
   //      auto pstillSpan = _allocate_label();

   //      ::procedure procedureUpdateSpan = [this, iLine, pstillSpan]()
   //      {
   //         ::string strStart = m_pcolumnDateStart->m_str2a[iLine]->element_at(m_pcolumnDateStart->m_iaCurrent[iLine]);

   //         ::string strEnd = m_pcolumnDateEnd->m_str2a[iLine]->element_at(m_pcolumnDateEnd->m_iaCurrent[iLine]);

   //         if (strStart.is_empty() || strEnd.is_empty())
   //         {

   //            pstillSpan->set_window_text("");
   //         }
   //         else
   //         {

   //            ::earth::time timeStart(datetime()->parse(strStart));
   //            ::earth::time timeEnd(datetime()->parse(strEnd));
   //            auto span = timeEnd - timeStart;
   //            pstillSpan->set_window_text(datetime()->friendly_elapsed(span.m_iSecond));
   //         }
   //      };

   //      m_pcolumnDateStart->add_row(iLine, this, playoutLine, strStart, procedureUpdateSpan, false, false);

   //      m_pcolumnDateEnd->add_row(iLine, this, playoutLine, strEnd, procedureUpdateSpan, false, false);

   //      m_pcolumnStatus->add_row(iLine, this, playoutLine, strStatus, {}, true, true);

   //      auto plabelHost = create_label(playoutLine);

   //      plabelHost->set_window_text(strHost);

   //      plabelHost->m_sizeFixed = {240, 28};

   //      plabelHost->m_statuscolorText = ::argb(255, 50, 160, 255);

   //      //plabelHost->m_statuscolorBackground = ::argb(160, 40, 40, 40);

   //      plabelHost->m_ealignText = ::e_align_left_center;

   //      plabelHost->m_pfont = pfontHost;


   //      _initialize_label(pstillSpan, playoutLine, false);
   //      pstillSpan->m_sizeFixed = {200, 28};

   //      pstillSpan->m_ealignText = ::e_align_left_center;
   //      


   //      auto peditComment = create_edit<::user::plain_edit>(playoutLine);

   //      peditComment->set_size({300, 29});

   //      peditComment->m_statuscolorBackground = ::argb(100, 50, 50, 50);
   //      peditComment->m_statuscolorText = ::argb(100, 255, 255, 255);
   //      m_editaComment.add(peditComment);
   //      peditComment->set_text(strComment, e_source_sync);

   //      procedureUpdateSpan();

   //      //auto pstraStart = m_str2a.main_add();

   //      //pstraStart->add(scopedstr);

   //      //peditStart->set_window_text(scopedstr);

   //      //peditStart->m_sizeFixed = {160, 28};

   //      //peditStart->m_ealignText = ::e_align_left_center;


   //      iLine++;
   //      
   //   }


   //}


   void impact::on_property_changed(::data::property_change & change)
   {

      if (m_papp->m_checkSimple && change)
      {

         set_need_redraw();

         post_redraw();

      }
      else if (m_papp->m_checkNoClientFrame && change)
      {

         set_need_redraw();

         post_redraw();

      }

   }


   void impact::on_message_destroy(::message::message * pmessage)
   {
      /*if (m_prender)
      {

         m_prender->destroy();

      }
      m_prender.release();*/
   }


   void impact::handle(::topic * ptopic, ::handler_context * phandlercontext)
   {

      if (ptopic->id() == "simple_checkbox"
         || ptopic->id() == "no_client_frame")
      {

         set_need_redraw();
         
         post_redraw();

      }

      ::user::impact::handle(ptopic, phandlercontext);
   }


   ::user::document * impact::get_document()
   {

      return ::user::impact::get_document();

   }


   void impact::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      auto r = client2_rectangle();

      if (r.is_empty())
      {

         return;

      }

      pgraphics->fill_solid_rectangle(r, argb(220,80, 80, 80));

   //   if (get_app()->m_checkNoClientFrame.echeck() != ::e_check_checked)
   //   {

   //      ::i32_rectangle rectangle = this->rectangle();

   //      for (::collection::index i = 0; i < 11; i++)
   //      {

   //         pgraphics->draw_inset_rectangle(rectangle, argb(180, 80, 80, 80), 1.0);

   //         rectangle.deflate(1, 1);

   //      }

   //   }

   //   m_prender->_001OnDraw(pgraphics);

   }


   ////void impact::on_layout(::draw2d::graphics_pointer & pgraphics)
   ////{

   ////   auto rectangleX = this->rectangle();

   ////   if(rectangleX.is_empty())
   ////   {

   ////      return;

   ////   }

   ////   m_prender->m_rectangle = rectangleX;

   ////}


} // namespace simple_build_plan



