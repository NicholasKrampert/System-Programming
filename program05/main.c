
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int args, char* argv[]){
  int c = 0;
  int id;
  node* head = NULL;
  while(c != 6){
    printf("Enter a number\n");
    printf("1: add to start, 2: add to end, 3: add inorder, 4: remove inorder, 5: remove from start, 6: reomve from end, 7: print list, 8: quit :");
    scanf("%d", &c);
    if(c == 1){
      node* new_node = (node*)malloc(sizeof(node));
      new_node->next = NULL;
      char* name = (char*)malloc(sizeof(char) * 20);
      printf("\nEnter your id: ");
      scanf("%d", &id);
      printf("\nEnter your name: ");
      scanf("%s", name);
      new_node->id = id;
      new_node->name = name;
      add_front(&head, new_node);
//      printf("%d, %s\n", head->id, head->name);
    }
    else if(c == 2){
      node* new_node = (node*)malloc(sizeof(node));
      new_node->next = NULL;
      char* name = (char*)malloc(sizeof(char) * 20);
      printf("\nEnter your id: ");
      scanf("%d", &id);
      printf("\nEnter your name: ");
      scanf("%s", name);
      new_node->id = id;
      new_node->name = name;
      add_end(&head, new_node);
//      printf("%d, %s\n", head->id, head->name);
    }
    else if(c == 3){
      node* new_node = (node*)malloc(sizeof(node));
      new_node->next = NULL;
      char* name = (char*)malloc(sizeof(char) * 20);
      printf("\nEnter your id: ");
      scanf("%d", &id);
      printf("\nEnter your name: ");
      scanf("%s", name);
      new_node->id = id;
      new_node->name = name;
      add_inorder(&head, new_node);
    }
    else if(c == 4){
      char* key_name = (char*)malloc(sizeof(char) * 20);
      printf("\nEnter a name you want to remove: ");
      scanf("%s", key_name);
      node* rem = rem_inorder(&head, key_name);
      if(rem != NULL)
        printf("\nRemoved id: %d name: %s\n", rem->id, rem->name);
      else
        printf("\nNo such element exists in the list");
    }
    else if(c == 5){
      node* rem = rem_front(&head);
      printf("\nRemoved id: %d name: %s\n", rem->id, rem->name);
    }
    else if(c == 6){
      node* rem = rem_end(&head);
      printf("\nRemoved id: %d name: %s\n", rem->id, rem->name);
    }
    else if(c == 7){
      print_list(head);
    }
    else if(c == 8){
      free_list(&head);
      break;
    }
    else{
      printf("\nEnter again: ");
    }
  }
}

