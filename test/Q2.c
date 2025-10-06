#include <stdio.h>
#include <stdlib.h>

//fractional num -> binary

void IntPart(int *Ipart, int ipart, int *length);
void FracPart(int *Fpart, double fpart, int *fraclength, int limit);

int main() {
  //
  double number = 8.234;
  int limit = 4;
  //
  int intLength = 0, fractLength = 0;
  int *pIntPart = malloc(10*sizeof(int));
  int *pFractPart = malloc(limit*sizeof(int));

  int intPart = (int) number;
  double fractPart = number - intPart;

  //evaluate the decimal part
  IntPart(pIntPart, intPart, &intLength);
  //
  // for (; intPart != 0; intPart /= 2) {
  //   pIntPart[intLength] = intPart % 2;
  //   intLength++;
  // }

  //evaluate the frational part
  FracPart(pFractPart, fractPart, &fractLength, limit);
  //
  // for (int i = 0; i != limit; i++) {
  //   if (fractPart == 0) {
  //     fractLength++;
  //     break;
  //   } else if (fractPart == 0 && i == 0) {
  //     fractLength = 1;
  //     pFractPart[0] = 0;
  //     break;
  //   }
  //   fractPart *= 2;
  //   if (fractPart >= 1) {
  //     fractPart -= 1;
  //     pFractPart[fractLength] = 1;
  //     fractLength++;
  //   } else {
  //     pFractPart[fractLength] = 0;
  //     fractLength++;
  //   }
  // }
  //

  printf("%f = ", number);
  for (int i = intLength-1; i >= 0; i--) {
    printf("%d", pIntPart[i]);
  }
  printf(".");
  for (int i = 0; i < fractLength; i++) {
    printf("%d", pFractPart[i]);
  }


  return 0;
}

void IntPart(int *Ipart, int ipart, int *length) {
  if (ipart == 0) {
    return;
  }
  Ipart[*length] = ipart % 2;
  (*length)++;
  IntPart(Ipart, ipart/2, length);
}

void FracPart(int *Fpart, double fpart, int *fraclength, int limit) {
  if (limit == 0) {
    return;
  }
  fpart *= 2;
  if (fpart >= 1) {
    Fpart[*fraclength] = 1;
    (*fraclength)++;
    fpart -= 1;
  } else {
    Fpart[*fraclength] = 0;
    (*fraclength)++;
  }
  FracPart(Fpart, fpart, fraclength, limit-1);
}