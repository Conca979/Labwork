#include <stdio.h>
#include <stdlib.h>

// linked list implemenation

typedef struct node {
  int value;
  struct node *prv;
  struct node *next;
} node;

void addNode(node **head, int value);
void countEven(node *head, int *count);
void findMax(node *head, int *max);
void printList(node *head);
void reverseList(node **head, node *nodes);

int main() {
  node *head = NULL;
  //
  addNode(&head, 12);
  addNode(&head, 1);
  addNode(&head, 2);
  addNode(&head, 5);
  addNode(&head, 10);
  addNode(&head, 5);
  addNode(&head, 9);
  addNode(&head, 60);
  //
  reverseList(&head, head);
  //
  int evenCount = 0;
  countEven(head, &evenCount);
  //
  int max = -9999;
  findMax(head, &max);
  //
  printf("%d-%d\n", evenCount, max);

  //
  printList(head);
  return 0;
}

void addNode(node **head, int value) {
  if ((*head) == NULL) {
    (*head) = malloc(sizeof(node));
    (*head)->value = value;
    (*head)->next = NULL;
    (*head)->prv = NULL;
    return;
  }
  if ((*head)->next != NULL) {
    addNode(&((*head)->next), value);
  } else {
    (*head)->next = malloc(sizeof(node));
    (*head)->next->value = value;
    (*head)->next->next = NULL;
    (*head)->next->prv = (*head);
  }

}

void countEven(node *head, int *count) {
  if (head == NULL) {
    return;
  }
  if (head->value % 2 == 0) {
    (*count)++;
  }
  countEven(head->next, count);
}

void findMax(node *head, int *max) {
  if (head == NULL)
    return;
  if (head->value > (*max)) {
    (*max) = head->value;
  }
  findMax(head->next, max);
}

void printList(node *head) {
  if (head == NULL) 
    return;
  printf("%d ", head->value);
  printList(head->next);
}

void reverseList(node **head, node *nodes) {
  if (nodes == NULL) {
    return;
  }
  node *temp = nodes->next;
  nodes->next = nodes->prv;
  nodes->prv = temp;
  (*head) = nodes;
  reverseList(head, nodes->prv);
}