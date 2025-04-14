#include "framework.h"
#include "application.h"


__FACTORY_EXPORT void app_simple_nfs_desktop_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::app_simple_nfs_desktop::application, ::platform::application >();

}




