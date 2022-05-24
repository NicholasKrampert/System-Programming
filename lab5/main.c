#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int args, char* argv[])
{
  node* head;
  node* new_node;

  // create a new (empty) list
  head = NULL;

  int i;
  for (i = 1; i < 10; ++i)
  {
    // create a new node
    new_node = (node*)malloc(sizeof(node));
    // set its data field
    new_node->data = 2 * i;
    // its next field is set in the add function
    // as well as adjusting the head pointer
    add(&head, new_node);
  }
  yeet(&head);

  int len = list_len(head);
  printf("\nList length = %d\n\n", len);

  // make copy of head for traversal
  node* my_head = head;
  // cheap print list
  while ( my_head )
  {
    printf("data = %d\n", my_head->data);
    my_head = my_head->next;
  }

  // think: how would you free all of the node? ...
  // free(head); ?

  return 0;
}

