#include "../../../Helper/TupleArr.h"
#include "../../../Helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void unstableImprovedSelectionSort(TupleArr *tupleArr) {
  Tuple *arr = tupleArr->arr;
  int size = tupleArr->size;

  int *queue = malloc(size * sizeof(*queue));
  int i = 0;
  while (i < size - 1) {
    int min = arr[i].n;
    int q_head = 0;
    for (int j = i; j < size; j++) {
      if (arr[j].n == min) {
        queue[q_head] = j;
        q_head++;
      }
      if (arr[j].n < min) {
        min = arr[j].n;
        queue[0] = j;
        q_head = 1;
      }
    }

    for (int k = 0; k < q_head; k++, i++) {
      swapTuple(&arr[queue[k]], &arr[i]);
    }
  }
}
