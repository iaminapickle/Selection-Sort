#include "TupleArr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

TupleArr *initTupleArr(int size) {
  TupleArr *tupleArr = malloc(sizeof(*tupleArr));
  tupleArr->size = size;
  tupleArr->arr = malloc(size * sizeof(*(tupleArr->arr)));

  return tupleArr;
}

TupleArr *genRandomTupleArr(int size, int max, int seed) {
  TupleArr *tupleArr = initTupleArr(size);

  randomiseTuples(tupleArr, size, max, seed);
  return tupleArr;
}

void randomiseTuples(TupleArr *tupleArr, int size, int max, int seed) {
  if (seed == -1) {
    srand(time(NULL));
  } else {
    srand(seed);
  }

  int count[max + 1];
  memset(count, 0, sizeof(count));
  for (int i = 0; i < size; i++) {
    int num = rand() % (max + 1);
    tupleArr->arr[i].n = num;
    tupleArr->arr[i].c = count[num] + 97;
    count[num]++;
  }
}

TupleArr *manualTupleArr(void) {
  int n[] = {10, 10, 4, 3, 2};
  char c[] = {'a', 'b', 'a', 'a', 'a'};

  TupleArr *tupleArr = malloc(sizeof(*tupleArr));
  tupleArr->arr = malloc(strlen(c) * sizeof(*(tupleArr->arr)));
  tupleArr->size = strlen(c);

  for (int i = 0; i < strlen(c); i++) {
    tupleArr->arr[i].n = n[i];
    tupleArr->arr[i].c = c[i];
  }
  return tupleArr;
}

int findMinIndex(Tuple *tuple_arr, int start, int end) {
  int min = tuple_arr[start].n;
  int index = start;
  for (int i = start; i < end; i++) {
    if (tuple_arr[i].n < min) {
      min = tuple_arr[i].n;
      index = i;
    }
  }
  return index;
}

void findMinMaxIndex(Tuple *tuple_arr, int start, int end, int *minIndex, int *maxIndex) {
  int min = tuple_arr[start].n;
  int max = tuple_arr[start].n;
  *minIndex = start;
  *maxIndex = start;
  for (int i = start; i < end + 1; i++) {
    if (tuple_arr[i].n < min) {
      min = tuple_arr[i].n;
      *minIndex = i;
    }

    if (tuple_arr[i].n >= max) {
      max = tuple_arr[i].n;
      *maxIndex = i;
    }
  }
  return;
}

void moveAcrossRight(Tuple *tuple_arr, int left, int right) {
  for (int i = right; i > left; i--) {
    tuple_arr[i] = tuple_arr[i - 1];
  }
}

void moveAcrossLeft(Tuple *tuple_arr, int left, int right) {
  for (int i = left; i < right; i++) {
    tuple_arr[i] = tuple_arr[i + 1];
  }
}

void printTupleArr(Tuple *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("(%d, %c)", arr[i].n, arr[i].c);
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

void freeTupleArr(TupleArr* tupleArr) {
  free(tupleArr->arr);
  free(tupleArr);
}
