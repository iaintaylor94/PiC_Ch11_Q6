// Program to create and print a doubly linked list
// Also to insert and delete elements

#include <stdio.h>

// Define Structures
struct dll {
struct dll *previous;
int value;
struct dll *next;
};

// Declare Functions
void insertElement (struct dll *, struct dll *);
void removeElement (struct dll *);
struct dll *printList (struct dll *);

int main(void) {

  // Devclare dlls
  struct dll *linkHead;
  struct dll n1, n2, n3;

  // Initialize values
  n1.value = 1;
  n2.value = 2;
  n3.value = 3;

  // Link entries
  linkHead = &n1;
  n1.previous = linkHead; n1.next = &n2;
  n2.previous = &n1; n2.next = &n3;
  n3.previous = &n2; n3.next = (struct dll *) 0;

  // Print list
  printList (linkHead);
  printf ("\n");

  // Insert element
  struct dll toInsert;
  toInsert.value = 4;
  insertElement (&toInsert, &n2);

  // Print list
  printList(linkHead);
  printf ("\n");

  // Remove element
  removeElement (&toInsert);

  // Print list
  printList(linkHead);
  printf ("\n");
  
  return 0;
}

// Define Functions
void insertElement (struct dll *insert, struct dll *after) {
  insert->previous = after;
  insert->next = after->next;
  after->next = insert;
}

void removeElement (struct dll *remove) {
  remove->previous->next = remove->next;
  remove->next->previous = remove->previous;
}

struct dll *printList (struct dll* current) {
  if (current->next == (struct dll*) 0) {
    printf ("%d\n", current->value);
    return (struct dll*) 0;
  }
  else {
    printf ("%d\n", current->value);
    printList (current->next);
    return (struct dll*) 0;
  }
}