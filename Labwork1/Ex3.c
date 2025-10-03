// Write a structure to represent complex numbers and complete operators: add and multiply.

#include <stdio.h>

void printComple(int complex[]);
void printSum(int complex1[], int complex2[]);
void printMul(int complex1[], int complex2[]);

void main () {
  int complex1[] = {3, -4};
  int complex2[] = {5,-5};
  printComple(complex1);
  printComple(complex2);
  printSum(complex1, complex2);
  printMul(complex1, complex2);
}

void printComple(int complex[]) {
  int realPart = complex[0];
  int imPart = complex[1];
  if (realPart == 0 && imPart != 0) {
    printf("%di\n", imPart);
    return;
  } else if (realPart != 0 && imPart == 0) {
    printf("%d\n", realPart);
    return;
  } else if (realPart == 0 && imPart == 0) {
    printf("0\n");
    return;
  } else {
    printf("%d%c%di\n", realPart, imPart>0?'+':'\0', imPart);
  }
}

void printSum(int complex1[], int complex2[]) {
  int realPartSum = complex1[0]+complex2[0];
  int imPartSum = complex1[1] + complex2[1];
  int final[] = {realPartSum, imPartSum};
  printComple(final);
}

void printMul(int complex1[], int complex2[]) {
  int realPartMul = complex1[0]*complex2[0]-complex1[1]*complex2[1];
  int imPartMul = complex1[0]*complex2[1]+complex1[1]*complex2[1];
  int final[] = {realPartMul, imPartMul};
  printComple(final);
}