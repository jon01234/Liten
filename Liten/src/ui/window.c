#include "../../include/Liten/ui/window.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>


// ((struct __lwindow_priv__ *)w->lwinpriv)->window 
// use that to access glfw window
// this is to make it harder for client to access the glfw window

lWindow *Lit_Window(char *title, int width, int height)
{
    struct __lwindow_priv__ *p = calloc(1, sizeof(struct __lwindow_priv__));
    lWindow *w = calloc(1, sizeof(lWindow));

    w->title = title;
    w->width = width;
    w->height = height;
    w->running = 1;
    w->lwinpriv = p;

    if (!glfwInit())
        return 0x00;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    ((struct __lwindow_priv__ *)w->lwinpriv)->window = glfwCreateWindow(w->width, w->height, w->title, NULL, NULL);

    if (((struct __lwindow_priv__ *)w->lwinpriv)->window == 0x00)
    {
        glfwTerminate();
        return 0x00;
    }

    glfwMakeContextCurrent(((struct __lwindow_priv__ *)w->lwinpriv)->window);

    // initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Lit_DestroyWindow(w);
        return 0x00;
    }

    glViewport(0, 0, w->width, w->height);

    return w;
}

void Lit_WindowUpdate(lWindow *win)
{
    // update the running variable
    win->running = !glfwWindowShouldClose(((struct __lwindow_priv__ *)win->lwinpriv)->window);

    glfwPollEvents();
}

void Lit_DestroyWindow(lWindow *win)
{
    glfwTerminate();
    glfwDestroyWindow(((struct __lwindow_priv__ *)win->lwinpriv)->window);

    // set the window to null
    win = 0x00; 
}

