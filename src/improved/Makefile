CC = gcc
CFLAGS = -c -Wall
VPATH = ../../../Helper

all: unstable_improved_selection_sort.o stable_improved_selection_sort.o

unstable_improved_selection_sort.o: unstable_improved_selection_sort.c
	$(CC) $(CFLAGS) $^

stable_improved_selection_sort.o: stable_improved_selection_sort.c 
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
