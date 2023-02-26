CC = gcc

lib = bin/libliten.so
source = $(shell find src -name *.c)
objects = $(source:.c=.o)
lflags = -lglfw -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp  
cflags = -fPIC -DLIT_PLATFORM_LINUX -DLIT_BUILD_DLL

bear:
	bear -- make $(lib)

$(lib): $(objects)
	$(CC) $(lflags) -shared -o $@ $^
	cp $(lib) ../test/bin

%.o: %.c
	$(CC) $(cflags) -c -o $@ $^

mkdirs:
	-mkdir -p bin


clean:
	rip $(objects)
	rip $(lib)
