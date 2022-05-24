#include <stdlib.h>
#include <stdio.h>
#include "histo.h"
#include <math.h>
#include <string.h>

#define LETTERS 26

void init_histogram(int histo[]){
  int i = 0;
  while(i < LETTERS){
    histo[i] = 0;
    ++i;
  }
}

void cons_histogram(const char string[], int histo[]){
  int i = 0;
  while(string[i] != '\0'){//loop1 goes over the hole string
    int c = string[i];
    if(c >= 'a' && c <= 'z'){
      ++histo[c - 'a'];
      ++i;
    }
  }
}

void most_frequent(const int histo[], char* ret_val){
  int most = 0;
  int i = 0;
  char letter;
  while(i < LETTERS){
    if(histo[i] > most){
      most = histo[i];
      letter = (i + 'a');
    }
    ++i;
  }
  printf("%c occured most frequent\n", letter);
  ret_val = (char*)letter;
}

void display_histogram(int* const histo){
  char pointer;
  int i = 0;
  while(i < LETTERS){
    int hist = histo[i];
    if(hist > 0){
      if(hist > 1){
        printf("%c appeared %d times\n", i + 97, hist);
      }
      else{
        printf("%c appeared %d time\n", i + 97, hist);
      }
    }
    ++i;
  }
  most_frequent(histo, pointer);
}
