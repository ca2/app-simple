#pragma once



namespace app_simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_DRAWING application :
      virtual public ::base::application
   {
   public:


      __PROPERTIES(application)
         __PROPERTY(::enum_check, m_echeckSimple, "simple_checkbox");
         __PROPERTY(::enum_check, m_echeckNoClientFrame, "no_client_frame");
         __PROPERTY(string, m_strSimple, "simple_text");
         __PROPERTY(string, m_strMainTitle, "main_title");
      __END_PROPERTIES(application);


      bool                                   m_bMultiverseChat;

      ::user::document *                     m_pdocMenu;
      ::user::plain_edit_view *              m_prollfps;
      ::user::single_document_template *     m_ptemplateSimpleDrawingMain;
      tab_impact *                             m_ptabimpact;

      application();
      ~application() override;

      virtual string preferred_experience() override;
      void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::create * pcreate) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      virtual __pointer(impact) create_simple_drawing_view(::user::impact * pimpactParent, ::user::impact_data * pimpactdata);




      virtual ::type get_pane_view_type() const;



      //DECLARE_MESSAGE_HANDLER(_001OnSimpleCheckbox);

      // slowly phase out this idle/poll approach?
      // is it good for later consolidated evaluation?
      // is this "consolidated" evaluation the only advantage?
      // can it be replaced by custom-on-demand delayed consolidated active update when it is proper to do so?
      // isn't it taking this "_001OnUpdate" approach (and assuming this single advantage) builtin
      // early optimization with the cost of idle update? (is it really a optimization if the update is
      // done through idle/polled evaluation)?
      //DECLARE_MESSAGE_HANDLER(_001OnUpdateSimpleCheckbox);


      virtual ::atom translate_property_id(const ::atom& atom) override;
   };


} // namespace simple_drawing



