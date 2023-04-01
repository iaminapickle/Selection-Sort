#include "../helper/TupleArr.h"
#include "../helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void stableImprovedSelectionSort(TupleArr *tupleArr) {
  Tuple *arr = tupleArr->arr;
  int size = tupleArr->size;

  int min_q[size];
  Tuple *min_tuples = malloc(size * sizeof(*min_tuples));
  int i = 0;
  while (i < size - 1) {
    int min = arr[i].n;
    unsigned int min_size = 0;

    for (int k = i; k < size; k++) {

      // Reset min_size, min_tuples and min_q
      if (arr[k].n == min) {
        min_q[min_size] = k;
        min_tuples[min_size] = arr[k];
        min_size++;
      }

      // Add to min_tuples and min_q
      if (arr[k].n < min) {
        min = arr[k].n;
        min_q[0] = k;
        min_tuples[0] = arr[k];
        min_size = 1;
      }
    }

    // If the size of the minimum is the rest of the unsorted section
    // then it is already sorted
    if (min_size == size - i) {
      break;
    }
    
    int offset = 0;
    int m = min_size - 1;
    for (int k = min_q[m]; k > i + min_size - 1; k--) {
      while (arr[k - offset].n == min) {
        offset++;
      }
      arr[k] = arr[k - offset];
    }

    for (int k = 0; k < min_size; k++) {
      arr[i] = min_tuples[k];
      i++;
    }
  }
  free(min_tuples);
}
