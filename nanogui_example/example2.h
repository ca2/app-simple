// From nanogui by camilo on 2022/03/18 2:01 AM <3ThomasBorregaardS�rensen!!
#pragma once


namespace app_simple_nanogui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE ExampleApplication2 : 
      public nanogui::Screen
   {
   public:


      __pointer(main_window)                 m_pmainwindow;


      ::nanogui::ref<::nanogui::Window>      m_window;

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
      std::string strval2 = "";
      test_enum enumval = Item2;
      ::nanogui::Color colval = { 0.5f, 0.5f, 0.7f, 1.f };

      ExampleApplication2(main_window * pmainwindow);

      void perform_layout(NVGcontext * pcontext, bool bRecalcTextSize = true) override;


   };




} // namespace simple_application



