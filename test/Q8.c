#include <stdio.h>

void printArr(int arr[], int arrSize);
void mergeSort(int arr[], int arrSize);

int main() {
  int arr[] = {17,13,12,100,8,15,2,16,14,1,3,4,19,20,10,18,7,9,11,5,6,0};
  int arrSize = sizeof(arr)/sizeof(int);
  mergeSort(arr, arrSize);

  printf("Sorted array: ");
  printArr(arr, arrSize);

  return 0;
}

void printArr(int arr[], int arrSize) {
  printf("[ ");
  for (int i = 0; i < arrSize; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

void mergeSort(int arr[], int arrSize) {
  if (arrSize < 2) return;
  int leftSize = arrSize/2;
  int rightSize = arrSize - leftSize;
  //
  // spliting 
  int leftArr[leftSize];
  for (int i = 0; i < leftSize; i++) {
    leftArr[i] = arr[i];
  }
  int rightArr[rightSize];
  for (int i = 0; i < rightSize; i++) {
    rightArr[i] = arr[leftSize+i];
  }
  //
  if (leftSize > 1) {
    mergeSort(leftArr, leftSize);
  }
  if (rightSize > 1) {
    mergeSort(rightArr, rightSize);
  }
  printArr(leftArr, leftSize);
  printArr(rightArr, rightSize);
  //
  //sort
  int leftIndex = 0, rightIndex = 0, arrIndex = 0;
  while ((leftIndex < leftSize) && (rightIndex < rightSize)) {
    if (leftArr[leftIndex] <= rightArr[rightIndex]) {
      arr[arrIndex] = leftArr[leftIndex];
      leftIndex++;
      arrIndex++;
    } else {
      arr[arrIndex] = rightArr[rightIndex];
      rightIndex++;
      arrIndex++;
    }
  }
  for (int i = 0; leftIndex < leftSize; i++) {
    arr[arrIndex+i] = leftArr[leftIndex];
    leftIndex++;
  }
  for (int i = 0; rightIndex < rightSize; i++) {
    arr[arrIndex+i] = rightArr[rightIndex];
    rightIndex++;
  }
}

