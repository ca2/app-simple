#include "framework.h"


__FACTORY_EXPORT void app_simple_nanogui_example_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::app_simple_nanogui_example::application, ::app >();

}




