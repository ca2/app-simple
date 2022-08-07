#pragma once



namespace app_simple_shader
{


   class CLASS_DECL_APP_SIMPLE_SHADER application :
      virtual public ::app_shader::application,
      virtual public ::core::application
   {
   public:


      //::enum_check &                         m_echeckSimple;
      //::enum_check &                         m_echeckNoClientFrame;
      //string &                               m_strSimple;

      //bool                                   m_bMultiverseChat;

      //::user::document *                     m_pdocMenu;
      //::user::plain_edit_impact *              m_prollfps;
      ::user::single_document_template *     m_ptemplateSimpleShaderMain;
      tab_impact *                             m_ptabimpact;

      string                                 m_strMainTitle;


      application();
      ~application() override;

      virtual string preferred_experience() override;
      void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::create * pcreate) override;

//#ifdef _DEBUG
//      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
//      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
//#endif

      virtual __pointer(impact) create_simple_shader_impact(::user::impact * pimpactParent, ::user::impact_data * pimpactdata);


      //virtual string get_main_title() const;
      //virtual string get_hover_font() const;


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


} // namespace simple_shader



