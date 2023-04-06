#include "../helper/TupleArr.h"
#include "../helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void stableImprovedBidirectionalSelectionSort(TupleArr *tupleArr) {
  Tuple* arr = tupleArr->arr;
  int size = tupleArr->size;

  int min_q[size];
  int max_q[size];
  Tuple *min_tuples = malloc(size * sizeof(*min_tuples));
  Tuple *max_tuples = malloc(size * sizeof(*max_tuples));

  int i = 0;
  int j = size - 1;
  while (i < j) {
    int min = arr[i].n;
    int max = arr[i].n;

    unsigned int min_size = 0;
    unsigned int max_size = 0;
    for (int k = i; k < j + 1; k++) {

      // Rest min_q, min_tuples and min_size
      if (arr[k].n == min) {
        min_q[min_size] = k;
        min_tuples[min_size] = arr[k];
        min_size++;
      }

      // Add to min_q, min_tuples and min_size
      if (arr[k].n < min) {
        min = arr[k].n;
        min_q[0] = k;
        min_tuples[0] = arr[k];
        min_size = 1;
      }

      // Reset max_q, max_tuples and max_size
      if (arr[k].n == max) {
        max_q[max_size] = k;
        max_tuples[max_size] = arr[k];
        max_size++;
      }

      // Add to max_q, max_tuples and max_size
      if (arr[k].n > max) {
        max = arr[k].n;
        max_q[0] = k;
        max_tuples[0] = arr[k];
        max_size = 1;
      }
    }

    // Already sorted
    if (min_size == j - i + 1) {
      break;
    }

    int offset = 0;
    int m = min_size - 1;
    int n = max_size - 1;
    for (int k = min_q[m]; k > i + min_size - 1; k--) {
      while (arr[k - offset].n == min) {
        offset++;
      }

      while (max_q[n] > k - offset) {
        // Bandaid fix
        if (n == 0) {
          break;
        }
        n--;
      }

      if (max_q[n] == k - offset) {
        max_q[n] += offset;
      }

      arr[k] = arr[k - offset];
    }

    for (int k = 0; k < min_size; k++) {
      arr[i] = min_tuples[k];
      i++;
    }

    offset = 0;
    n = 0;
    for (int k = max_q[n]; k < j - max_size + 1; k++) {
      while (arr[k + offset].n == max) {
        offset++;
      }
      arr[k] = arr[k + offset];
    }


    for (int k = max_size - 1; k >= 0; k--, j--) {
      arr[j] = max_tuples[k];
    }
  }

  free(min_tuples);
  free(max_tuples);
}
