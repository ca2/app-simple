#include "framework.h"
#include "application.h"


__FACTORY_EXPORT void app_simple_http_file_server_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::app_simple_http_file_server::application, ::platform::application >();

}




