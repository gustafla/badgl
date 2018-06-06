TARGET=badgltest

CC=gcc
PKGS=sdl2 gl
CFLAGS=$(shell pkg-config --cflags $(PKGS)) -DGL_GLEXT_PROTOTYPES
LDLIBS=$(shell pkg-config --libs $(PKGS))

SOURCES=badgltest.c
OBJS=$(patsubst %.c,%.o,$(SOURCES))

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(TARGET)
	find . -name "*.o" -delete
