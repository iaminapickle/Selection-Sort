#include "../../../Helper/TupleArr.h"
#include "../../../Helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void unstableImprovedBidirectionalSelectionSort(TupleArr *tupleArr) {
  Tuple* arr = tupleArr->arr;
  int size = tupleArr->size;

  int *queue = malloc(size * sizeof(*queue));
  int i = 0;
  int j = size - 1;
  while (i < j) {
    int min = arr[i].n;
    int max = arr[i].n;
    int q_head = 0;
    int q_tail = size - 1;
    for (int k = i; k < j + 1; k++) {
      if (arr[k].n == min) {
        queue[q_head] = k;
        q_head++;
      }
      if (arr[k].n < min) {
        min = arr[k].n;
        queue[0] = k;
        q_head = 1;
      }
      if (arr[k].n == max && min != max) {
        queue[q_tail] = k;
        q_tail--;
      }
      if (arr[k].n > max) {
        max = arr[k].n;
        queue[size - 1] = k;
        q_tail = size - 2;
      }
    }

    for (int l = 0; l < q_head; l++, i++) {
      swapTuple(&arr[queue[l]], &arr[i]);
      for (int m = q_tail + 1; m < size; m++) {
        if (queue[m] == i) {
          queue[m] = queue[l];
        }
      }
    }

    for (int l = q_tail + 1; l < size; l++, j--) {
      swapTuple(&arr[queue[l]], &arr[j]);
    }
  }
}
