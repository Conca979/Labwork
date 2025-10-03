#include <stdio.h>
#include <math.h>

//sum of digits
int sum(int number);

int main() {
  int numb = 11111;
  //
  int sum = 0;
  for (; numb > 0;) {
    sum += numb % 10;
    numb /= 10;
  }
  printf("%d", sum);

  return 0;
}