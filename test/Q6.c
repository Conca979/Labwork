// insertion sort

#include <stdio.h>

int main() {
  int arr[] = {17,13,12,100,8,15,2,16,14,1,3,4,19,20,10,18,7,9,11,5,6,0};
  int arrSize = sizeof(arr)/sizeof(int);
  for (int i = 0; i < arrSize-1; i++) {
    for (int j = i; j >= 0; j--) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      } else break;
    }
  }
  for (int i = 0; i<arrSize; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}