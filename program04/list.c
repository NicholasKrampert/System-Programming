#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// add a new node to the front of the list
void add_front(node* *head, node* new_node){
  node* tmp = *head;
  *head = new_node;
  new_node->next = tmp;
}

// add a new node to the end of the list
void add_end(node* *head, node* new_node){
  node* tmp = *head;
  if(*head == NULL){
    new_node->next = *head;
    *head = new_node;
    return;
  }
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  tmp->next = new_node;
  new_node->next = NULL;
}

// remove and return the node at the front of the list or NULL if empty
node* rem_front(node* *head){
  if(*head == NULL){
    return NULL;
  }
  node* tmp = *head;
  *head = (*head)->next;
  return tmp;
}

// remove and return the node at the end of the list or NULL if empty
node* rem_end(node* *head){
  if(*head == NULL){
    return NULL;
  }
  node* tmp = *head;
  node* lag = NULL;
  while(tmp->next != NULL){
    lag = tmp;
    tmp = tmp->next;
  }
  lag->next = NULL;
  return tmp;
}

// return the number of nodes in the list
int list_len(const node* head){
  int count = 0;
  while(head){
    count++;
    head = head->next;
  }
  return count;
}

// print the data values of  all the nodes in the list (from start to end)
void print_list(const node* head){
  node* tmp = head;
  if(head == NULL)
    return;
  if(tmp->next == NULL){
    printf("\nid: %d, name: %s\n", tmp->id, tmp->name);
    return;
  }
  do{
    printf("\nid: %d, name: %s\n", tmp->id, tmp->name);
    tmp = tmp->next;
  }while(tmp != NULL);
}

// free the entire list and set *head = NULL
void free_list(node* *head){
  node* tmp = *head;
  while(tmp){
    node* insideTMP = tmp;
    free(insideTMP->name);
    free(insideTMP);
    tmp = tmp->next;
  }
  *head = NULL;
}
