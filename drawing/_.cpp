#include "framework.h"
#define SYSTEM base
#define APPLICATION simple_drawing
#define __APP_ID "app-simple/drawing"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "([a-z0-9_]+)_factory.inl"
#endif
#include "aura/application.h"



