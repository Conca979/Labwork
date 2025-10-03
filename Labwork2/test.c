

#include <stdio.h>
#include <stdlib.h>

struct person {
  char name[10];
  int age;
  int sex; //1 for male, 2 for female
};

int main() {
  int num = 4;
  int *ptr1 = &num;
  int *ptr2 = ptr1;
  printf("%d", *ptr2);
}
