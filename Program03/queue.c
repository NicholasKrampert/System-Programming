#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

int tail = 0;
int size = 0;

float* creatr_queue(){
  float * tmp = (float*)malloc(sizeof(float) * 1);
  size = 1;
  return tmp;
}

void enque(float num, float* arr){
  arr[tail] = num;
  tail++;
  test_queue(arr);
}

void test_queue(float* arr){
  if(tail == size){
    grow_x_2(&arr);
  }
}

void grow_x_2(float* *arr){
  float * tmp = (float*)malloc(sizeof(float) * (size * 2));

  int i;
  for (i = 0; i < size; i++){
    tmp[i] = ((*arr)[i]);
  }

  free(*arr);
  size = size * 2;
  *arr = tmp;
}

int queue_empty(float* arr){
  if(tail == 0)
    return 1;
  else
    return 0;
}

float deque(float* arr){
  float num = arr[0];
  arr[0] = 0;
  --tail;
  for(int i = 0; i < size; ++i){
    arr[i] = arr[i + 1];
  }
  test_half_full(arr);
  return num;
}

void test_half_full(float* arr){
  if(tail < (size / 2))
    half_size(&arr);
}

void half_size(float* *arr){
  float  * tmp = (float*)malloc(sizeof(float) * (size / 2));

  int i;
  for (i = 0; i < size / 2; ++i)
    tmp[i] = (*arr)[i];

  free(*arr);
  size = size / 2;
  *arr = tmp;
}
