#ifndef LIT_SHADERS_H
#define LIT_SHADERS_H

#include "../../core.h"
#include "../typedefs.h"

typedef struct lbasicshader
{
    luint program; 
} lBasicShader;

LIT_API lBasicShader *Lit_BasicShader(const char *vertsrc, const char *fragsrc);
LIT_API void Lit_UseBasicShader(lBasicShader *shader);
LIT_API void Lit_DeleteBasicShader(lBasicShader *shader);

#endif // LIT_SHADERS_H
