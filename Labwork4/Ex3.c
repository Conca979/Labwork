// Write a program in C/C++ to enter a natural number n and verify whether n is sphenic using Recursion. Calculate the complexity of the proposed algorithm. Note: A sphenic number is a product of pqr where p, q, and r are three distinct prime numbers. Example:
// 30 = 2 * 3 * 5
// 42 = 2 * 3 * 7
// 66 = 2 * 3 * 11

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 23554;
  int count = 3;
  int *ptr = malloc(count*sizeof(int));
  ptr[0] = 2;
  ptr[1] = 3;
  ptr[2] = 5;
  //
  //finding primes
  int newPrime = ptr[count-1] + 1;
  while (ptr[count-1]*ptr[count-2]*ptr[count-3] < num) {
    int temp = 0;
    for (int i = 2; i < newPrime; i++) {
      if (newPrime % i == 0) {
        temp++;
        break;
      }
    }
    if (temp == 0) {
      ptr = realloc(ptr, (count+1)*sizeof(int));
      ptr[count] = newPrime;
      count++;
    }
    newPrime++;
  }
  for (int i = 0; i < count; i++) {
    printf("%d ", ptr[i]);
  }
  //
  //sphenic checking
  for (int i = 0; i < count-2; i++) {
    for (int j = i+1; j < count-1; j++) {
      for (int h = j+1; h < count; h++) {
        if (ptr[i]*ptr[j]*ptr[h] == num) {
          printf("\n%d is a sphenic number", num);
        }
      }
    }
  }
  
  return 0;
}