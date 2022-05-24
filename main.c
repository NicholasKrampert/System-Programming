#include<stdio.h>
#include<stdlib.h>

int factor_power(int num){
  printf("%d = ", num);
  int d = 2;
  while(d <= num){
    if(num % d == 0){
      int pod = 0;
      do{
        ++pod;
        num /= d;
      }while(num % d == 0);
      printf("%d^%d ", d, pod);
      if(d <= num){
        printf("* ");
      }
    }
    ++d;
  }
  return 0;
}

int main(int args, char* argv[]){
  int num = 0;
  do{
    printf("Enter a integer (> 1): ");
    scanf("%d", &num);
  }while(num < 1);
  factor_power(num);
  printf("\n");
  return 0;
}
