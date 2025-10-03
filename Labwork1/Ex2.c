// Complete this given function void findMax(int *max, int a), which assigns a value a to max if a > max

#include <stdio.h>

void findMax(int *max, int a);

int main() {
  int testNum = 9;
  int *max;
  *max = 10;
  findMax(max, testNum);
  printf("%d", *max);
}

void findMax(int *max, int a) {
  if (a > *max) 
    *max = a;
}
