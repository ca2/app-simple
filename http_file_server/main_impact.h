#pragma once


#include "application.h"
#include "apex/platform/app_consumer.h"
#include "base/user/user/split_impact.h"


namespace app_simple_http_file_server
{


   class CLASS_DECL_APP_SIMPLE_HTTP_FILE_SERVER main_impact :
      virtual public ::app_consumer < application, ::user::split_impact >
   {
   public:


      ::pointer < edit_impact >                    m_peditimpact;
      ::pointer < app_simple_http_file_server::impact >        m_pimpact;
      ::pointer < tab_impact >                     m_ptabimpact;


      main_impact();
      ~main_impact() override;


      void on_create_split_impact() override;

      virtual void handle(::topic * ptopic, ::handler_context * phandlercontext) override;


      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



   };


} // namespace RedDotLogicsInternal_license_manager





