CC      = gcc
CFLAGS  = -Wall -g -std=c99 -Werror -pedantic

.SUFFIXES: .c .o

.PHONY: all clean

all: main add_member delete_record list_records menu modify_record

main: main.o helper_functions.o main_functions/add_member.o main_functions/delete_record.o main_functions/list_records.o main_functions/menu.o main_functions/modify_record.o

add_member: add_member.o helper_functions.o

delete_record: delete_record.o helper_functions.o

list_records: list_records.o helper_functions.o

modify_record: modify_record.o helper_functions.o

menu: menu.o helper_functions.o

clean:
	rm -f $(wildcard *.o)
	rm -f main
	rm -f add_member
	rm -f delete_record
	rm -f list_records
	rm -f menu
	rm -f modify_record