
#define PLAT_X11
#ifdef PLAT_X11
#include "../platform/engine-x11.hpp"
#endif

int main()
{
    Engine *engine = new Engine();

    engine->initialize("Hydrogen Engine");

    return 0;
}