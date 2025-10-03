#include <stdio.h>
#include <stdlib.h>

//fractional num -> binary

int main() {
  //
  double number = 19.234;
  int limit = 4;
  //
  int intLength = 0, fractLength = 0;
  int *pIntPart = malloc(10*sizeof(int));
  int *pFractPart = malloc(limit*sizeof(int));

  int intPart = (int) number;
  double fractPart = number - intPart;
  for (; intPart != 0; intPart /= 2) {
    pIntPart[intLength] = intPart % 2;
    intLength++;
  }

  

  for (int i = 0; i != limit; i++) {
    if (fractPart == 0) {
      fractLength++;
      break;
    } else if (fractPart == 0 && i == 0) {
      fractLength = 1;
      pFractPart[0] = 0;
      break;
    }
    fractPart *= 2;
    if (fractPart >= 1) {
      fractPart -= 1;
      pFractPart[fractLength] = 1;
      fractLength++;
    } else {
      pFractPart[fractLength] = 0;
      fractLength++;
    }
  }

  for (int i = intLength-1; i >= 0; i--) {
    printf("%d", pIntPart[i]);
  }
  printf(".");
  for (int i = 0; i < fractLength; i++) {
    printf("%d", pFractPart[i]);
  }


  return 0;
}