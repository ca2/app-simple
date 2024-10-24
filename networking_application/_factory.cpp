#include "framework.h"
#include "application.h"


__FACTORY_EXPORT void app_simple_networking_application_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::app_simple_networking_application::application, ::platform::application >();

}




