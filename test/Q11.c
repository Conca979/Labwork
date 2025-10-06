// Time complexity: O(n^2)
//  Best case: O(n^2)
//  Average case: O(n^2)
// space complexity: O(1)

#include <stdio.h>

void targetSum(int arr[], int arrSize, int index1, int index2);

int main() {
  int arr[] = {2, 4, 6, 3, 7, 8, 5};
  int arrSize = sizeof(arr)/sizeof(int);
  //
  // for (int i = 0; i < arrSize-1; i++) {
  //   for (int j = i+1; j < arrSize; j++) {
  //     if ((arr[i]+arr[j]) == 10) {
  //       printf("Sum to 10: %d-%d\n", arr[i], arr[j]);
  //     }
  //   }
  // }
  //
  targetSum(arr, arrSize, 0, 1);


  return 0;
}

void targetSum(int arr[], int arrSize, int index1, int index2) {
  int i = index1, j = index2;
  if (j >= arrSize) {
    i++;
    j = i;
  }
  if (i >= arrSize - 1) {
    return;
  }
  if ((arr[i]+arr[j]) == 10) {
    printf("Sum to 10: %d, %d\n", arr[i], arr[j]);
  }
  targetSum(arr, arrSize, i, j+1);
}