// : Suppose that we use a List data structure to represent unbounded
// integers.
//  the first element refers to the sign: 1 is positive and -1 is negative.
//  each element in the list represents one digit of these integers.
// Implement and test the program in C/C++ using an Array-based List (Static or
// Dynamic) to manage this unbounded integers:
// 1 add new digits at any place in an integer.
// 2 remove a digit at a specfic position in an integer.
// 3 calculate the sum of all digits from an unbounded integer.
// 4 display the whole number on the screen

#include <stdio.h>
#include <stdlib.h>

int length(char num[]);
void configuringList(int** list, int length, char num[]);
void displayList(int** list, int listLength);
void removeDigit(int** list, int position, int *listLength);
void addDigit(int** list, int position, int newDigit, int *listLength);
int sum(int** list, int listLength);

int main() {
  char number[] = "-1030598475397585439457049375034";
  int *list;
  int listLength = 0;
  if (!length(number)) {
    printf("Invalid form");
    return 0;
  } else {
    listLength =  length(number)+1;
  }
  printf("length(%s) = %d", number, listLength);
  configuringList(&list, listLength, number);
  displayList(&list, listLength);

  // free(list);
  return 0;
}

int length(char num[]) {
  int count = 0;
  if ((num[0] == 43 || num[0] == 45) && num[1] != 0) {
    for (int i = 1; num[i] != '\0'; i++) {
      if (num[i] < '0' || num[i] > '9')
        return 0;
      count++;
    }
  } else if (num[0] >= '0' && num[0] <= '9') {
    for (int i = 0; num[i] != '\0'; i++) {
      if (num[i] < '0' || num[i] > '9')
        return 0;
      count++;
    }
  }
  return count;
}

void configuringList(int **list, int length, char num[]) {
  *list = calloc(length, sizeof(int));
  if ((num[0] == 43 || num[0] == 45) && num[1] != 0) {
    if (num[0] == 43) 
      (*list)[0] = 1;
    else (*list)[0] = -1;
    //
    for (int i = 1; num[i] != '\0'; i++) {
      (*list)[i] = num[i] - '0';
    }
    //
  } else if (num[0] >= '0' && num[0] <= '9') {
    (*list)[0] = 1;
    //
    for (int i = 0; num[i] != '\0'; i++) {
      (*list)[i+1] = num[i] - '0';
    }
    //
  }
}

void displayList(int** list, int listLength) {
  printf("\nThe list: ");
  for (int i = 0; i<listLength; i++) {
    printf("|%d|%d| ", i, (*list)[i]);
  }
}

void removeDigit(int** list, int position, int *listLength) {
  for (int i = position; (*listLength)-1-i; i++) {
    (*list)[i] = (*list)[i+1]; 
  }
  (*listLength)--;
  *list = realloc(*list, (*listLength)*sizeof(int));
}

void addDigit(int** list, int position, int newDigit, int *listLength) {
  (*listLength)++;
  *list = realloc(*list, (*listLength)*sizeof(int));
  for (int i = (*listLength)-1; i!=position; i--) {
    (*list)[i] = (*list)[i-1];
  }
  (*list)[position] = newDigit;
}

int sum(int** list, int listLength) {
  int sum = 0;
  for (int i = 1; i<listLength; i++) {
    sum+=(*list)[i];
  }
  return sum;
}