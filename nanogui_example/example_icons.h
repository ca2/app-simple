// From nanogui by camilo on 2022/03/22 2:01 AM <3ThomasBorregaardS�rensen!!
#pragma once

using namespace nanogui;


namespace app_simple_nanogui_example
{



   class CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE ExampleApplicationIcons : public nanogui::Screen
   {
   public:

      __pointer(impact) m_pimpact;

      ref<Window> m_window;


      enum test_enum {
         Item1 = 0,
         Item2,
         Item3
      };

      bool bvar = true;
      int ivar = 12345678;
      double dvar = 3.1415926;
      float fvar = (float)dvar;
      std::string strval = "A string";
      test_enum enumval = Item2;

      Screen * screen = nullptr;

      ::nanogui::Color colval = { 0.5f, 0.5f, 0.7f, 1.f };

      ExampleApplicationIcons(impact * pimpact);

      void perform_layout(NVGcontext * pcontext) override;


   };




} // namespace simple_application




