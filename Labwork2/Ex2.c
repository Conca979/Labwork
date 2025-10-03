// Exercise 2: Assume that a railway train has N railroad cars attached together
// such as car1, car2, car3, ..., carN . A train can be considered as a list and each car
// corresponds to a node in this list.
// 1
//  Each car carries a maximum capacity of passengers (int type) and has an id
// (char type). Both variables are user-defined values.
//  Each car is reserved by a number of passengers (int type) (which should be
// less than its capacity). If there are any cars that don’t have any passengers,
// they should be removed from the train.
//  It is possible to add new cars to the train.
//  A function is available to display all cars’ information or the length of the
// train.
// Implement a program in C/C++

#include <stdio.h>
#include <stdlib.h>
#define _capacity 20

struct Car {
  char id;
  int reserved;
};

void addCar(struct Car ***train, char id, int reserved, int *length);
/*train: address of **train
  id: id of new car
  length: address of trainLength*/
void carChange(struct Car ***train, char id, int newReservation, int *length);
/*id: id of a car to change
  newRe: new reservation*/
void displayTrain(struct Car ***train, int length);

int main() {
  struct Car **train = NULL; //ptr to struct
  int length = 0;
  addCar(&train, 'A', 5, &length);
  addCar(&train, 'B', 6, &length);
  addCar(&train, 'C', 7, &length);
  addCar(&train, 'D', 8, &length);
  addCar(&train, 'E', 9, &length);
  addCar(&train, 'F', 10, &length);
  carChange(&train, 'D', 0, &length);
  carChange(&train, 'A', 0, &length);
  displayTrain(&train, length);

  //a loop to free all allocated memory later

  return 0;
}

void addCar(struct Car ***train, char id, int reserved, int *length) {
  if (reserved > _capacity) {
    printf("Cannot add Car id = %c, capacity conflic\n", id);
    return;
  }
  (*length)++;
  *train = realloc(*train, (*length)*sizeof(struct Car *));
  (*train)[(*length)-1] = calloc(1, sizeof(struct Car));
  (*train)[(*length)-1]->id = id;
  (*train)[(*length)-1]->reserved = reserved;
}

void displayTrain(struct Car ***train, int length) {
  printf("Train's length = %d %s\n", length, length==0?"car":"cars");
  for (int i = 0; i<length; i++) {
    printf("[%c-%d]\n", (*train)[i]->id, (*train)[i]->reserved);
  }
}

void carChange(struct Car ***train, char id, int newReservation, int *length) {
  if (newReservation > _capacity) {
    printf("Cannot change Car id = %c, capacity conflic\n", id);
    return;
  } else if (newReservation == 0) {
    for (int i = 0; i<(*length); i++) {
      if ((*train)[i]->id == id) {
        free((*train)[i]);
        for (int j = i; j<(*length)-1; j++) {
          // struct Car *temp = (*train)[j];
          (*train)[j] = (*train)[j+1];
        }
        (*length)--;
        *train = realloc(*train, (*length)*sizeof(struct Car *));
        break;
      }
    }
  } else {
    for (int i = 0; i<(*length); i++) {
      if ((*train)[i]->id == id) {
        (*train)[i]->reserved = newReservation;
        break;
      }
    }
  }
}

/*The code above using strategy define train as a pointer to array of pointer to struct*/

/*the code below using strategy define train as a pointer to array of structs*/

// struct Car {
//   int capacity;
//   char id;
// };

// int checkLimit(int capacity);
// int addCar(struct Car **train, int* trainLength, int capacity, char id);
// void displayTrain(struct Car **train, int trainLength);

// int main() {
//   struct Car *train = NULL; //pointer to struct
//   int trainLength = 0;
//   if (!addCar(&train, &trainLength, 3, '1')) {
//     printf("The car's capacity limit is %d", _limitCapacity);
//     return 0;
//   } else if (!addCar(&train, &trainLength, 9, '2')) {
//     printf("The car's capacity limit is %d", _limitCapacity);
//     return 0;
//   } else if (!addCar(&train, &trainLength, 4, '3')) {
//     printf("The car's capacity limit is %d", _limitCapacity);
//     return 0;
//   }
//   displayTrain(&train, trainLength);

//   return 0;
// }

// int addCar(struct Car **train, int* trainLength, int capacity, char id) {
//   if (checkLimit(capacity) == 2) return 1;
//   else if (!checkLimit(capacity)) return 0;
//   (*trainLength)++;
//   if (*trainLength == 1) {
//     (*train) = calloc(*trainLength, sizeof(struct Car));
//     (*train)[(*trainLength)-1].capacity = capacity;
//     (*train)[(*trainLength)-1].id = id;
//   } else {
//     (*train) = realloc((*train), (*trainLength)*sizeof(struct Car));
//     (*train)[(*trainLength)-1].capacity = capacity;
//     (*train)[(*trainLength)-1].id = id;
//   }
//   printf("New Car was added\n");
//   return 1;
// }

// void displayTrain(struct Car **train, int trainLength) {
//   for (int i = 0; i<trainLength; i++) {
//     printf("|%d-[%d][%c]|\n", i+1, (*train)[i].capacity, (*train)[i].id);
//   }
// }

// int checkLimit(int capacity) {
//   if ((capacity > _limitCapacity) || (capacity < 0))
//     return 0;
//   else if (capacity == 0)
//     return 2;
//   else return 1;
// }