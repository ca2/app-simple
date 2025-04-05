#pragma once


#include "application.h"
#include "apex/platform/app_consumer.h"
#include "base/user/user/split_impact.h"


namespace app_simple_http_folder_upload
{


   class CLASS_DECL_APP_SIMPLE_HTTP_FOLDER_UPLOAD impact_path :
      virtual public ::app_consumer < application, ::user::split_impact >
   {
   public:


      main_impact * m_pmainimpact;
      ::pointer < impact_folder_path >    m_pimpactfolderpath;
      ::pointer < impact_netnode_url >    m_pimpactnetnodeurl;
      ::pointer < impact_start_button >   m_pimpactstartbutton;


      impact_path();
      ~impact_path() override;


      void on_create_split_impact() override;

      virtual void handle(::topic * ptopic, ::handler_context * phandlercontext) override;


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace RedDotLogicsInternal_license_manager





