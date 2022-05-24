#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int args, char* argv[]){
  int c = 0;
  float n;
  float* arr = creatr_queue();
  while(c != 3){
    printf("Enter a number\n");
    printf("1: Enqueue, 2: Dequeue, 3: Exit : ");
    scanf("%d", &c);
    if(c == 1){
      printf("Enter a float: ");
      scanf("%f", &n);
      enque(n, arr);
    }
    else if(c == 2)
      printf("\nElement dequeue: %f\n", deque(arr));
    else if(c == 3)
      break;
    else
      printf("\nEnter again: ");
  }
}
