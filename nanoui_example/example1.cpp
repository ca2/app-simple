#include "framework.h"
#include "example1.h"
#include "main_window.h"
#include "acme/constant/_font_awesome.h"
#include "acme/graphics/draw2d/_text_stream.h"
#include "acme/platform/node.h"
#include "nanoui/CheckBox.h"
#include "nanoui/Layout.h"
#include "nanoui/Screen.h"
#include "nanoui/Label.h"
//#include "nanoui/Icons.h"
#include "nanoui/ToolButton.h"
#include "nanoui/Graph.h"
#include "nanoui/ColorPicker.h"
#include "nanoui/TextBox.h"
#include "nanoui/MessageDialog.h"
#include "nanoui/VScrollPanel.h"
#include "nanoui/ImagePanel.h"
#include "nanoui/ImageImpact.h"
#include "nanoui/IntBox.h"
#include "nanoui/ComboBox.h"
#include "nanoui/ProgressBar.h"
#include "nanoui/Slider.h"
#include "nanoui/TabWidget.h"
#include "nanoui/ColorWheel.h"
#include "nano2d/context.h"
#include "acme/filesystem/file/file_stream1.h"
#include "acme/filesystem/filesystem/file_dialog.h"
#include "aura/windowing/window.h"


namespace app_simple_nanoui_example
{


