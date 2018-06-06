TARGET=badgltest

CC=gcc
CFLAGS=$(shell pkg-config --cflags sdl2 gl) -DGL_GLEXT_PROTOTYPES
LFLAGS=$(shell pkg-config --libs sdl2 gl)

SOURCES=badgltest.c
OBJS=$(patsubst %.c,%.o,$(SOURCES))

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(TARGET)
	find . -name "*.o" -delete
