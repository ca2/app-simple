// From nanoui by camilo on 2022/03/18 2:01 AM <3ThomasBorregaardS�rensen!!
#pragma once


#include "nanoui/Screen.h"


namespace app_simple_nanoui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOUI_EXAMPLE ExampleApplication2 : 
      public nanoui::Screen
   {
   public:


      ::pointer<main_window>                 m_pmainwindow;


      ::nanoui::ref<::nanoui::Window>      m_window;

      enum test_enum {
         Item1 = 0,
         Item2,
         Item3
      };

      bool bvar = true;
      int ivar = 12345678;
      double dvar = 3.1415926;
      float fvar = (float)dvar;
      ::string strval = "A string";
      ::string strval2 = "";
      test_enum enumval = Item2;
      ::color::color colval = { 0.5f, 0.5f, 0.7f, 1.f };

      ExampleApplication2(main_window * pmainwindow);

      void perform_layout(::nano2d::context * pcontext, bool bRecalcTextSize = true) override;


   };




} // namespace simple_application



