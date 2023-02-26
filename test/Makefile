CC = gcc

exec = bin/test
source = $(shell find src -name *.c)
objects = $(source:.c=.o)
lflags = -Lbin -lliten -Wl,-rpath bin 
cflags = -I../Liten/include

bear:
	bear -- make $(exec)

$(exec): $(objects)
	$(CC) $(lflags) -o $@ $^

%.o: %.c
	$(CC) $(cflags) -c -o $@ $^

mkdirs:
	-mkdir -p bin

clean:
	rip $(objects)
	rip $(exec) 
