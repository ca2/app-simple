#pragma once


namespace simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_DRAWING render :
      virtual public __application_consumer
   {
   public:


      string   & m_strHoverFontFamilyName;

      rect                                m_rect;
      ::user::impact *                    m_pview;
      string                              m_strFont1;
      int                                 m_iDrawing;
      string_map < ::image_pointer >      m_pimagemap;
      ::image_pointer                     m_pimage1;
      ::image_pointer                     m_pimage2;
      ::hls                               m_hlsText;

      render();
      virtual ~render();

#ifdef DEBUG
      virtual int64_t add_ref(OBJ_REF_DBG_PARAMS) override;
      virtual int64_t dec_ref(OBJ_REF_DBG_PARAMS) override;
#endif

      string get_font();
      ::estatus set_font(const string& strFont);

      virtual void initialize_simple_drawing(int iDrawing);

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics);

      virtual void _001OnDraw1Through3(::draw2d::graphics_pointer & pgraphics);

      virtual void _001OnDrawArcs(::draw2d::graphics_pointer & pgraphics, bool bPath);

      virtual void draw_arc(::draw2d::graphics_pointer & pgraphics, rect & r, angle angleStart, angle angleAngle, bool bPath);

      virtual void on_layout(::draw2d::graphics_pointer & pgraphics);




      

   };


} // namespace simple_drawing


