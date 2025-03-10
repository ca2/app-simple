#pragma once


#include "base/platform/application.h"
#include "acme/prototype/data/check_property.h"

namespace app_simple_drawing
{


   class CLASS_DECL_APP_SIMPLE_DRAWING application :
      virtual public ::base::application
   {
   public:


      ::data::check_property           m_checkSimple;
      ::data::check_property           m_checkNoClientFrame;
      ::data::text_property            m_textSimple;
      ::data::text_property            m_textMainTitle;
      //__PROPERTIES(application)
      //   __PROPERTY(e_check, m_echeckSimple, "simple_checkbox");
      //   __PROPERTY(e_check, m_echeckNoClientFrame, "no_client_frame");
      //   __PROPERTY(string, m_strSimple, "simple_text");
      //   __PROPERTY(string, m_strMainTitle, "main_title");
      //__END_PROPERTIES(application);

      


      bool                                   m_bMultiverseChat;

      ::user::document *                     m_pdocMenu;
      ::user::plain_edit_impact *              m_prollfps;
      //::user::single_document_template *     m_ptemplateSimpleDrawingMain;
      tab_impact *                             m_ptabimpact;

      application();
      ~application() override;
      

      __DECLARE_APPLICATION_RELEASE_TIME();


      virtual string preferred_experience() override;
      void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::request * prequest) override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      virtual ::pointer<impact> create_simple_drawing_impact(::user::impact * pimpactParent, ::user::impact_data * pimpactdata);




      virtual ::type_atom get_pane_impact_type() const;



      //DECLARE_MESSAGE_HANDLER(_001OnSimpleCheckbox);

      // slowly phase out this idle/poll approach?
      // is it good for later consolidated evaluation?
      // is this "consolidated" evaluation the only advantage?
      // can it be replaced by custom-on-demand delayed consolidated active update when it is proper to do so?
      // isn't it taking this "_001OnUpdate" approach (and assuming this single advantage) builtin
      // early optimization with the cost of idle update? (is it really a optimization if the update is
      // done through idle/polled evaluation)?
      //DECLARE_MESSAGE_HANDLER(_001OnUpdateSimpleCheckbox);


      //virtual ::atom translate_property_id(const ::atom& atom) override;


      string draw2d_get_default_implementation_name() override;


   };


} // namespace simple_drawing



