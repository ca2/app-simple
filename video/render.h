#pragma once


namespace simple_video
{


   class CLASS_DECL_APP_SIMPLE_VIDEO render :
      virtual public __application_consumer
   {
   public:


      string                              m_strDevice;
      string   &                          m_strHoverFontFamilyName;
      rect                                m_rect;
      ::user::impact *                    m_pview;
      string                              m_strFont1;
      string_map < ::image_pointer >      m_pimagemap;
      ::image_pointer                     m_imagea[2];
      ::mutex                             m_mutexa[2];
      int                                 m_iShow;

      ::hls                               m_hlsText;

      render();
      virtual ~render();

#ifdef DEBUG
      virtual int64_t add_ref(OBJ_REF_DBG_PARAMS) override;
      virtual int64_t dec_ref(OBJ_REF_DBG_PARAMS) override;
#endif

      string get_font();
      ::e_status set_font(const string& strFont);

      virtual void initialize_simple_video(const string & strDevice);

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics);

      //virtual void _001OnDraw1Through3(::draw2d::graphics_pointer & pgraphics);

      //virtual void _001OnDrawArcs(::draw2d::graphics_pointer & pgraphics, bool bPath);

      //virtual void draw_arc(::draw2d::graphics_pointer & pgraphics, rect & r, angle angleStart, angle angleAngle, bool bPath);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics);
      int get_device();

      void capture_loop();

      void capture_step(int iVideo);
      

   };


} // namespace simple_video


