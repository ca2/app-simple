// From nanoui by camilo on 2022/03/22 2:01 AM <3ThomasBorregaardSorensen!!
#pragma once


#include "app/nanoui/Screen.h"


using namespace nanoui;


namespace app_simple_nanoui_example
{


   class CLASS_DECL_APP_SIMPLE_NANOUI_EXAMPLE ExampleApplicationIcons : public nanoui::Screen
   {
   public:


      ::pointer<main_window>        m_pmainwindow;


      ::pointer<Window>             m_pwindow;


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
      test_enum enumval = Item2;

      Screen * screen = nullptr;

      ::color::color colval = rgba(0.5f, 0.5f, 0.7f, 1.f);

      ExampleApplicationIcons(main_window * pmainwindow);

      void perform_layout(::nano2d::context * pcontext, bool bRecalcTextSize = true) override;


   };




} // namespace simple_application





