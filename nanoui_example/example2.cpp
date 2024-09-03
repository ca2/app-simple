/*
    src/example2.cpp -- C++ version of an example application that shows
    how to use the form helper class. For a Python implementation, see
    '../python/example2.py'.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
#include "framework.h"
#include "example2.h"
#include "main_window.h"
#include "nanoui/FormHelper.h"


////#include <nanoui/nanoui.h>
////#include <iostream>
//
//
using namespace nanoui;
//
//enum test_enum {
//   Item1 = 0,
//   Item2,
//   Item3
//};
//
//bool bvar = true;
//int ivar = 12345678;
//double dvar = 3.1415926;
//float fvar = (float)dvar;
//::string strval = "A string";
//::string strval2 = "";
//test_enum enumval = Item2;
//Color colval(0.5f, 0.5f, 0.7f, 1.f);


namespace app_simple_nanoui_example
{


   ExampleApplication2::ExampleApplication2(main_window * pmainwindow) :
      Screen(pmainwindow, { 500, 900 }, "NanoGUI Test"),
      m_pmainwindow(pmainwindow)
   {

      //nanoui::init();

      /* scoped variables */// {
         //bool use_gl_4_1 = false;// Set to true to create an OpenGL 4.1 context.
         //Screen * screen = nullptr;

         //if (use_gl_4_1) {
         //   // NanoGUI presents many options for you to utilize at your discretion.
         //   // See include/nanoui/screen.h for what all of these represent.
         //   screen = __new< Screen(Vector2i >(500, 700), "NanoGUI test [GL 4.1]",
         //      /* resizable */ true, /* fullscreen */ false,
         //      /* depth_buffer */ true, /* stencil_buffer */ true,
         //      /* float_buffer */ false, /* gl_major */ 4,
         //      /* gl_minor */ 1);
         //}
         //else {
         //   screen = __new< Screen(Vector2i >(500, 700), "NanoGUI test");
         //}

      nanoui::FormHelper * guiNanouiExample = new ::nanoui::FormHelper(this);
      m_pwindow = guiNanouiExample->add_window({ 10, 10 }, "nanoui example");
      guiNanouiExample->add_group("Buttons");
      guiNanouiExample->add_button("A button", [this]()
         { message_box_asynchronous(nullptr, screen()->m_puserinteraction, "Button pressed.");
         });

      bool enabled = true;
         nanoui::FormHelper * gui = new ::nanoui::FormHelper(this);
         m_pwindow = gui->add_window({ 10, 10 }, "Form helper example");
         gui->add_group("Basic types");
         gui->add_variable("bool", bvar);
         gui->add_variable("string", strval);
         gui->add_variable("placeholder", strval2)->set_placeholder("placeholder");

         gui->add_group("Validating fields");
         gui->add_variable("int", ivar)->set_spinnable(true);
         gui->add_variable("float", fvar);
         gui->add_variable("double", dvar)->set_spinnable(true);

         gui->add_group("Complex types");
         gui->add_variable("Enumeration", enumval, enabled)
            ->set_items({ "Item 1", "Item 2", "Item 3" });
         gui->add_variable("Color", colval);

         gui->add_group("Other widgets");
         gui->add_button("A button", [this]() 
            { message_box_asynchronous(nullptr, screen()->m_puserinteraction, "Button pressed.");
            });

         set_visible(true);
//         screen->perform_layout();
         //window->center();

        // nanoui::mainloop(-1);
      //}

      //nanoui::shutdown();

      //return 0;


         auto window = new Window(this, "Navigation");
         window->set_position({ 15, 680 });
         window->set_layout(new GroupLayout());



         auto b = new Button(window, "Next Example");
         b->set_callback(
            [this]
            {

               //message_box_synchronous(nullptr, "Pushed Plain Button!");/* std::cout << "pushed!" << std::endl; */

               m_pmainwindow->next_application();


            });
         b = new Button(window, "Previous Example");
         b->set_callback(
            [this]
            {

               //message_box_synchronous(nullptr, "Pushed Plain Button!");/* std::cout << "pushed!" << std::endl; */

               m_pmainwindow->previous_application();


            });
         //b->set_tooltip("short tooltip");


   }


   void ExampleApplication2::perform_layout(::nano2d::context * pcontext, bool bRecalcTextSize)
   {

      Screen::perform_layout(pcontext, bRecalcTextSize);

      m_pwindow->center();

   }


} // namespace app_simple_nanoui_example



