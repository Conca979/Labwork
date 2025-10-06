#include <stdio.h>
#include <stdlib.h>

// array-based stack

typedef struct stack {
  int top;
  int capacity;
  int *arr;
} stack;

void sInit(stack **s, int cap);
void push(stack *s, int value);
void pop(stack *s);
void printStack(stack *s);
//
void parenCheck(stack *s);
// Input: (())()     → Balanced
// Input: (()(()     → Not balanced
//

int main() {
  stack *stack = NULL;
  sInit(&stack, 10);
  //
  push(stack, '(');
  push(stack, '(');
  push(stack, ')');
  push(stack, ')');
  push(stack, ')');
  parenCheck(stack);
  //
  printStack(stack);

  return 0;
}

void sInit(stack **s, int cap) {
  (*s) = malloc(sizeof(stack));
  // int *arr = malloc(sizeof(int)*cap);
  (*s)->arr = malloc(sizeof(int)*cap);
  (*s)->capacity = cap;
  (*s)->top = 0;

}

void push(stack *s, int value) {
  if (s->top == s->capacity) {
    printf("Cannot add %d into stack, stack is full\n", value);
    return;
  }
  s->arr[s->top] = value;
  s->top++;
}

void printStack(stack *s) {
  printf("Stack from top->bottom: ");
  int size = s->top;
  int *arr = s->arr;
  for (int i = size-1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void pop(stack *s) {
  if (s->top == 0)
    return;
  s->top--;
}

void parenCheck(stack *s) {
  int open = 0, close = 0;
  for (int i = 0; i < s->top; i++) {
    if (s->arr[i] == '(') {
      open++;
    } else {
      close++;
    }
  }
  printf("%s\n", open==close?"Balenced":"Not balenced");
}