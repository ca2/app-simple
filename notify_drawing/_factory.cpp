// Created by camilo on 2022-05-30 08:29 PM <3ThomasBorregaardS�rensen!!
#include "framework.h"
#if !BROAD_PRECOMPILED_HEADER
#include "_library.h"
#endif


__FACTORY_EXPORT void app_simple_notify_drawing_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::app_simple_notify_drawing::application, ::app >();

}
