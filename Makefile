CC      = gcc
CFLAGS  = -Wall -g -std=c99 -Werror -pedantic

.SUFFIXES: .c .o

.PHONY: all clean

all: main

main: main.o system_functions.o

clean:
	rm -f $(wildcard *.o)
	rm -f main
