#include "../src/helper/TupleArr.h"
#include "../src/original/stable_selection_sort.h"
#include "../src/original/unstable_selection_sort.h"
#include "../src/bidirectional/stable_bidirectional_selection_sort.h"
#include "../src/bidirectional/unstable_bidirectional_selection_sort.h"
#include "../src/improved/stable_improved_selection_sort.h"
#include "../src/improved/unstable_improved_selection_sort.h"
#include "../src/improved_bidirectional/stable_improved_bidirectional_selection_sort.h"
#include "../src/improved_bidirectional/unstable_improved_bidirectional_selection_sort.h"
#include "AlgorithmArr.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  AlgorithmArr *algos = createEmptyAlgorithmArr();
  addAlgorithm(algos, &stableSelectionSort, true, "Stable Selection Sort");
  addAlgorithm(algos, &unstableSelectionSort, false, "Unstable Selection Sort");
  addAlgorithm(algos, &stableBidirectionalSelectionSort, true, "Stable Bidirectional Selection Sort");
  addAlgorithm(algos, &unstableBidirectionalSelectionSort, false, "Unstable Bidirectional Selection Sort");
  addAlgorithm(algos, &stableImprovedSelectionSort, true, "Stable Improved Selection Sort");
  addAlgorithm(algos, &unstableImprovedSelectionSort, false, "Unstable Improved Selection Sort");
  addAlgorithm(algos, &stableImprovedBidirectionalSelectionSort, true, "Stable Improved Bidirectional Selection Sort");
  addAlgorithm(algos, &unstableImprovedBidirectionalSelectionSort, false, "Unstable Improved Bidirectional Selection Sort");

  runTests(algos);
  freeAlgorithmArr(algos);
  return 0;
}
