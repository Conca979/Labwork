// In this problem, we would like to implement a variation of the Insertion Sort algorithm. The algorithm differs from a bubble sort in that it sorts in both directions on each pass through the list. The algorithm is illustrated in the following figure:

// - For the first step, we perform insertion sort from the index 1 to n (n is the
// number of elements in the array).
// - In the next pass, we perform a reserved bubble sort from the index n to 1.
// - The process is repeated until all the array is sorted.

// Propose a pseudo-code to complete the Insertion Sort algorithm. Implement and test this algorithm in C/C++. Analyze and compute the complexity of this algorithm in the best, average and worst scenarios

#include <stdio.h>

int main() {
  int arr[] = {17,13,12,100,8,15,2,16,14,1,3,4,19,20,10,18,7,9,11,5,6,0};
  int arrSize = sizeof(arr)/sizeof(int);
  //
  for (int i = 0; i < arrSize; i++) {
    int max = arr[i];
    for (int j = i; j < arrSize; j++) {
      if (arr[j] > max) {
        max = arr[j];
      }
    }
  }

  return 0;
}