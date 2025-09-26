CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# default target
all: list.exe

# compile object file for list
iter.o: src/iter.c include/iter.h include/list.h
	$(CC) $(CFLAGS) -c src/iter.c -o iter.o

# build test executable
list.o: src/list.c include/list.h 
	$(CC) $(CFLAGS) -c src/list.c -o list.o

test.o: tests/test.c
	$(CC) $(CFLAGS) -c tests/test.c -o test.o

# link object files into executable
list.exe: iter.o list.o test.o
	$(CC) iter.o list.o test.o -o list.exe
	@del /Q iter.o list.o test.o 2>nul || true

# clean up build artifacts
clean:
	del /Q *.o list.exe


