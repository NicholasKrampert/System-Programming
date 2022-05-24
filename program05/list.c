#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// create an empty list - set *head = NULL
void create_list(node** head){
  *head = NULL;
}

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


// add a new node in the list, in (ascending) sorted order based on
// the nodes name component's value
void add_inorder(node* *head, node* new_node){
  if(*head == NULL)
    *head = new_node;
  else if(strcmp((*head)->name, new_node->name) > 0){
    node* tmp = *head;
    *head = new_node;
    new_node->next = tmp;
  }
  else{
    node* before = *head;
    int done = 0;
    while(!done && before->next){
      if(strcmp(before->next->name, new_node->name) > 0){
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
// remove and return the first node in the list whose name component's value
// is equal to the given key_name
// return NULL if no such node exists in the list
node* rem_inorder(node* *head, char* key_name){
  node* rem;
  if(*head == NULL)
    return NULL;
  if(strcmp((*head)->name, key_name) == 0){
    rem = *head;
    *head = (*head)->next;
    return rem;
  }
  node* tmp = (*head)->next;
  node* lag = *head;
  while(tmp){
    if(strcmp(tmp->name, key_name) == 0){
      rem = tmp;
      lag->next = tmp->next;
      return rem;
    }
    lag = tmp;
    tmp = tmp->next;
  }
  return NULL;
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

// free the entire list and set *node = NULL
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

