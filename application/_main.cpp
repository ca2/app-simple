#include "framework.h"
#define APPLICATION app_simple_application
#define __APP_ID "app-simple/application"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "([a-z0-9_]+)_factory.inl"
#endif
#include "acme/application.h"
