#include "framework.h"


__FACTORY_EXPORT void app_simple_application_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::app_simple_application::application, ::app >();

}



