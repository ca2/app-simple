#pragma once


namespace app_simple_networking_application
{


   class CLASS_DECL_APP_SIMPLE_WEBSERVER application :
      virtual public ::base::application
   {
   public:



      ::user::document *                              m_pdocMenu;
      ::user::plain_edit_view *                       m_prollfps;
      ::user::single_document_template *              m_ptemplateSimpleDrawingMain;
      tab_view *                                      m_ptabview;


      application();
      ~application() override;


      virtual string preferred_experience() override;
      virtual ::e_status init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::create * pcreate) override;

#ifdef _DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

      virtual __pointer(impact) create_simple_drawing_view(::user::impact * pimpactParent, ::user::impact_data * pimpactdata);


      ::e_status create_networking_application() override;


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


   };


} // namespace app_simple_networking_application



