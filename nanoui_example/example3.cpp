/*
    src/example3.cpp -- C++ version of an example application that shows
    how to use nanoui in an application with an already created and managed
    GLFW context.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
#include "framework.h"

#include "example3.h"
#include "nanoui/FormHelper.h"

//#include "nanoui/FormHelper.h"
//// GLFW
////
//#if defined(NANOUI_USE_OPENGL)
//#  if defined(NANOUI_GLAD)
//#    if defined(NANOUI_SHARED) && !defined(GLAD_GLAPI_EXPORT)
//#      define GLAD_GLAPI_EXPORT
//#    endif
//#    include <glad/glad.h>
//#  else
//#    if defined(__APPLE__)
//#      define GLFW_INCLUDE_GLCOREARB
//#    else
//#      define GL_GLEXT_PROTOTYPES
//#    endif
//#  endif
//#elif defined(NANOUI_USE_GLES)
//#  define GLFW_INCLUDE_ES2
//#endif
//
//#include <GLFW/glfw3.h>
//#include <nanoui/nanoui.h>
//#include <iostream>
//

namespace app_simple_nanoui_example
{


   ExampleApplication3::ExampleApplication3(impact * pimpact) :
      Screen(Vector2i(500, 900), "NanoGUI Test"),
      m_pimpact(pimpact)
   {

//using namespace nanoui;
//
//enum test_enum {
//    Item1 = 0,
//    Item2,
//    Item3
//};
//
//bool bvar = true;
//int ivar = 12345678;
//double dvar = 3.1415926;
//float fvar = (float)dvar;
//std::string strval = "A string";
//test_enum enumval = Item2;
//Color colval(0.5f, 0.5f, 0.7f, 1.f);
//
//Screen *screen = nullptr;
//
//int main(int /* argc */, char ** /* argv */) {
//    glfwInit();
//    glfwSetTime(0);
//
//#if defined(NANOUI_USE_OPENGL)
//    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#elif defined(NANOUI_USE_GLES)
//    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
//
//    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
//#elif defined(NANOUI_USE_METAL)
//    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//
//    metal_init();
//#endif
//
//    glfwWindowHint(GLFW_SAMPLES, 0);
//    glfwWindowHint(GLFW_RED_BITS, 8);
//    glfwWindowHint(GLFW_GREEN_BITS, 8);
//    glfwWindowHint(GLFW_BLUE_BITS, 8);
//    glfwWindowHint(GLFW_ALPHA_BITS, 8);
//    glfwWindowHint(GLFW_STENCIL_BITS, 8);
//    glfwWindowHint(GLFW_DEPTH_BITS, 24);
//    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
//
//    // Create a GLFWwindow object
//    GLFWwindow* window = glfwCreateWindow(500, 700, "example3", nullptr, nullptr);
//    if (window == nullptr) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//#if defined(NANOUI_GLAD)
//    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
//        throw std::runtime_error("Could not initialize GLAD!");
//    glGetError(); // pull and ignore unhandled errors like GL_INVALID_ENUM
//#endif
//
//    // Create a nanoui screen and pass the glfw pointer to initialize
//    screen = ___new Screen();
//    screen->initialize(window, true);
//
//#if defined(NANOUI_USE_OPENGL) || defined(NANOUI_USE_GLES)
//    int width, height;
//    glfwGetFramebufferSize(window, &width, &height);
//    glContext(0, 0, width, height);
//    glfwSwapInterval(0);
//    glfwSwapBuffers(window);
//#endif
//
    // Create nanoui gui
    bool enabled = true;
    FormHelper *gui = ___new FormHelper(this);
    m_window = gui->add_window(Vector2i(10, 10), "Form helper example");
    gui->add_group("Basic types");
    gui->add_variable("bool", bvar)->set_tooltip("Test tooltip.");
    gui->add_variable("string", strval);

    gui->add_group("Validating fields");
    gui->add_variable("int", ivar)->set_spinnable(true);
    gui->add_variable("float", fvar)->set_tooltip("Test.");
    gui->add_variable("double", dvar)->set_spinnable(true);

    gui->add_group("Complex types");
    gui->add_variable("Enumeration", enumval, enabled)->set_items({ "Item 1", "Item 2", "Item 3" });
    gui->add_variable("Color", colval);

    gui->add_group("Other widgets");
    gui->add_button("A button", []()
       { auto pmessagebox = __initialize_new ::message_box(nullptr, "Button pressed.");

pmessagebox->sync(); }
    )
       ->set_tooltip("Testing a much longer tooltip, that will wrap around to ___new lines multiple times.");;

    this->set_visible(true);
    //screen->perform_layout();
//    nanoui_window->center();
//    screen->clear();
//    screen->draw_all();
//
//    glfwSetCursorPosCallback(window,
//            [](GLFWwindow *, double x, double y) {
//            screen->cursor_pos_callback_event(x, y);
//        }
//    );
//
//    glfwSetMouseButtonCallback(window,
//        [](GLFWwindow *, int button, int action, int modifiers) {
//            screen->mouse_button_callback_event(button, action, modifiers);
//        }
//    );
//
//    glfwSetKeyCallback(window,
//        [](GLFWwindow *, int key, int scancode, int action, int mods) {
//            screen->key_callback_event(key, scancode, action, mods);
//        }
//    );
//
//    glfwSetCharCallback(window,
//        [](GLFWwindow *, unsigned int codepoint) {
//            screen->char_callback_event(codepoint);
//        }
//    );
//
//    glfwSetDropCallback(window,
//        [](GLFWwindow *, int count, const char **filenames) {
//            screen->drop_callback_event(count, filenames);
//        }
//    );
//
//    glfwSetScrollCallback(window,
//        [](GLFWwindow *, double x, double y) {
//            screen->scroll_callback_event(x, y);
//       }
//    );
//
//    glfwSetFramebufferSizeCallback(window,
//        [](GLFWwindow *, int width, int height) {
//            screen->resize_callback_event(width, height);
//        }
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window)) {
//        // Check if any happenings have been activated (key pressed, mouse moved etc.) and call corresponding response functions
//        glfwPollEvents();
//
//#if defined(NANOUI_USE_METAL)
//        // Important to periodically free memory used up by Metal command queues, etc.
//        void *pool = autorelease_init();
//#endif
//
//        // Draw nanoui
//        screen->draw_setup();
//        screen->clear(); // glClear
//        screen->draw_contents();
//        screen->draw_widgets();
//        screen->draw_teardown();
//
//#if defined(NANOUI_USE_METAL)
//        autorelease_release(pool);
//#endif
//
//        glfwSwapBuffers(window);
//    }
//
//    // Terminate GLFW, clearing any resources allocated by GLFW.
//    glfwTerminate();
//
//#if defined(NANOUI_USE_METAL)
//    metal_shutdown();
//#endif
//
//    return 0;
//}


   }


   void ExampleApplication3::perform_layout(NVGcontext * pcontext)
   {

      Screen::perform_layout(pcontext);

      m_window->center();

   }


} // namespace app_simple_nanoui_example



