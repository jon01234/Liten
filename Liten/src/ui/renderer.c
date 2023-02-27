#include "../../include/Liten/ui/renderer.h"

#include "../../include/glad/glad.h"
#include <stdlib.h>
#include <GLFW/glfw3.h>

lRenderer *Lit_Renderer(lWindow *window)
{
    struct __lrender_priv__ *p = calloc(1, sizeof(struct __lwindow_priv__));
    lRenderer *r = calloc(1, sizeof(lRenderer));

    r->window = window;
    r->lrenpriv = p;

    return r;
}

void Lit_RenderUpdate(lRenderer *renderer)
{
    glfwSwapBuffers(((struct __lwindow_priv__ *)renderer->window->lwinpriv)->window);
}

void Lit_RenderClear(lRenderer *renderer, float r, float g, float b, float a)
{
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Lit_DestroyRenderer(lRenderer *renderer)
{
    // set renderer to null
    renderer = 0x00;
}


