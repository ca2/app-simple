// From nanogui by camilo on 2022/03/18 2:01 AM <3ThomasBorregaardSørensen!!
#pragma once

using namespace nanogui;

namespace app_simple_nanogui_example1
{



   class CLASS_DECL_APP_SIMPLE_NANOGUI_EXAMPLE1 ExampleApplication : public nanogui::Screen {
   public:
      ExampleApplication() : Screen(Vector2i(1024, 768), "NanoGUI Test") {
         inc_ref();
         Window * window = new Window(this, "Button demo");
         window->set_position(Vector2i(15, 15));
         window->set_layout(new GroupLayout());

         /* No need to store a pointer, the data structure will be automatically
            freed when the parent window is deleted */
         new Label(window, "Push buttons", "sans-bold");

      }

   };




} // namespace simple_application



