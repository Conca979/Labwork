#include <stdio.h>

void recursive(int numb, int *sum);

int main() {
  int numb = 12345;
  int sum = 0;
  recursive(numb, &sum);
  printf("%d", sum);

  return 0;
}

void recursive(int numb, int *sum) {
  if (numb == 0) {
    return;
  }
  (*sum) += numb % 10;
  return recursive(numb/10, sum);
}