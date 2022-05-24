#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int args, char* argv[])
{
  node* head;

  // create an empty list
  create_list(&head);

  // add some nodes to the list
  node* new_node;
  int i;
  for (i = 1; i < 10; ++i)
  {
    // create a new node
    new_node = (node*)malloc(sizeof(node));
    // set its data field to a random number [0, 100)
    new_node->data = rand() % 100;
    // its next field is set in the add function
    // as well as adjusting the head pointer
    add(&head, new_node);
  }


  // make copy of head for traversal
  node* my_head = head;
  // cheap print list
  while (my_head)
  {
    printf("data = %d\n", my_head->data);
    my_head = my_head->next;
  }

  // free all of the nodes left in the list
  free_list(&head);

  return 0;
}

