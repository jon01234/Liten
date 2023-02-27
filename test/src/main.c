#define LIT_PLATFORM_LINUX
#include <Liten/ui/window.h>
#include <Liten/ui/renderer.h>
#include <Liten/ui/shaders.h>
#include <Liten/typedefs.h>
#include <GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main (int argc, char **argv)
{
    lWindow *window = Lit_Window("Liten", 1280, 720);
    lRenderer *renderer = Lit_Renderer(window);

    float vertecies[] = {
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
    };

    lBasicShader *shader = Lit_BasicShader(vertexShaderSource, fragmentShaderSource);

    luint vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while(window->running)
    {
        Lit_RenderClear(renderer, 15, 35, 45, 255);

        Lit_UseBasicShader(shader);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        Lit_RenderUpdate(renderer);
        Lit_WindowUpdate(window);
    }

    Lit_DeleteBasicShader(shader);
    
    return 0;
}
