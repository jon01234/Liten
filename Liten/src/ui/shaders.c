#include "../../include/Liten/ui/shaders.h"
#include <stdio.h>
#include <stdlib.h>

#include "../../include/glad/glad.h"
#include <GLFW/glfw3.h>

lBasicShader *Lit_BasicShader(const char *vertsrc, const char *fragsrc)
{
    lBasicShader *shader = calloc(1, sizeof(lBasicShader));

    int compileStatus;

    luint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertsrc, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == 0)
    {
        int errlength;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &errlength);

        char errorLog[errlength];

        glGetShaderInfoLog(vertexShader, errlength, &errlength, &errorLog[0]);

        printf("Couldn't compile vertex shader\n Error: %s\n", errorLog);

        glDeleteShader(vertexShader);
        
        return NULL;
    }
    
    luint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragsrc, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == 0)
    {
        int errlength;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &errlength);

        char errorLog[errlength];

        glGetShaderInfoLog(fragmentShader, errlength, &errlength, &errorLog[0]);

        printf("Couldn't compile fragment shader\n Error: %s\n", errorLog);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        
        return NULL;
    }

    shader->program = glCreateProgram();
    glAttachShader(shader->program, vertexShader);
    glAttachShader(shader->program, fragmentShader);
    glLinkProgram(shader->program);

    glGetProgramiv(shader->program, GL_LINK_STATUS, &compileStatus);
    if (compileStatus == 0)
    {
        int errlength;
        glGetProgramiv(shader->program, GL_INFO_LOG_LENGTH, &errlength);

        char errorLog[errlength];
        glGetProgramInfoLog(shader->program, errlength, &errlength, &errorLog[0]);

        printf("Couldn't linke shader program\n Error: %s\n", errorLog);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return NULL;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shader;
}

void Lit_UseBasicShader(lBasicShader *shader)
{
    glUseProgram(shader->program);
}

void Lit_DeleteBasicShader(lBasicShader *shader)
{
    glDeleteProgram(shader->program);
    shader = 0x00;
}


