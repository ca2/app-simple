#include "framework.h"


__FACTORY_EXPORT void app_simple_shortcut_factory(::factory::factory * pfactory)
{

   pfactory->add_factory_item<::app_simple_shortcut::application, ::app >();

}



