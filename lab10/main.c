
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int args, char* argv[])
{
  printf("\n");
  int num = 0;

  pid_t pid = fork(); // create child

  // your code goes here ...
  if(pid == 0)
  {
    printf("I am the child\n");
    num = 2;
    printf("cnum = %d\n", num);
    execlp("pwd", "pwd", (char*)0);
    fflush(stdout);
  }
  else if(pid > 0)
  {
    printf("I am the parent\n");
    num = 4;
    printf("pnum = %d", num);
    execlp("ls", "ls", "-l", (char*)0);
    fflush(stdout);
  }
  else
  {
    printf("Bad fork()");
    exit(1);
  }

  printf("\n");
  return 0;
}

