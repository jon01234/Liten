#define LIT_PLATFORM_LINUX
#include <Liten/ui/window.h>

int main(int argc, char **argv)
{
    lWindow *window = Lit_Window("Window", 1280, 720);

    while (window->running)
    {
        Lit_ClearWindow(window, 15, 35, 40, 255);
        Lit_UpdateWindow(window);
    }

    Lit_DestroyWindow(window);

    return 0;
}
