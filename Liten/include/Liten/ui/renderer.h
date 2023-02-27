#ifndef LIT_RENDERER_H
#define LIT_RENDERER_H

#include "../../core.h"
#include "window.h"

typedef struct lrenderer
{
    lWindow *window;

    // same idea as window
    // private members
    void *lrenpriv;
} lRenderer;

struct __lrender_priv__
{
    
};

LIT_API lRenderer *Lit_Renderer(lWindow *window);

LIT_API void Lit_RenderUpdate(lRenderer *renderer);
// TODO: Create vec4
LIT_API void Lit_RenderClear(lRenderer *renderer, float r, float g, float b, float a);

LIT_API void Lit_DestroyRenderer(lRenderer *renderer);

#endif // LIT_RENDERER_H
