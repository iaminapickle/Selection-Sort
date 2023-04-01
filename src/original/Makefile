CC = gcc
CFLAGS = -c -Wall
VPATH = ../helper

all: unstable_selection_sort.o stable_selection_sort.o

unstable_selection_sort.o: unstable_selection_sort.c
	$(CC) $(CFLAGS) $^

stable_selection_sort.o: stable_selection_sort.c
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
