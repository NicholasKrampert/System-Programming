#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void create_list(node** head){
  *head = NULL;
}

void add(node* *head, node* new_node){
  if(*head == NULL){
    *head = new_node;
  }
  else if((*head)->next == NULL){
    if((*head)->data >= new_node->data){
      node* tmp = *head;
      *head = new_node;
      (*head)->next = tmp;
    }
    else{
      (*head)->next = new_node;
    }
  }
  else if((*head)->data > new_node->data){
    node* tmp = *head;
    *head = new_node;
    (*head)->next = tmp;
  }
  else{
    node* before = *head;
    int done = 0;
    while(!done && before->next){
      if(before->next->data >= new_node->data){
        done = 1;
      }
      else{
        before = before->next;
      }
    }
    new_node->next = before->next;
    before->next = new_node;
  }
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

void free_list(node* *head)
{
  if (*head)
  {
    free_list( &((*head)->next) );
    free(*head);
    *head = NULL;
  }
}

