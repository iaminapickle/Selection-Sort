CC = gcc
CFLAGS = -c -Wall
VPATH = ../helper

all: unstable_improved_bidirectional_selection_sort.o stable_improved_bidirectional_selection_sort.o

unstable_improved_bidirectional_selection_sort.o: unstable_improved_bidirectional_selection_sort.c
	$(CC) $(CFLAGS) $^

stable_improved_bidirectional_selection_sort.o: stable_improved_bidirectional_selection_sort.c
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
