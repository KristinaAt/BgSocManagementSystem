CC      = gcc
CFLAGS  = -Wall -g -std=c99 -Werror -pedantic

.SUFFIXES: .c .o

.PHONY: all clean

all: main

main: main.o helper_functions.o add_member.o delete_record.o list_records.o menu.o modify_record.o

clean:
	rm -f $(wildcard *.o)
	rm -f main
