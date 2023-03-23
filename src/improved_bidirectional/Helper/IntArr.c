#include "IntArr.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

IntArr *genRandomIntArr(int size, int max);
void printIntArr(int *arr, int size);

IntArr *genRandomIntArr(int size, int max) {
  srand(time(NULL));

  IntArr *int_arr = malloc(sizeof(*int_arr));
  int_arr->arr = malloc(size * sizeof(int_arr->arr));
  for (int i = 0; i < size; i++) {
    int_arr->arr[i] = rand() % (max + 1);
  }
  int_arr->size = size;
  return int_arr;
}

void printIntArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
