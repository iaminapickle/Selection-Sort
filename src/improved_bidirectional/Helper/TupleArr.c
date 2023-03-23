#include "TupleArr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

TupleArr *genRandomTupleArr(int size, int max) {
  srand(time(NULL));
  TupleArr *tuple_arr = malloc(sizeof(*tuple_arr));
  tuple_arr->arr = malloc(size * sizeof(tuple_arr->arr));
  int *count = calloc(max + 1, sizeof(*count));
  for (int i = 0; i < size; i++) {
    int num = rand() % (max + 1);
    tuple_arr->arr[i].n = num;
    tuple_arr->arr[i].c = count[num] + 97;
    count[num]++;
  }
  tuple_arr->size = size;
  free(count);
  return tuple_arr;
}

TupleArr *manualTupleArr(void) {
  int n[] = {10, 10, 4, 3, 2};
  char c[] = {'a', 'b', 'a', 'a', 'a'};

  TupleArr *tuple_arr = malloc(sizeof(*tuple_arr));
  tuple_arr->arr = malloc(strlen(c) * sizeof(*tuple_arr->arr));
  tuple_arr->size = strlen(c);

  for (int i = 0; i < strlen(c); i++) {
    tuple_arr->arr[i].n = n[i];
    tuple_arr->arr[i].c = c[i];
  }
  return tuple_arr;
}

int findMinIndex(Tuple *tuple_arr, int start, int end) {
  int min = tuple_arr[start].n;
  int index = start;
  for (int i = start; i <= end; i++) {
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
  for (int i = start; i <= end; i++) {
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
