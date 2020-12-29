#include "framework.h"
#include "aura/id.h"
#include <math.h>
#include "video_input/video_input.h"

void video_input_stop_event(int deviceID, void * userData);
CLASS_DECL_AURA color32_t dk_red(); // <3 tbs


namespace simple_video
{



   render::render() :
      m_strHoverFontFamilyName(topic(id_hover_font_family_name))
   {

      defer_create_mutex();

      


   }


   render::~render()
   {

   }


#ifdef _DEBUG


   int64_t render::add_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::add_ref(OBJ_REF_DBG_ARGS);

   }


   int64_t render::dec_ref(OBJ_REF_DBG_PARAMS_DEF)
   {

      return ::object::dec_ref(OBJ_REF_DBG_ARGS);

   }


#endif


   void render::on_layout(::draw2d::graphics_pointer & pgraphics)
   {


   }

   int render::get_device()
   {

      auto & videoinput = ::video_input::video_input::get_instance();

      return videoinput.get_video_device_index(m_strDevice);

   }


   void render::capture_loop()
   {


      while (::thread_get_run())
      {

         auto & videoinput = ::video_input::video_input::get_instance();

         if (videoinput.is_frame_new(get_device()))
         {

            int iVideo;

            if (m_iShow == 0)
            {

               iVideo = 1;

            }
            else
            {

               iVideo = 0;

            }


            capture_step(m_iShow);

            sync_lock sl(mutex());

            if (m_iShow == 0)
            {

               m_iShow = 1;

            }
            else
            {

               m_iShow = 0;

            }

         }

         m_pview->post_redraw();

         sleep(100_ms);

      }


   }

   void render::capture_step(int iCapture)
   {

      auto & mutex = m_mutexa[iCapture];

      sync_lock sl(&mutex);

      auto & pimage = m_imagea[iCapture];

      auto & videoinput = ::video_input::video_input::get_instance();

      videoinput.get_pixels(get_device(), pimage->get_data());

   }


   void render::initialize_simple_video(const string & strDevice)
   {

      initialize_application_consumer();
      
      auto & videoinput = ::video_input::video_input::get_instance();

      auto iDevice = videoinput.get_video_device_index(strDevice);

      if(iDevice < 0)
      { 
      
         return;
      
      }

      m_strDevice = strDevice;

      ThisApp.data_set("device", strDevice);

      if (strDevice.is_empty())
      {

         __throw(invalid_argument_exception());

         return;

      }

      if (videoinput.setup_device(get_device(), 1920, 1080, 60))
      {

         videoinput.set_emergency_stop_event(get_device(), NULL, &video_input_stop_event);

         //if (videoinput.is_frame_new(m_iDevice))
         //{
         
            int countLeftFrames = 0;

            m_imagea[0].create(e_create);
            m_imagea[1].create(e_create);

            m_imagea[0]->create(videoinput.get_width(get_device()), videoinput.get_height(get_device()));
            m_imagea[1]->create(videoinput.get_width(get_device()), videoinput.get_height(get_device()));
            m_iShow = 0;

            fork([this]()
               {

                  capture_loop();

               });


                  //else
                  //   countLeftFrames++;

         //         char c = cvWaitKey(33);

         //         if (c == 27)
         //            break;

         //         if (c == 49)
         //         {
         //            camera_parameters CP = VI->get_parameters(i - 1);
         //            CP.Brightness.m_lCurrentValue = 128;
         //            CP.Brightness.m_lFlag = 1;
         //            VI->set_parameters(i - 1, CP);
         //         }

         //         if (!VI->is_device_setup(i - 1))
         //         {
         //            break;
         //         }

         //         if (countLeftFrames > 60)
         //            break;
         //      }

         //      VI->close_device(i - 1);

         //      cvDestroyWindow("VideoTest");
         //   }
         //}
      }

      //if (VI->setup_device(i - 1, 1920, 1080, 60))
      //{
      //   if (VI->is_frame_new(i - 1))
      //   {
      //      int countLeftFrames = 0;

      //      cvNamedWindow("VideoTest1", CV_WINDOW_AUTOSIZE);
      //      CvSize size = cvSize(VI->get_width(i - 1), VI->get_height(i - 1));

      //      IplImage * frame;

      //      frame = cvCreateImage(size, 8, 3);

      //      while (1)
      //      {
      //         if (VI->is_frame_new(i - 1))
      //         {
      //            VI->get_pixels(i - 1, (unsigned char *)frame->imageData, false);
      //            cvShowImage("VideoTest1", frame);
      //            countLeftFrames = 0;
      //         }
      //         else
      //            countLeftFrames++;

      //         char c = cvWaitKey(33);

      //         if (c == 27)
      //            break;

      //         if (!VI->is_device_setup(i - 1))
      //         {
      //            break;
      //         }

      //         if (countLeftFrames > 60)
      //            break;
      //      }

      //      VI->close_device(i - 1);

      //      cvDestroyWindow("VideoTest1");
      //   }

      //}


      //color32_t crText = ARGB(255, 55, 210, 120);

      //if (m_iDevice == 1)
      //{

      //   crText = ARGB(127, 0, 127, 200);

      //}
      //else if (m_iDevice == 3)
      //{

      //   crText = ARGB(255, 180, 180, 180);

      //}

      //color color(crText);

      //string strDataId;

      //strDataId = m_pview->m_id;

      ////m_hlsText.m_dH = 0.1;
      ////m_hlsText.m_dL = 0.5;
      ////m_hlsText.m_dS = 0.9;

      ////Application.data_set(strDataId, m_hlsText);

      //if(!Application.data_get(strDataId +".color", m_hlsText))
      //{

      //   m_hlsText = color.get_hls();

      //}

   }


   void render::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      sync_lock sl1(mutex());

      sync_lock sl2(&m_mutexa[m_iShow]);

      if (m_imagea[m_iShow])
      {

         pgraphics->draw_at(point(), m_imagea[m_iShow]);

      }

   }


   ::e_status render::set_font(const string & strFont)
   {

      if (strFont.is_empty())
      {

         return error_invalid_argument;

      }

      string strDataId;

      strDataId = m_pview->m_id;

      if (!Application.data_set(strDataId + ".font_family", m_strFont1))
      {

         return error_failed;

      }

      m_strFont1 = strFont;

      return ::success;

   }





   string render::get_font()
   {

      string strFont;

      strFont = m_strHoverFontFamilyName;

      if (strFont.has_char())
      {

         return strFont;

      }

      if (m_strFont1.is_empty())
      {

         string strDataId;

         strDataId = m_pview->m_id;

         if (!Application.data_get(strDataId + ".font_family", m_strFont1)
            || m_strFont1.is_empty())
         {

            m_strFont1 = FONT_SANS_EX;

         }

      }

      return m_strFont1;

   }



   //string application::get_main_title() const
   //{

   //   string strSimple(m_strSimple);

   //   if (strSimple.trimmed().has_char())
   //   {

   //      return m_strSimple;

   //   }
   //   else
   //   {

   //      return m_strMainTitle;

   //   }

   //}


} // namespace simple_video



