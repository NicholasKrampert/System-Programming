

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int args, char* argv[])
{
  printf("\n");

  DIR* dirp; // type used for a directory stream
  dirp = opendir("."); // try to open the current working directory
  if ( dirp == NULL )
  {
    printf("\ndir open error\n");
    exit(1);
  }
  else
  {
    struct stat fst; // needed to hold file stats – must be allocated (or local var)
    struct dirent* dentry; // a pointer to an “internal” structure
    dentry = readdir(dirp); // no allocation needed, unless we need to save each one
    while ( dentry != NULL ) // if the dir entry is non NULL use it
    {

      // Your Work Here …
      printf("ino = %d\n", dentry->d_ino);
      printf("name = %s\n", dentry->d_name);
      if(!stat(dentry->d_name, &fst))
      {
        if(S_ISDIR(fst.st_mode))
        {
          printf("\t\t- Directory size = %o\n", fst.st_mode);
        }
        else if(S_ISREG(fst.st_mode))
        {
          printf("\t\t- File size = %o\n", fst.st_mode);
        }
      }
      printf("\n");
      dentry = readdir(dirp); // get the “next” entry
    }

    closedir(dirp); // close the directory
  }

  printf("\n");
  return 0;
}

