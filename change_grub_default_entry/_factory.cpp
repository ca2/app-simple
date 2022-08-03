#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif


__FACTORY_EXPORT void app_simple_change_grub_default_entry_factory(::factory::factory * pfactory)
{

   pfactory->add_factory_item<::app_simple_change_grub_default_entry::application, ::app >();

}



