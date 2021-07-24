﻿#pragma once



namespace simple_application
{


   class CLASS_DECL_APP_SIMPLE_APPLICATION application :
      virtual public ::base::application
   {
   public:



      ::user::document *                              m_pdocMenu;
      __composite(::user::single_document_template)   m_ptemplateSimpleDrawingMain;
      pane_view *                                     m_ppaneview;

      application();
      virtual ~application();

      virtual string preferred_experience() override;
      virtual ::e_status init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::create * pcreate) override;

#ifdef DEBUG
      virtual int64_t increment_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
      virtual int64_t decrement_reference_count(OBJECT_REFERENCE_COUNT_DEBUG_PARAMETERS) override;
#endif

   };


} // namespace simple_application



