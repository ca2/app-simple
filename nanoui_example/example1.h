// From nanoui by camilo on 2022/03/18 2:01 AM <3ThomasBorregaardSørensen!!
#pragma once


#include "app/nanoui/Screen.h"


using namespace nanoui;


namespace app_simple_nanoui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOUI_EXAMPLE ExampleApplication1 :
      public nanoui::Screen 
   {
   public:

      ::pointer<main_window>  m_pmainwindow;

      int m_current_image;

      ProgressBar * m_progress;

      ExampleApplication1(main_window * pmainwindow);


      void draw_contents(::nano2d::context * ctx) override;


   };




} // namespace simple_application