   ExampleApplication1::ExampleApplication1(main_window * pmainwindow) :
      Screen(pmainwindow, { 1024, 768 }, "NanoGUI Test"),
      m_pmainwindow(pmainwindow)
   {

      //inc_ref();
      Window * window = ___new Window(this, "Button demo");
      window->set_position({ 15, 15 });
      window->set_layout(___new GroupLayout());

      ///* No need to store a pointer, the data structure will be automatically
      //   freed when the parent window is deleted */
      ___new Label(window, "Push buttons", "sans-bold");


      Button * b = ___new Button(window, "Plain button");
      b->set_callback([this] 
         {
            auto pmessagebox = __initialize_new::message_box("Pushed Plain Button!");
            /* std::cout << "pushed!" << std::endl; */ 
            pmessagebox->async();
         
         });
      b->set_tooltip("short tooltip");

      ///* Alternative construction notation using variadic template */
      b = window->add<Button>("Styled", e_font_awesome_rocket);
      b->set_background_color(::rgba(0, 0, 255, 25));
      b->set_callback([this] { 
         auto pmessagebox = __initialize_new::message_box("Pushed Styled!");
         /* std::cout << "pushed!" << std::endl; std::cout << "pushed!" << std::endl;*/ 
         pmessagebox->async();
         });
      b->set_tooltip("This button has a fairly long tooltip. It is so long, in "
         "fact, that the shown text will span several lines.");
      
      ___new Label(window, "Toggle buttons", "sans-bold");
      b = ___new Button(window, "Toggle me");
      b->set_flags(Button::ToggleButton);
      b->set_change_callback([this](bool state)
         {
            string_stream str;
            str << "Toggle button state: " << state;
            auto pmessagebox = message_box(str.as_string());
            pmessagebox->async();
         
         });
      
         ___new Label(window, "Radio buttons", "sans-bold");
         b = ___new Button(window, "Radio button 1");
         b->set_flags(Button::RadioButton);
         b = ___new Button(window, "Radio button 2");
         b->set_flags(Button::RadioButton);
      
               ___new Label(window, "A tool palette", "sans-bold");
               Widget * tools = ___new Widget(window);
               tools->set_layout(___new BoxLayout(::e_orientation_horizontal,
                  ::nanoui::e_alignment_middle, 0, 6));
      
               b = ___new ToolButton(tools, e_font_awesome_cloud);
               b = ___new ToolButton(tools, e_font_awesome_fast_forward);
               b = ___new ToolButton(tools, e_font_awesome_compass);
               b = ___new ToolButton(tools, e_font_awesome_utensils);
      
               ___new Label(window, "Popup buttons", "sans-bold");
               PopupButton * popup_btn = ___new PopupButton(window, "Popup", e_font_awesome_flask);
               Popup * popup = popup_btn->popup();
               popup->set_layout(___new GroupLayout());
               ___new Label(popup, "Arbitrary widgets can be placed here");
               ___new CheckBox(popup, "A check box");
               // popup right
               popup_btn = ___new PopupButton(popup, "Recursive popup", e_font_awesome_chart_pie);
               Popup * popup_right = popup_btn->popup();
               popup_right->set_layout(___new GroupLayout());
               ___new CheckBox(popup_right, "Another check box");
               // popup left
               popup_btn = ___new PopupButton(popup, "Recursive popup", e_font_awesome_dna);
               popup_btn->set_side(Popup::Side::Left);
               Popup * popup_left = popup_btn->popup();
               popup_left->set_layout(___new GroupLayout());
               ___new CheckBox(popup_left, "Another check box");
      
               window = ___new Window(this, "Basic widgets");
               window->set_position({ 200, 15 });
               window->set_layout(___new GroupLayout());
      
               ___new Label(window, "Message dialog", "sans-bold");
               tools = ___new Widget(window);
               tools->set_layout(___new BoxLayout(::e_orientation_horizontal,
                  e_alignment_middle, 0, 6));
               b = ___new Button(tools, "Info");
               b->set_callback([this] {
                  auto dlg = ___new MessageDialog(this, MessageDialog::Type::Information, "Title", "This is an information message");
                  dlg->set_callback([this](int result) { 
                     auto pmessagebox = __initialize_new::message_box("Dialog result: " + ::as_string(result)); 
                     
                     pmessagebox->async();
                     });
                  });
               b = ___new Button(tools, "Warn");
               b->set_callback([this] {
                  auto dlg = ___new MessageDialog(this, MessageDialog::Type::Warning, "Title", "This is a warning message");
                  dlg->set_callback([this](int result) 
                     {
                        auto pmessagebox = __initialize_new::message_box("Dialog result: " + ::as_string(result)); 
                     
                        pmessagebox->async();
                     });
                  });
               b = ___new Button(tools, "Ask");
               b->set_callback([this] {
                  auto dlg = ___new MessageDialog(this, MessageDialog::Type::Warning, "Title", "This is a question message", "Yes", "No", true);
                  dlg->set_callback([this](int result) 
                     {
                        auto pmessagebox = __initialize_new::message_box("Dialog result: " + ::as_string(result)); 
                     
                        pmessagebox->async();
                     });
                  });
      
      #if defined(_WIN32)
               /// Executable is in the Debug/Release/.. subdirectory
               ::string resources_folder_path("matter://icons");
      #else
               ::string resources_folder_path("./icons");
      #endif
               ::array<::pair<int, ::string>> icons;
      
      //#if !defined(EMSCRIPTEN)
      //         try {

      //            icons = load_image_directory(m_nvg_context, resources_folder_path);
      //         }
      //         catch (const exception & e) 
      //         {
      //            //std::cerr << "Warning: " << e.what() << std::endl;
      //         }
      //#endif
      
               ___new Label(window, "Image panel & scroll panel", "sans-bold");
               PopupButton * image_panel_btn = ___new PopupButton(window, "Image Panel");
               image_panel_btn->set_icon(e_font_awesome_images);
               popup = image_panel_btn->popup();
               VScrollPanel * vscroll = ___new VScrollPanel(popup);
               ImagePanel * img_panel = ___new ImagePanel(vscroll);
               img_panel->load_image_directory("matter://icons");
               popup->set_fixed_size({ 245, 150 });
      
               auto image_window = ___new Window(this, "Selected image");
               image_window->set_position({ 710, 15 });
               image_window->set_layout(___new GroupLayout(3));
      
               //// Create a Texture instance for each object
               //for (auto & icon : icons) {
               //   Vector2i size;
               //   int n = 0;
               //   ImageHolder texture_data(
               //      stbi_load((icon.second + ".png").c_str(), &size.cx(), &size.cy(), &n, 0),
               //      stbi_image_free);
               //   assert(n == 4);
      
               //   Texture * tex = ___new Texture(
               //      Texture::PixelFormat::RGBA,
               //      Texture::ComponentFormat::UInt8,
               //      size,
               //      Texture::InterpolationMode::Trilinear,
               //      Texture::InterpolationMode::Nearest);
      
               //   tex->upload(texture_data.get());
      
               //   m_images.emplace_back(tex, std::transfer(texture_data));
               //}
      
               ImageImpact * image_impact = ___new ImageImpact(image_window);
               //if (!m_images.empty())
                 // image_impact->set_image(m_images[0].first);
               image_impact->center();
               m_current_image = 0;
      
               img_panel->set_callback([this, image_impact, img_panel](::collection::index i) {
                  //std::cout << "Selected item " << i << std::endl;
                  image_impact->set_image(img_panel->_get_image(i));
                  m_current_image = i;
                  });
      
               //image_impact->set_pixel_callback(
               //   [this](const Vector2i & index, char ** out, size_t size) {
               //      const Texture * texture = m_images[m_current_image].first.get();
               //      uint8_t * data = m_images[m_current_image].second.get();
               //      for (int ch = 0; ch < 4; ++ch) {
               //         uint8_t value = data[(index.x() + index.y() * texture->size().x()) * 4 + ch];
               //         snprintf(out[ch], size, "%i", (int)value);
               //      }
               //   }
               //);
      
               ___new Label(window, "File dialog", "sans-bold");
               tools = ___new Widget(window);
               tools->set_layout(___new BoxLayout(::e_orientation_horizontal,
                  ::nanoui::e_alignment_middle, 0, 6));
               b = ___new Button(tools, "Open");
               b->set_callback([this,image_impact] {
                  
                  //m_puserinteraction->node()->node_post(__routine([this, image_impact]()
                    //         {
                  //auto pwindow = m_puserinteraction->window();
                  //auto poswindow = pwindow->get_os_data();
                  auto pdialog = node()->node_file_dialog();
                  pdialog->m_filedialogfilter.add({ "Portable Network Graphics", "*.png" });
                  pdialog->m_filedialogfilter.add({ "JPEG file", "*.jpeg" });
                  pdialog->m_filedialogfilter.add({ "JPG file", "*.jpg" });
                  pdialog->m_filedialogfilter.add({ "Text file", "*.txt" });
                  pdialog->m_function = [this, image_impact](::file::file_dialog * pdialog)
                  {

                     if(pdialog->m_patha.has_element())
                     {

                        image_impact->set_image(___load_image(m_puserinteraction, pdialog->m_patha.first().c_str()));

                     }

                  };
                  pdialog->m_puserelement = m_puserinteraction;
                  pdialog->m_bSave = false;
                  pdialog->m_bMultiple = false;
                  pdialog->call();
                  //node()->pick_single_file(poswindow,
                    //          ,
                      //        , false);
                     
                  });
                  
                 // });

               b = ___new Button(tools, "Save");
               b->set_callback([this, image_impact]
               {

                  //auto pwindow = m_puserinteraction->window();
                  //auto poswindow = pwindow->get_os_data();
                  auto pdialog = node()->node_file_dialog();
                  pdialog->m_puserelement = m_puserinteraction;
                  pdialog->m_filedialogfilter.add({ "Portable Network Graphics", "*.png" });
                  pdialog->m_filedialogfilter.add({ "Text file", "*.txt" } );
                  pdialog->m_function = [this, image_impact](::file::file_dialog * pdialog)
                  {

                     if(pdialog->m_patha.has_element())
                     {

                        ___save_image(m_puserinteraction, pdialog->m_patha.first().c_str(), image_impact->image());

                     }

                  };
                  pdialog->m_bSave = true;
                  pdialog->m_bMultiple = false;
                  pdialog->call();
//                  node()->pick_single_file(
//                     poswindow,
//                     ,
//                     , true);

               });
      
               ___new Label(window, "Combo box", "sans-bold");

      ::string_array straComboItems{"Combo box item 1", "Combo box item 2", "Combo box item 3" };
               ___new ComboBox(window, straComboItems);
               ___new Label(window, "Check box", "sans-bold");
               CheckBox * cb = ___new CheckBox (window, "Flag 1",
                  [this](bool state) { 
                     string_stream str;
                     str << "Check box 1 state: " << state;
                     auto pmessagebox = __initialize_new::message_box(str.as_string());

                     pmessagebox->async();

                  }
               );
               cb->set_checked(true, ::e_source_initialize);
               cb = ___new CheckBox(window, "Flag 2",
                  [this](bool state) {
                     
                     string_stream str;
                     str << "Check box 2 state: " << state;
                     auto pmessagebox = __initialize_new::message_box(str.as_string());

                     pmessagebox->async();

                  }
               );
               ___new Label(window, "Progress bar", "sans-bold");
               m_progress = ___new ProgressBar(window);
      
               ___new Label(window, "Slider and text box", "sans-bold");
      
               Widget * panel = ___new Widget(window);
               panel->set_layout(___new BoxLayout(::e_orientation_horizontal,
                  ::nanoui::e_alignment_middle, 0, 20));
      
               Slider * slider = ___new Slider(panel);
               slider->set_value(0.5f, e_source_initialize);
               slider->set_fixed_width(80);
      
               TextBox * text_box = ___new TextBox(panel);
               text_box->set_fixed_size({ 60, 25 });
               text_box->set_value("50", e_source_initialize);
               text_box->set_unit("%");
               slider->set_callback([text_box](float value) {
                  text_box->set_value(::as_string((int)(value * 100)), e_source_user);
                  });
               slider->set_final_callback([&](float value) {
                  string str;
                  
                  str.formatf("Final slider value: %d", (int)(value * 100));
                  auto pmessagebox = message_box(str);
                  pmessagebox->async();
                  });
               text_box->set_fixed_size({ 60, 25 });
               text_box->set_font_size(20);
               text_box->set_alignment(TextBox::e_alignment_right);
      
               window = ___new Window(this, "Misc. widgets");
               window->set_position({ 425, 15 });
               window->set_layout(___new GroupLayout());
      
               TabWidget * tab_widget = window->add<TabWidget>();
      
               Widget * layer = ___new Widget(tab_widget);
               layer->set_layout(___new GroupLayout());
               tab_widget->append_tab("Color Wheel", layer);
      
               // Use overloaded variadic add to fill the tab widget with Different tabs.
               layer->add<Label>("Color wheel widget", "sans-bold");
               layer->add<ColorWheel>();
      
               layer = ___new Widget(tab_widget);
               layer->set_layout(___new GroupLayout());
               tab_widget->append_tab("Function Graph", layer);
      
               layer->add<Label>("Function graph widget", "sans-bold");
      
               Graph * graph = layer->add<Graph>("Some Function");
      
               graph->set_header("E = 2.35e-3");
               graph->set_footer("Iteration 89");
               auto & func = graph->values();
               func.resize(100);
               for (int i = 0; i < 100; ++i)
                  func[i] = 0.5f * (0.5f * std::sin(i / 10.f) +
                     0.5f * std::cos(i / 23.f) + 1);
      
               // Dummy tab used to represent the last tab button.
               auto plus_id = tab_widget->append_tab("+", ___new Widget(tab_widget));
      
               // A simple counter.
               int counter = 1;
               tab_widget->set_callback([tab_widget, this, counter, plus_id](::collection::index id) mutable {
                  if (id == plus_id) {
                     // When the "+" tab has been clicked, simply add a ___new tab.
                     ::string tab_name = "Dynamic " + ::as_string(counter);
                     Widget * layer_dyn = ___new Widget(tab_widget);
                     auto new_id = tab_widget->insert_tab(tab_widget->tab_count() - 1,
                        tab_name, layer_dyn);
                     layer_dyn->set_layout(___new GroupLayout());
                     layer_dyn->add<Label>("Function graph widget", "sans-bold");
                     Graph * graph_dyn = layer_dyn->add<Graph>("Dynamic function");
      
                     graph_dyn->set_header("E = 2.35e-3");
                     graph_dyn->set_footer("Iteration " + ::as_string(new_id * counter));
                     auto & func_dyn = graph_dyn->values();
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
               panel->set_layout(___new BoxLayout(::e_orientation_horizontal,
                  ::nanoui::e_alignment_middle, 0, 6));
      
               auto ib = panel->add<IntBox<int>>();
               ib->set_editable(true);
      
               b = panel->add<Button>("", e_font_awesome_forward);
               b->set_fixed_size({ 22, 22 });
               ib->set_fixed_height(22);
               b->set_callback([tab_widget, ib] {
                  int value = ib->value();
                  if (value >= 0 && value < tab_widget->tab_count())
                     tab_widget->set_selected_index(value);
                  });
      
               window = ___new Window(this, "Grid of small widgets");
               window->set_position({ 425, 300 });
               GridLayout * layout =
                  ___new GridLayout(::e_orientation_horizontal, 2,
                     e_alignment_middle, 15, 5);
               layout->set_col_alignment(
                  { e_alignment_maximum, e_alignment_fill });
               layout->set_spacing(0, 10);
               window->set_layout(layout);
      
               /* FP widget */ {
                  ___new Label(window, "Floating point :", "sans-bold");
                  text_box = ___new TextBox(window);
                  text_box->set_editable(true);
                  text_box->set_fixed_size({ 100, 20 });
                  text_box->set_value("50", e_source_initialize);
                  text_box->set_unit("GiB");
                  text_box->set_default_value("0.0");
                  text_box->set_font_size(16);
                  text_box->set_format("[-]?[0-9]*\\.?[0-9]+");
               }
      
               /* Positive integer widget */ {
                  ___new Label(window, "Positive integer :", "sans-bold");
                  auto int_box = ___new IntBox<int>(window);
                  int_box->set_editable(true);
                  int_box->set_fixed_size({ 100, 20 });
                  int_box->set_value(50, e_source_initialize);
                  int_box->set_unit("Mhz");
                  int_box->set_default_value("0");
                  int_box->set_font_size(16);
                  int_box->set_format("[1-9][0-9]*");
                  int_box->set_spinnable(true);
                  int_box->set_minimum_value(1);
                  int_box->set_value_increment(2);
               }
      
               /* Checkbox widget */ {
                  ___new Label(window, "Checkbox :", "sans-bold");
      
                  cb = ___new CheckBox(window, "Check me");
                  cb->set_font_size(16);
                  cb->set_checked(true, ::e_source_initialize);
               }
      
               ___new Label(window, "Combo box :", "sans-bold");

      ::string_array straComboItems2{ "Item 1", "Item 2", "Item 3"  };
               ComboBox * cobo =
                  ___new ComboBox(window, straComboItems2);
               cobo->set_font_size(16);
               cobo->set_fixed_size({ 100, 20 });
      
               ___new Label(window, "Color picker :", "sans-bold");
               auto cp = ___new ColorPicker(window, argb(255, 120, 0, 255));
               cp->set_fixed_size({ 100, 20 });
               cp->set_final_callback([this](const ::color::color & c) {
                  string_stream str;
                  str << "ColorPicker final callback: [" << c << "]";
                  auto pmessagebox = message_box(str.as_string());
                  pmessagebox->async();
                  });
               // setup a fast callback for the color picker widget on a ___new window
               // for demonstrative purposes
               window = ___new Window(this, "Color Picker Fast Callback");
               layout = ___new GridLayout(::e_orientation_horizontal, 2,
                  e_alignment_middle, 15, 5);
               layout->set_col_alignment(
                  { e_alignment_maximum, e_alignment_fill });
               layout->set_spacing(0, 10);
               window->set_layout(layout);
               window->set_position({ 425, 500 });
               ___new Label(window, "Combined: ");
               b = ___new Button(window, "ColorWheel", e_font_awesome_infinity);
               ___new Label(window, "Red: ");
               auto red_int_box = ___new IntBox<int>(window);
               red_int_box->set_editable(false);
               ___new Label(window, "Green: ");
               auto green_int_box = ___new IntBox<int>(window);
               green_int_box->set_editable(false);
               ___new Label(window, "Blue: ");
               auto blue_int_box = ___new IntBox<int>(window);
               blue_int_box->set_editable(false);
               ___new Label(window, "Alpha: ");
               auto alpha_int_box = ___new IntBox<int>(window);
      
               cp->set_callback([b, red_int_box, blue_int_box, green_int_box, alpha_int_box](const ::color::color & c) {
                  b->set_background_color(c);
                  b->set_text_color(c.contrasting_color());
                  int red = (int) c.byte_red();
                  red_int_box->set_value(red, e_source_user);
                  int green = (int)c.byte_green();
                  green_int_box->set_value(green, e_source_user);
                  int blue = (int)c.byte_blue();
                  blue_int_box->set_value(blue, e_source_user);
                  int alpha = (int)c.byte_opacity();
                  alpha_int_box->set_value(alpha, e_source_user);
                  });
      

               window = ___new Window(this, "Navigation");
               window->set_position({ 15, 680 });
               window->set_layout(___new GroupLayout());



               b = ___new Button(window, "Next Example");
               b->set_callback(
                  [this] 
                  { 
                     
                     //auto pmessagebox = __initialize_new ::message_box(nullptr, "Pushed Plain Button!");

//pmessagebox->sync();/* std::cout << "pushed!" << std::endl; */

                     m_pmainwindow->next_application();


                  });
               b = ___new Button(window, "Previous Example");
               b->set_callback(
                  [this]
                  {

                     //auto pmessagebox = __initialize_new ::message_box(nullptr, "Pushed Plain Button!");

//pmessagebox->sync();/* std::cout << "pushed!" << std::endl; */

                     m_pmainwindow->previous_application();


                  });
               b->set_tooltip("short tooltip");

   }

   //
   //void start(ExampleApplication *& papplication, ::user::interaction * puserinteraction)
   //{

   //   papplication = ___new ExampleApplication();

   //   papplication->_nanoui_to_user(puserinteraction);

   //}


   //void finish(ExampleApplication * & papplication)
   //{

   //   ::acme::del(papplication);

   //}

   void ExampleApplication1::draw_contents(::nano2d::context * pcontext)
   {

      Screen::draw_contents(pcontext);


      int iSize = minimum(m_size.cx(), m_size.cy());

      iSize = iSize / 2;

      int centerX = m_size.cx() / 2;

      int centerY = m_size.cy() / 2;

      ::nano2d::guard guard(pcontext);

      pcontext->fill_color(rgba(1.0f, 1.0f, 1.0f, 0.5f));

      auto angle = fmod(double_second(), 2.0 * π);

      pcontext->translate((float)centerX, (float)centerY);
      pcontext->rotate((float) angle);

      pcontext->begin_path();
      pcontext->rectangle(-iSize / 2.f, -iSize / 2.f, (float)iSize, (float)iSize);
      pcontext->fill();


      //nvgRestore(ctx);


   }


} // namespace simple_application



