# Doing OpenGL the easy way

Most OpenGL tutorials tell you to load OpenGL functions either by using some
form of *GetProcAddress (even SDL2 provides one of those, use it if you want
proper multi-platform support without GLEW), or by using some library such as
GLEW or GLFW.

On most UNIXlike systems, basic dynamic linking with the libGL.so* library
works just fine. Even with NVidia. This means that you can straight up use all
functions your driver supports, just by adding \`pkg-config --libs gl\` to your
LDLIBS.

Headers you can get by `#include GL/gl.h`, and `GL/glext.h`, with
`-DGL_GLEXT_PROTOTYPES` in your CFLAGS.

If you want to use OpenGL ES, use it's headers (`GLES2/gl2.h`) and libraries
(`-lGLESv2`) instead, and set SDL GL attribute `SDL_GL_CONTEXT_PROFILE_MASK` to
`SDL_GL_CONTEXT_PROFILE_ES`. Or better yet, use `pkg-config (--libs/--cflags)
glesv2`.
