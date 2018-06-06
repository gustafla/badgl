# Doing OpenGL the easy way

Most OpenGL tutorials tell you to load OpenGL functions either by using some
form of *GetProcAddress (even SDL2 provides one of those, use it if you want
proper multi-platform support without GLEW), or by using some library such as
GLEW or GLFW.

On most UNIXlike systems, the functions are actually defined just fine, ready
for linking, in the libGL.so* library. Even on NVidia. This means that you can
straight up use all functions your context supports, just by adding
`pkg-config --libs gl` to your LDLIBS!

Headers you can get by \#including GL/gl.h, and GL/glext.h after that, with
-DGL\_GLEXT\_PROTOTYPES in your CFLAGS.

At least with Mesa, doing OpenGL this way can even support ES contexts just
fine! (But I think you should use GLES 2.0 headers and libs, when using ES 2.0)
