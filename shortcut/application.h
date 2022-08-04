#pragma once



namespace app_simple_shortcut
{


   class CLASS_DECL_APP_SIMPLE_SHORTCUT application :
      virtual public ::base::application
   {
   public:


      bool                                   m_bMultiverseChat;

      ::user::document *                     m_pdocMenu;
      ::user::plain_edit_impact *              m_prollfps;
      ::user::single_document_template *     m_ptemplateBeatMapperMain;
      ::user::single_document_template *     m_ptemplateBeatMapperView;


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


   };


} // namespace simple_shortcut



