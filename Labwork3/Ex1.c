// Suppose we would like to implement a queue system for a commercial website. Given that the website offers three items for sale (or a list of items), each item has a limited quantity in stock. Implement a queue of customers, each customer can buy only a few products among the available three items.
// - Determine the item name, their quantity in stock;
// - Specify a queue of n customers; each customer can buy k products from one item (k is different for each customer);
// - Customers take turns to enter (enqueue) and leave (dequeue) the queue according to the FIFO order to purchase wanted products;
// - If a customer successfully purchases products, then display a message and reduce the number of products in stock; otherwise, if the item has been run out, display a warning message.
// Implement the above problems in C/C++ using a Queue data structure. Write the main function for testing all written functions (`init()`, `display()`, `enqueue()`, `dequeue()`,...).

//Querry implimenation with linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct boxes {
  int customerNumber;
  struct boxes *next;
} box;

typedef struct product {
  int id;
  int quanity;
  int price;
  struct product *next;
} product;

void customerEnqueue(box **head, int customerNumber);
void customerDequeue(box **head);
void printQueue(box *head);
void printProduct(product *firstItem);
void newItem(product **firstItem, int id, int quantity, int price);
void makePurchase(box **head, product **firstItem, int productId, int quantity);
void deleteItem(product **firstItem, int id);
int findProductId(product **firstItem, int id);
int findBuyerId(box **head, int id);

//each customer has unique id
//each product has unque id

int main() {
  box *head = NULL;
  product *firstItem = NULL;

  customerEnqueue(&head, 1);
  customerEnqueue(&head, 2);
  customerEnqueue(&head, 3);
  customerEnqueue(&head, 2); //try to add a customer id already in queue
  newItem(&firstItem, 1, 100, 20);
  newItem(&firstItem, 2, 100, 30);
  newItem(&firstItem, 2, 100, 30); //try to add a product id already in queue
  makePurchase(&head, &firstItem, 1, 50);
  makePurchase(&head, &firstItem, 1, 50);
  makePurchase(&head, &firstItem, 2, 90);

  //inserting new actions

  printf("END");
}

void printQueue(box *head) {
  box * temp = head;
  printf("The queue: ");
  while(temp != NULL) {
    printf("%d%s", temp->customerNumber, (temp->next)==NULL?".\n":"-");
    temp = temp->next;
  }
}

void customerEnqueue(box **head, int customerNumber) {
  box* temp;
  if (*head == NULL) {
    printf("~The first customer, id %d goes in queue\n", customerNumber);
    temp = malloc(sizeof(box));
    temp->customerNumber = customerNumber;
    temp->next = NULL;
    *head = temp;
  } else {
    if (findBuyerId(head, customerNumber)) {
      printf("Cannot enqueue customer id %d, queue already have customer id %d\n", customerNumber, customerNumber);
      return;
    }
    //
    box* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    printf("~New customer %d goes in queue\n", customerNumber);
    current->next = malloc(sizeof(box));
    current->next->customerNumber = customerNumber;
    current->next->next = NULL;
    // the code below run the same but more complex
    // box **temp = &((*head)->next);
    // while(1) {
    //   if (*temp == NULL) {
    //     printf("New node added\n");
    //     *temp = malloc(sizeof(box));
    //     (*temp)->customerNumber = customerNumber;
    //     (*temp)->next = NULL;
    //     return;
    //   }
    //   temp = &(*temp)->next;
    // }
  }
  printQueue(*head);
}

void customerDequeue(box **head) {
  printf("~Customer %d done purchasing\n", (*head)->customerNumber);
  box* temp = *head;
  free(*head);
  *head = temp->next;
  printQueue(*head);
}

void newItem(product **firstItem, int id, int quantity, int price) {
  product* temp;
  if (*firstItem == NULL) {
    printf("~First item id %d was added\n", id);
    temp = malloc(sizeof(product));
    temp->id = id;
    temp->price = price;
    temp->quanity = quantity;
    temp->next = NULL;
    *firstItem = temp;
  } else {
    if (findProductId(firstItem, id)) {
      printf("~Cannot add product id %d into stall, in stall there is already product id %d\n", id, id);
      printProduct(*firstItem);
      return;
    }
    product* current = *firstItem;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = malloc(sizeof(product));
    current->next->id = id;
    current->next->quanity = quantity;
    current->next->price = price;
    current->next->next = NULL;
    printf("~New item id %d was added\n", id);
  }
  printProduct(*firstItem);
}

void printProduct(product *firstItem) {
  product * temp = firstItem;
  printf("~All available products: \n");
  while(temp != NULL) {
    printf("\t[ id: %d, quantity: %d, price: %d]\n", temp->id, temp->quanity, temp->price);
    temp = temp->next;
  }
}

void deleteItem(product **firstItem, int idToDelete) {
  if (!findProductId(firstItem, idToDelete)) {
    printf("Cannot find product %d to delete\n", idToDelete);
    return;
  }
  product *temp = *firstItem;
  product *temp2;
  if ((*firstItem)->id == idToDelete) {
    printf("product %d deleted\n", idToDelete);
    *firstItem = (*firstItem)->next;
    printProduct(*firstItem);
    return;
  }
  while (temp->next->id != idToDelete) {
    temp = temp->next;
  }
  printf("product %d deleted\n", temp->next->id);
  temp2 = temp->next->next;
  free(temp->next);
  temp->next = temp2;
  printProduct(*firstItem);
}

int findProductId(product **firstItem, int id) {
  product *temp = *firstItem;
  if (temp->id == id) return 1;
  for(; temp->next != NULL; ) {
    temp = temp->next;    
    if (temp->id == id) {
      return 1;
    }
  }
  return 0;
}

int findBuyerId(box **head, int id) {
  box *temp = *head; 
  if (temp->customerNumber == id) return 1;
  for (; temp->next != NULL; ) {
    temp = temp->next;
    if (temp->customerNumber == id) {
      return 1;
    }
  }
  return 0;
}

void makePurchase(box **head, product** firstItem, int productId, int quantity) {
  if (quantity < 0) {
    printf("Invalid product quantity (%d)\n", quantity);
    return;
  }
  product *itemToBuy = *firstItem;
  product *temp = *firstItem;
  if (!findProductId(firstItem, productId)) {
    printf("~Cannot find product %d to purchase\n", productId);
    return;
  }
  if ((*firstItem)->id == productId ) {
    if ((*firstItem)->quanity < quantity) {
      printf("~Product id %d was not enought for customer %d to buy %d/%d\n", productId, (*head)->customerNumber, quantity, (*firstItem)->quanity);
      customerDequeue(head);
      printProduct(*firstItem);
      return;
    } else {
      (*firstItem)->quanity -= quantity;
      printf("~Customer id %d have been purchased successfully the product id %d, %d %s \n", (*head)->customerNumber, productId, quantity, quantity>1?"items":"item");
      customerDequeue(head);
      if (itemToBuy->quanity == 0) {
        deleteItem(firstItem, productId);
      }
      printProduct(*firstItem);
    }
    return;
  }
  while (itemToBuy->next->id != productId) {
    itemToBuy = itemToBuy->next;
  }
  if (itemToBuy->quanity < quantity) {
    customerDequeue(head);
    printProduct(*firstItem);
    return;
  } else {
    itemToBuy->quanity -= quantity;
    printf("~Customer id %d have been purchased successfully the product id %d, %d %c\n", (*head)->customerNumber, productId, quantity, quantity>1?"items":"item");
    if (itemToBuy->quanity == 0) {
      deleteItem(firstItem, productId);
    }
    customerDequeue(head);
    printProduct(*firstItem);
    return;
  }
}