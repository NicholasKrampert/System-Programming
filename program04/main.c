#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int args, char* argv[]){
  int c = 0;
  int id;
  node* head = NULL;//(node*)malloc(sizeof(node));
//  head->next = NULL;
  while(c != 6){
    printf("Enter a number\n");
    printf("1: add to start, 2: add to end, 3: remove from start, 4: remove from end, 5: print list, 6: quit : ");
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
      printf("%d, %s\n", head->id, head->name);
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
      printf("%d, %s\n", head->id, head->name);
    }
    else if(c == 3){
      node* rem = rem_front(&head);
      printf("\nRemoved id: %d name: %s\n", rem->id, rem->name);
    }
    else if(c == 4){
      node* rem = rem_end(&head);
      printf("\nRemoved id: %d name: %s\n", rem->id, rem->name);
    }
    else if(c == 5){
      print_list(head);
    }
    else if(c == 6){
      free_list(&head);
      break;
    }
    else{
      printf("\nEnter again: ");
    }
  }
}
