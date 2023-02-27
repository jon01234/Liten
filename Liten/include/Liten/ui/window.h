#ifndef LIT_WINDOW_H
#define LIT_WINDOW_H

#include "../../core.h"
#include "../../glad/glad.h"
#include <GLFW/glfw3.h>

typedef struct lwindow
{
    char *title;
    int width, height;
    unsigned running:1; // 1 bit value (1 or 0) 

    // to make it hard to access the glfw window
    void *lwinpriv;
} lWindow;

struct __lwindow_priv__
{
    GLFWwindow *window;
};

LIT_API lWindow *Lit_Window(char *title, int width, int height);
LIT_API void Lit_WindowUpdate(lWindow *win);
LIT_API void Lit_DestroyWindow(lWindow *win);

#endif // !LIT_WINDOW_H
