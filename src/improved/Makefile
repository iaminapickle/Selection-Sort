CC = gcc
CFLAGS = -c -Wall
VPATH = ../../../Helper

all: unstable_improved_selection_sort.o stable_improved_selection_sort.o

unstable_improved_selection_sort.o: unstable_improved_selection_sort.c Tuple.h TupleArr.h
	$(CC) $(CFLAGS) $^

stable_improved_selection_sort.o: stable_improved_selection_sort.c Tuple.h TupleArr.h
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
