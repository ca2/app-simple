#include "framework.h"
#include "example1.h"
#include "nanogui/Icons.h"
#include "nanogui/ToolButton.h"
#include "nanogui/Graph.h"
#include "nanogui/ColorPicker.h"


namespace app_simple_nanogui_example
{


   ExampleApplication1::ExampleApplication1(main_window * pmainwindow) :
      Screen(Vector2i(1024, 768), "NanoGUI Test") ,
      m_pmainwindow(pmainwindow)
   {

      inc_ref();
      Window * window = new Window(this, "Button demo");
      window->set_position(Vector2i(15, 15));
      window->set_layout(new GroupLayout());

      ///* No need to store a pointer, the data structure will be automatically
      //   freed when the parent window is deleted */
      new Label(window, "Push buttons", "sans-bold");


      Button * b = new Button(window, "Plain button");
      b->set_callback([this] { os_message_box(nullptr, "Pushed Plain Button!");/* std::cout << "pushed!" << std::endl; */});
      b->set_tooltip("short tooltip");

      ///* Alternative construction notation using variadic template */
      b = window->add<Button>("Styled", FA_ROCKET);
      b->set_background_color(Color(0, 0, 255, 25));
      b->set_callback([this] { os_message_box(nullptr, "Pushed Styled!");/* std::cout << "pushed!" << std::endl; std::cout << "pushed!" << std::endl;*/ });
      b->set_tooltip("This button has a fairly long tooltip. It is so long, in "
         "fact, that the shown text will span several lines.");
      
      new Label(window, "Toggle buttons", "sans-bold");
      b = new Button(window, "Toggle me");
      b->set_flags(Button::ToggleButton);
      b->set_change_callback([](bool state)
         {
            string_stream str;
            str << "Toggle button state: " << state;
            os_message_box(nullptr, (::string &) str);
            
         
         });
      
         new Label(window, "Radio buttons", "sans-bold");
         b = new Button(window, "Radio button 1");
         b->set_flags(Button::RadioButton);
         b = new Button(window, "Radio button 2");
         b->set_flags(Button::RadioButton);
      
               new Label(window, "A tool palette", "sans-bold");
               Widget * tools = new Widget(window);
               tools->set_layout(new BoxLayout(Orientation::Horizontal,
                  Alignment::Middle, 0, 6));
      
               b = new ToolButton(tools, FA_CLOUD);
               b = new ToolButton(tools, FA_FAST_FORWARD);
               b = new ToolButton(tools, FA_COMPASS);
               b = new ToolButton(tools, FA_UTENSILS);
      
               new Label(window, "Popup buttons", "sans-bold");
               PopupButton * popup_btn = new PopupButton(window, "Popup", FA_FLASK);
               Popup * popup = popup_btn->popup();
               popup->set_layout(new GroupLayout());
               new Label(popup, "Arbitrary widgets can be placed here");
               new CheckBox(popup, "A check box");
               // popup right
               popup_btn = new PopupButton(popup, "Recursive popup", FA_CHART_PIE);
               Popup * popup_right = popup_btn->popup();
               popup_right->set_layout(new GroupLayout());
               new CheckBox(popup_right, "Another check box");
               // popup left
               popup_btn = new PopupButton(popup, "Recursive popup", FA_DNA);
               popup_btn->set_side(Popup::Side::Left);
               Popup * popup_left = popup_btn->popup();
               popup_left->set_layout(new GroupLayout());
               new CheckBox(popup_left, "Another check box");
      
               window = new Window(this, "Basic widgets");
               window->set_position(Vector2i(200, 15));
               window->set_layout(new GroupLayout());
      
               new Label(window, "Message dialog", "sans-bold");
               tools = new Widget(window);
               tools->set_layout(new BoxLayout(Orientation::Horizontal,
                  Alignment::Middle, 0, 6));
               b = new Button(tools, "Info");
               b->set_callback([&] {
                  auto dlg = new MessageDialog(this, MessageDialog::Type::Information, "Title", "This is an information message");
                  dlg->set_callback([](int result) { os_message_box(nullptr, "Dialog result: " + __string(result)); });
                  });
               b = new Button(tools, "Warn");
               b->set_callback([&] {
                  auto dlg = new MessageDialog(this, MessageDialog::Type::Warning, "Title", "This is a warning message");
                  dlg->set_callback([](int result) { os_message_box(nullptr, "Dialog result: " + __string(result)); });
                  });
               b = new Button(tools, "Ask");
               b->set_callback([&] {
                  auto dlg = new MessageDialog(this, MessageDialog::Type::Warning, "Title", "This is a question message", "Yes", "No", true);
                  dlg->set_callback([](int result) { os_message_box(nullptr, "Dialog result: " + __string(result)); });
                  });
      
      #if defined(_WIN32)
               /// Executable is in the Debug/Release/.. subdirectory
               std::string resources_folder_path("matter://icons");
      #else
               std::string resources_folder_path("./icons");
      #endif
               std::vector<std::pair<int, std::string>> icons;
      
      //#if !defined(EMSCRIPTEN)
      //         try {

      //            icons = load_image_directory(m_nvg_context, resources_folder_path);
      //         }
      //         catch (const exception & e) 
      //         {
      //            //std::cerr << "Warning: " << e.what() << std::endl;
      //         }
      //#endif
      
               new Label(window, "Image panel & scroll panel", "sans-bold");
               PopupButton * image_panel_btn = new PopupButton(window, "Image Panel");
               image_panel_btn->set_icon(FA_IMAGES);
               popup = image_panel_btn->popup();
               VScrollPanel * vscroll = new VScrollPanel(popup);
               ImagePanel * img_panel = new ImagePanel(vscroll);
               img_panel->load_image_directory("matter://icons");
               popup->set_fixed_size(Vector2i(245, 150));
      
               auto image_window = new Window(this, "Selected image");
               image_window->set_position(Vector2i(710, 15));
               image_window->set_layout(new GroupLayout(3));
      
               //// Create a Texture instance for each object
               //for (auto & icon : icons) {
               //   Vector2i size;
               //   int n = 0;
               //   ImageHolder texture_data(
               //      stbi_load((icon.second + ".png").c_str(), &size.x(), &size.y(), &n, 0),
               //      stbi_image_free);
               //   assert(n == 4);
      
               //   Texture * tex = new Texture(
               //      Texture::PixelFormat::RGBA,
               //      Texture::ComponentFormat::UInt8,
               //      size,
               //      Texture::InterpolationMode::Trilinear,
               //      Texture::InterpolationMode::Nearest);
      
               //   tex->upload(texture_data.get());
      
               //   m_images.emplace_back(tex, std::move(texture_data));
               //}
      
               ImageView * image_view = new ImageView(image_window);
               //if (!m_images.empty())
                 // image_view->set_image(m_images[0].first);
               image_view->center();
               m_current_image = 0;
      
               img_panel->set_callback([this, image_view, img_panel](int i) {
                  //std::cout << "Selected item " << i << std::endl;
                  image_view->set_image(img_panel->_get_image(i));
                  m_current_image = i;
                  });
      
               //image_view->set_pixel_callback(
               //   [this](const Vector2i & index, char ** out, size_t size) {
               //      const Texture * texture = m_images[m_current_image].first.get();
               //      uint8_t * data = m_images[m_current_image].second.get();
               //      for (int ch = 0; ch < 4; ++ch) {
               //         uint8_t value = data[(index.x() + index.y() * texture->size().x()) * 4 + ch];
               //         snprintf(out[ch], size, "%i", (int)value);
               //      }
               //   }
               //);
      
               new Label(window, "File dialog", "sans-bold");
               tools = new Widget(window);
               tools->set_layout(new BoxLayout(Orientation::Horizontal,
                  Alignment::Middle, 0, 6));
               b = new Button(tools, "Open");
               b->set_callback([this,image_view] {
                  
                  m_puserinteraction->m_psystem->node()->node_post(__routine([this, image_view]()
                             {
                  ::string str = file_dialog(
                     { {"png", "Portable Network Graphics"}, {"txt", "Text file"} }, false).c_str();

                  image_view->set_image(___load_image(m_puserinteraction, str));
                     
                  }));
                  
                  });

               b = new Button(tools, "Save");
               b->set_callback([this,image_view] {
                  
                  m_puserinteraction->m_psystem->node()->node_post(__routine([this, image_view]()
                             {

                  auto path = file_dialog(
                     { {"png", "Portable Network Graphics"}, {"txt", "Text file"} }, true);

                  ___save_image(m_puserinteraction, path.c_str(), image_view->image());
                  }));
                  });
      
               new Label(window, "Combo box", "sans-bold");
               new ComboBox(window, { "Combo box item 1", "Combo box item 2", "Combo box item 3" });
               new Label(window, "Check box", "sans-bold");
               CheckBox * cb = new CheckBox(window, "Flag 1",
                  [](bool state) { 
                     string_stream str;
                     str << "Check box 1 state: " << state;
                     os_message_box(nullptr, str.get_string());

                  }
               );
               cb->set_checked(true);
               cb = new CheckBox(window, "Flag 2",
                  [](bool state) { 
                     
                     string_stream str;
                     str << "Check box 2 state: " << state;
                     os_message_box(nullptr, str.get_string());

                  }
               );
               new Label(window, "Progress bar", "sans-bold");
               m_progress = new ProgressBar(window);
      
               new Label(window, "Slider and text box", "sans-bold");
      
               Widget * panel = new Widget(window);
               panel->set_layout(new BoxLayout(Orientation::Horizontal,
                  Alignment::Middle, 0, 20));
      
               Slider * slider = new Slider(panel);
               slider->set_value(0.5f);
               slider->set_fixed_width(80);
      
               TextBox * text_box = new TextBox(panel);
               text_box->set_fixed_size(Vector2i(60, 25));
               text_box->set_value("50");
               text_box->set_units("%");
               slider->set_callback([text_box](float value) {
                  text_box->set_value(std::to_string((int)(value * 100)));
                  });
               slider->set_final_callback([&](float value) {
                  string str;
                  
                  str.format("Final slider value: %d", (int)(value * 100));
                  os_message_box(nullptr, str);
                  });
               text_box->set_fixed_size(Vector2i(60, 25));
               text_box->set_font_size(20);
               text_box->set_alignment(TextBox::Alignment::Right);
      
               window = new Window(this, "Misc. widgets");
               window->set_position(Vector2i(425, 15));
               window->set_layout(new GroupLayout());
      
               TabWidget * tab_widget = window->add<TabWidget>();
      
               Widget * layer = new Widget(tab_widget);
               layer->set_layout(new GroupLayout());
               tab_widget->append_tab("Color Wheel", layer);
      
               // Use overloaded variadic add to fill the tab widget with Different tabs.
               layer->add<Label>("Color wheel widget", "sans-bold");
               layer->add<ColorWheel>();
      
               layer = new Widget(tab_widget);
               layer->set_layout(new GroupLayout());
               tab_widget->append_tab("Function Graph", layer);
      
               layer->add<Label>("Function graph widget", "sans-bold");
      
               Graph * graph = layer->add<Graph>("Some Function");
      
               graph->set_header("E = 2.35e-3");
               graph->set_footer("Iteration 89");
               std::vector<float> & func = graph->values();
               func.resize(100);
               for (int i = 0; i < 100; ++i)
                  func[i] = 0.5f * (0.5f * std::sin(i / 10.f) +
                     0.5f * std::cos(i / 23.f) + 1);
      
               // Dummy tab used to represent the last tab button.
               int plus_id = tab_widget->append_tab("+", new Widget(tab_widget));
      
               // A simple counter.
               int counter = 1;
               tab_widget->set_callback([tab_widget, this, counter, plus_id](int id) mutable {
                  if (id == plus_id) {
                     // When the "+" tab has been clicked, simply add a new tab.
                     std::string tab_name = "Dynamic " + std::to_string(counter);
                     Widget * layer_dyn = new Widget(tab_widget);
                     int new_id = tab_widget->insert_tab(tab_widget->tab_count() - 1,
                        tab_name, layer_dyn);
                     layer_dyn->set_layout(new GroupLayout());
                     layer_dyn->add<Label>("Function graph widget", "sans-bold");
                     Graph * graph_dyn = layer_dyn->add<Graph>("Dynamic function");
      
                     graph_dyn->set_header("E = 2.35e-3");
                     graph_dyn->set_footer("Iteration " + std::to_string(new_id * counter));
                     std::vector<float> & func_dyn = graph_dyn->values();
                     func_dyn.resize(100);
                     for (int i = 0; i < 100; ++i)
                        func_dyn[i] = 0.5f *
                        std::abs((0.5f * std::sin(i / 10.f + counter) +
                           0.5f * std::cos(i / 23.f + 1 + counter)));
                     ++counter;
                     tab_widget->set_selected_id(new_id);
      
                     // We must invoke the layout manager after adding tabs dynamically
                     //perform_layout();
                     //m_bPendingLayout = true;
                  }
                  });
      
               // A button to go back to the first tab and scroll the window.
               panel = window->add<Widget>();
               panel->add<Label>("Jump to tab: ");
               panel->set_layout(new BoxLayout(Orientation::Horizontal,
                  Alignment::Middle, 0, 6));
      
               auto ib = panel->add<IntBox<int>>();
               ib->set_editable(true);
      
               b = panel->add<Button>("", FA_FORWARD);
               b->set_fixed_size(Vector2i(22, 22));
               ib->set_fixed_height(22);
               b->set_callback([tab_widget, ib] {
                  int value = ib->value();
                  if (value >= 0 && value < tab_widget->tab_count())
                     tab_widget->set_selected_index(value);
                  });
      
               window = new Window(this, "Grid of small widgets");
               window->set_position(Vector2i(425, 300));
               GridLayout * layout =
                  new GridLayout(Orientation::Horizontal, 2,
                     Alignment::Middle, 15, 5);
               layout->set_col_alignment(
                  { Alignment::Maximum, Alignment::Fill });
               layout->set_spacing(0, 10);
               window->set_layout(layout);
      
               /* FP widget */ {
                  new Label(window, "Floating point :", "sans-bold");
                  text_box = new TextBox(window);
                  text_box->set_editable(true);
                  text_box->set_fixed_size(Vector2i(100, 20));
                  text_box->set_value("50");
                  text_box->set_units("GiB");
                  text_box->set_default_value("0.0");
                  text_box->set_font_size(16);
                  text_box->set_format("[-]?[0-9]*\\.?[0-9]+");
               }
      
               /* Positive integer widget */ {
                  new Label(window, "Positive integer :", "sans-bold");
                  auto int_box = new IntBox<int>(window);
                  int_box->set_editable(true);
                  int_box->set_fixed_size(Vector2i(100, 20));
                  int_box->set_value(50);
                  int_box->set_units("Mhz");
                  int_box->set_default_value("0");
                  int_box->set_font_size(16);
                  int_box->set_format("[1-9][0-9]*");
                  int_box->set_spinnable(true);
                  int_box->set_min_value(1);
                  int_box->set_value_increment(2);
               }
      
               /* Checkbox widget */ {
                  new Label(window, "Checkbox :", "sans-bold");
      
                  cb = new CheckBox(window, "Check me");
                  cb->set_font_size(16);
                  cb->set_checked(true);
               }
      
               new Label(window, "Combo box :", "sans-bold");
               ComboBox * cobo =
                  new ComboBox(window, { "Item 1", "Item 2", "Item 3" });
               cobo->set_font_size(16);
               cobo->set_fixed_size(Vector2i(100, 20));
      
               new Label(window, "Color picker :", "sans-bold");
               auto cp = new ColorPicker(window, { 255, 120, 0, 255 });
               cp->set_fixed_size({ 100, 20 });
               cp->set_final_callback([](const Color & c) {
                  string_stream str;
                  str << "ColorPicker final callback: ["
                     << c.r() << ", "
                     << c.g() << ", "
                     << c.b() << ", "
                     << c.w() << "]";
                  os_message_box(nullptr, str.get_string());
                  });
               // setup a fast callback for the color picker widget on a new window
               // for demonstrative purposes
               window = new Window(this, "Color Picker Fast Callback");
               layout = new GridLayout(Orientation::Horizontal, 2,
                  Alignment::Middle, 15, 5);
               layout->set_col_alignment(
                  { Alignment::Maximum, Alignment::Fill });
               layout->set_spacing(0, 10);
               window->set_layout(layout);
               window->set_position(Vector2i(425, 500));
               new Label(window, "Combined: ");
               b = new Button(window, "ColorWheel", FA_INFINITY);
               new Label(window, "Red: ");
               auto red_int_box = new IntBox<int>(window);
               red_int_box->set_editable(false);
               new Label(window, "Green: ");
               auto green_int_box = new IntBox<int>(window);
               green_int_box->set_editable(false);
               new Label(window, "Blue: ");
               auto blue_int_box = new IntBox<int>(window);
               blue_int_box->set_editable(false);
               new Label(window, "Alpha: ");
               auto alpha_int_box = new IntBox<int>(window);
      
               cp->set_callback([b, red_int_box, blue_int_box, green_int_box, alpha_int_box](const Color & c) {
                  b->set_background_color(c);
                  b->set_text_color(c.contrasting_color());
                  int red = (int)(c.r() * 255.0f);
                  red_int_box->set_value(red);
                  int green = (int)(c.g() * 255.0f);
                  green_int_box->set_value(green);
                  int blue = (int)(c.b() * 255.0f);
                  blue_int_box->set_value(blue);
                  int alpha = (int)(c.w() * 255.0f);
                  alpha_int_box->set_value(alpha);
                  });
      

               window = new Window(this, "Navigation");
               window->set_position(Vector2i(15, 680));
               window->set_layout(new GroupLayout());



               b = new Button(window, "Next Example");
               b->set_callback(
                  [this] 
                  { 
                     
                     //os_message_box(nullptr, "Pushed Plain Button!");/* std::cout << "pushed!" << std::endl; */

                     m_pmainwindow->next_application();


                  });
               b = new Button(window, "Previous Example");
               b->set_callback(
                  [this]
                  {

                     //os_message_box(nullptr, "Pushed Plain Button!");/* std::cout << "pushed!" << std::endl; */

                     m_pmainwindow->previous_application();


                  });
               b->set_tooltip("short tooltip");


   }

   //
   //void start(ExampleApplication *& papplication, ::user::interaction * puserinteraction)
   //{

   //   papplication = new ExampleApplication;

   //   papplication->_nanogui_to_user(puserinteraction);

   //}


   //void finish(ExampleApplication * & papplication)
   //{

   //   ::acme::del(papplication);

   //}


} // namespace simple_application



