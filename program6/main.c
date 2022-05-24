//includes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

//functions
void get_directory(int args, char* argv[]);
int get_number_display(DIR* searchD, int mSize, char* argv[]);

//main function
int main(int args, char* argv[])
{
  //call get_directory to get the directory that you want to look at and display the number of files
  get_directory(args, argv);
  return 0;
}

//get directory function
void get_directory(int args, char* argv[])
{
  //got mSize from file3ic.c
  int mSize = 1024;

  //return value from get_number_display
  int return_value;

  //if there is something in argv, args will not be 0
  if(args > 0)
  {
    int i = chdir(strdup(argv[1]));
    //get the first directory from argv
    DIR *searchD;
    searchD = opendir(".");

    //test if directory opened
    if(searchD == NULL)
    {
      printf("can not open directory\n");
      //because directory did not open close the program
      exit(1);
    }
    else
    {
      //call get_number_display to get the number of files and display the names and size
      return_value = get_number_display(searchD, mSize, argv);
      //print the number of files returned by get_number_display
      printf("\n%d Matching files in all\n", return_value);
    }
    i = chdir("..");
  }
}

//get number of files and display them
int get_number_display(DIR* searchD, int mSize, char* argv[])
{
  //value to be returned at end of function
  int return_value = 0;

  //get the first entry in searchD
  struct dirent* dentry;
  dentry = readdir(searchD);

  //file stats
  struct stat fst;

  //loop while there is still files to read
  while(dentry != NULL)
  {
    //get stats
    if(!stat(dentry->d_name, &fst))
    {
      //if it is a reg file
      if(S_ISREG(fst.st_mode))
      {
        //if it is bigger then mSize
        if(fst.st_mode >= mSize)
        {
          //print name and size to screen
          printf("./%s/%s, size = %d\n", strdup(argv[1]), dentry->d_name, fst.st_mode);
          //incrament counter of number of files
          ++return_value;
        }
      }
    }
    //open the next entry
    dentry = readdir(searchD);
  }
  return return_value;
}
