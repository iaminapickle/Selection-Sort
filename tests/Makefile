CC = gcc
CFLAGS = -c -ggdb -Wall
VPATH = ../src/helper ../src/original ../src/improved_bidirectional ../src/improved ../src/bidirectional

all:
	+$(MAKE) -C ../src/helper
	+$(MAKE) -C ../src/original
	+$(MAKE) -C ../src/bidirectional
	+$(MAKE) -C ../src/improved
	+$(MAKE) -C ../src/improved_bidirectional
	+$(MAKE) tests

tests: tests.c Tuple.o TupleArr.o Algorithm.o AlgorithmArr.o \
			 stable_selection_sort.o unstable_selection_sort.o \
			 stable_bidirectional_selection_sort.o unstable_bidirectional_selection_sort.o \
			 stable_improved_selection_sort.o unstable_improved_selection_sort.o \
			 stable_improved_bidirectional_selection_sort.o unstable_improved_bidirectional_selection_sort.o
		$(CC) -g $^ -o tests

Algorithm.o: Algorithm.c
		$(CC) $(CFLAGS) $^

AlgorithmArr.o: AlgorithmArr.c
	 	$(CC) $(CFLAGS) $^

clean:
	+$(MAKE) -C ../src/helper clean
	+$(MAKE) -C ../src/original clean
	+$(MAKE) -C ../src/bidirectional clean
	+$(MAKE) -C ../src/improved clean
	+$(MAKE) -C ../src/improved_bidirectional clean
	rm *.o
	rm tests
