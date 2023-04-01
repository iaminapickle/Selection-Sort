CC = gcc
CFLAGS = -c -Wall
VPATH = ../helper

all: unstable_bidirectional_selection_sort.o stable_bidirectional_selection_sort.o

unstable_bidirectional_selection_sort.o: unstable_bidirectional_selection_sort.c
	$(CC) $(CFLAGS) $^

stable_bidirectional_selection_sort.o: stable_bidirectional_selection_sort.c
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
