

#include <stdio.h>
#include <stdlib.h>

struct person {
  char name[10];
  int age;
  int sex; //1 for male, 2 for female
};

int main() {
  struct person **ptr = calloc(0, sizeof(struct person*));
  *ptr = realloc(*ptr, 2*sizeof(struct person*));
  struct person Dave = {"Dave", 12, 1};
  struct person Sophia = {"Sophia", 20, 2};
  ptr[0] = &Dave;
  ptr[1] = &Sophia;
  printf("%s-%d\n", ptr[0]->name, (*ptr[0]).age);
  printf("%s-%d", ptr[1]->name, (*ptr[1]).age);
}
