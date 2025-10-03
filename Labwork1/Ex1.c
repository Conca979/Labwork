#include <stdio.h>

// Write a pseudocode and implement a program in C to swap the first and last digits of a positive integer.

//pseudocode

int exchange(int number);
int power(int base, int exponent);

int main() {
  int number = 2;
  printf("%d result = %d", number, exchange(number));
}

int exchange(int number) {
  int temp = number;
  int lastDigit = number%10;
  int count = 0;
  for (; temp > 10; count++) {
    temp /= 10;
  }
  int firstDigit = number/(power(10, count));
  int middleDigit = number%(power(10, count))-lastDigit;
  printf("NumberLength = %d\nfirstDigit = %d\nmiddleDigits = %d\nlastDigit = %d\n", count+1, firstDigit, middleDigit/10, lastDigit);
  return lastDigit*(power(10, count))+middleDigit+firstDigit;
}

int power(int base, int exponent) {
  if (exponent == 0)
    return 1;
  return base*power(base, exponent-1);
}