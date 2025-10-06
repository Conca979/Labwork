// Initialize a random array of your choice. The current goal is to verify whether an array number is
// centered cube.
// Note: a centered cube number is calculated by the following formula:
// 𝑓(𝑛) = 𝑛^3 + (𝑛 + 1)^3
// For example, the centered cube numbers are:
// f(1) = 1^3 + (1 + 1)^3 = 9
// f(2) = 2^3 + (2 + 1)^3 = 8 + 27 = 35
// f(3) = 3^3 + (3 + 1)^3 = 27 + 64 = 91
// …..
// ▪ Write pseudo-code using Recursion (if necessary, Iteration) to check all values in the given
// array are centered cube or not. (2pts)
// ▪ Write a program in C/C++ to complete your proposed algorithm in the pseudo-code. (7pts).
// Note: The program must include a recursive function and the main function.
// ▪ Calculate the complexity of your algorithm. Justify the answer. (2pts)


#include <stdio.h>
#include <math.h>

void recursion(int arr[], int arrSize, int index);

int main() {
  int arr[] = {9, 3, 881, 189, 5, 1, 35, 99, 91};
  int arrSize = sizeof(arr)/sizeof(int);
  //
  //sorting by bubble sort
  for (int i = 1; i<arrSize; i++) {
    for (int j = 0; j < arrSize-i; j++) {
      if (arr[j]>arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  for (int i = 0; i<arrSize; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  //
  //find max numb
  int max = arr[0];
  for (int i = 1; i<arrSize; i++) {
    if (arr[i]>max) 
      max = arr[i];
  }
  //
  recursion(arr, arrSize, 0);
  //finding cube
  // for (int j = 0; j < arrSize; j++) {
  //   for (int i = 1; ((int) (pow(i, 3)+pow(i+1, 3))) < max; i++) {
  //     if (((int) (pow(i, 3)+pow(i+1, 3))) == arr[j]) {
  //       printf("%d is a centered cube\n", arr[j]);
  //       break;
  //     }
  //   }
  // }
  //
  

  return 0;
}

void recursion(int arr[], int arrSize, int index) {
  int max = arr[0];
  for (int i = 1; i<arrSize; i++) {
    if (arr[i]>max) 
      max = arr[i];
  }
  if (index == arrSize) {
    return;
  }
  for (int i = 1; ((int) (pow(i, 3)+pow(i+1, 3))) <= max; i++) {
    if (((int) (pow(i, 3)+pow(i+1, 3))) == arr[index]) {
      printf("%d is a centered cube\n", arr[index]);
      break;
    }
  }
  recursion(arr, arrSize, index+1);
}