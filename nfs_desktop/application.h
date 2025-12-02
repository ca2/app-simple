#pragma once


#include "berg/platform/application.h"


class nfs;


namespace app_simple_nfs_desktop
{


   class CLASS_DECL_APP_SIMPLE_NFS_DESKTOP application :
      virtual public ::berg::application
   {
   public:


      ::file::path                                    m_pathFolder;
      ::user::document *                              m_pdocMenu;
      ::user::plain_edit_impact *                     m_prollfps;
      tab_impact *                                    m_ptabimpact;
      
      ::pointer < nfs >                               m_pnfs;

      ::property_set                                  m_set; 


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


      //virtual void read_ini();
      //virtual void write_ini();


      //::string get_bind_address() const override;
      //void set_bind_address(const ::scoped_string & scopedstrBindAddress) override;

      //virtual ::pointer<impact> create_simple_drawing_impact(::user::impact * pimpactParent, ::user::impact_data * pimpactdata);


      //void create_networking_application() override;


      virtual ::platform::type get_pane_impact_type() const;



      //DECLARE_MESSAGE_HANDLER(_001OnSimpleCheckbox);

      // slowly phase out this idle/poll approach?
      // is it good for later consolidated evaluation?
      // is this "consolidated" evaluation the only advantage?
      // can it be replaced by custom-on-demand delayed consolidated active update when it is proper to do so?
      // isn't it taking this "_001OnUpdate" approach (and assuming this single advantage) builtin
      // early optimization with the cost of idle update? (is it really a optimization if the update is
      // done through idle/polled evaluation)?
      //DECLARE_MESSAGE_HANDLER(_001OnUpdateSimpleCheckbox);

      void create_options_body(::user::interaction * pparent) override;


   };


} // namespace app_simple_nfs_desktop



