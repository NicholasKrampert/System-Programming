//Name: Nicholas Krampert
//includes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

//main
int main(int args, char* argv[])
{
  //creating vars
  char buf[400];
  char* str = (char*)malloc(sizeof(char) * 50);
  int boolin = 0;
  int status;
  char* dil = " ";

  //loop untill the user enters exit
  while(boolin == 0)
  {
    //getting the current working directory
    getcwd(buf, 400);

    printf("\n%s ? ", buf);
    scanf("%[^\n]%*c", str);

    //tokenize the string
    char* tstr = strtok(str, dil);

    //if the user enters exit it will exit the loop ant stop the program
    if(strcmp(tstr, "exit") == 0)
    {
      boolin = 1;
    }
    //if the user enters cd it will change the current directory
    else if(strcmp(tstr, "cd") == 0)
    {
      //get the directory name that they want to go to
      char* nstr = strtok(NULL, dil);
      chdir(nstr);
      printf("\n< changed the directory to %s >\n", nstr);
    }
    //else it will create a child to do what they entered
    else
    {
      //create child
      pid_t pid = fork();

      //child
      if(pid == 0)
      {
        //get the next part of the command
        char* nstr = strtok(NULL, dil);
        execlp(tstr, tstr, nstr, (char*)0);
        fflush(stdout);
      }
      else
      {
        //wait for child
        wait(&status);
        fflush(stdout);
      }
    }
  }
}
