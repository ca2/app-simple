// From nanogui by camilo on 2022/03/18 2:01 AM <3ThomasBorregaardSørensen!!
#pragma once

using namespace nanogui;


namespace app_simple_nanogui_example
{



   class CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE ExampleApplication1   : public nanogui::Screen {
   public:

      __pointer(impact) m_pimpact;

      int m_current_image;

      ProgressBar * m_progress;

      ExampleApplication1(impact * pimpact);

   };




} // namespace simple_application



