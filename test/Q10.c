#include <stdio.h>

int parseFactor();
int parseProduct();
int parseSum();


char *factor = "2*4-9*3\n";

int main() {
  printf("%s\n", factor);

  printf("Result : %d\n", parseSum());


  return 0;
}

int parseFactor() {
  if (*factor >= 48 && *factor <= 57) {
    int value = (*factor)-'0';
    factor++;
    printf("%d\n", value);
    return value;
  } else {
    printf("%c is not recognized as a number\n", *factor);
  }
}

int parseProduct() {
  int num1 = parseFactor();
  if (*factor == '*') {
    factor++;
    int num2 = parseFactor();
    num1 = num1*num2;
  }
  return num1;
}

int parseSum() {
  int num1 = parseProduct();
  if (*factor == '+') {
    factor++;
    int num2 = parseProduct();
    num1 = num1+num2;
  }
  return num1;
}