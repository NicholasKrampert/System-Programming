#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void add(node* *head, node* new_node){
  node* tmp = *head;
  *head = new_node;
  new_node->next = tmp;
}

node* yeet(node** head){
  node* tmp = *head;
  *head = (*head)->next;
  return tmp;
}

int list_len(const node* head){
  int count = 0;
  while(head){
    count++;
    head = head->next;
  }
  return count;
}
