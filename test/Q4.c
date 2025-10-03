//new bubble sort
// Given an array of n elements, the Bubble sort algorithm swaps repeatedly the adjacent elements
// if they are in the wrong order (ascending order). We want to implement an improve version of this
// sorting algorithm.
// The idea is to sort both maximum (at the end) and minimum (at the beginning) in one pass and the
// array is sorted from both ends.
// - Traverse from left to right and compare adjacent elements and the maximum is placed at
// right side.
// - Traverse from right to left and compare adjacent elements and the minimum is placed at
// left side.
// - Repeat the process until the array is sorted.
// Implement this algorithm in C/C++. Calculate the complexity of the above algorithm. Justify your
// answer. 

#include <stdio.h>

int main() {
  int arr[] = {9, 8, 3, 5, 4, 1, 7, 6, 2, 0};
  int arrSize = sizeof(arr)/sizeof(int);
  int leftIndex = 0, rightIndex = arrSize-1;

  for (int i = 0; i<arrSize; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  for (int i = 0; i < arrSize/2; i++) {
    //max
    int max = arr[leftIndex];
    int index = leftIndex;
    for (int j = leftIndex; j <= rightIndex; j++) {
      if (arr[j] > max) {
        max = arr[j];
        index = j;
      }
    }
    arr[index] = arr[rightIndex];
    arr[rightIndex] = max;
    rightIndex--;
    //min
    int min = arr[rightIndex];
    index = rightIndex;
    for (int j = rightIndex; j >= leftIndex; j--) {
      if (arr[j] < min) {
        min = arr[j];
        index = j;
      }
    }
    arr[index] = arr[leftIndex];
    arr[leftIndex] = min;
    leftIndex++;
  }
  for (int i = 0; i<arrSize; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}