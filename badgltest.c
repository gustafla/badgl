#include <stdio.h>

#include <SDL.h>
#include <GL/gl.h>
// Compile with -DGL_GLEXT_PROTOTYPES
#include <GL/glext.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window *w = SDL_CreateWindow("test", 0, 0, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(w);

    glClearColor(1., 0., 0., 1.);

    glCreateShader(GL_VERTEX_SHADER);

    SDL_Event e;
    while(1) {
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(w);

        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            break;
        } else if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_q) {
                break;
            }
        }
    }

    return 0;
}
