#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 257

int my_pipe(int fd[2]); // prototype is given

int main(int args, char* argv[])
{
  printf("\n");
  // buffer used for pipe reads and writes
  char buffer[BUFFER_SIZE];

  // create an array of two file descriptors
  // for use with pipe() [0] - read, [1] - write
  int pipe_fds[2];

  // create a pipe - must be done before fork()
  // so that the read and write descriptors are
  // avialable to both parent and child
  int psts; // holds result of pipe creation attempt

  psts = pipe(pipe_fds); // You must write its definition

  if ( psts == 0 ) // pipe sucess
  {
    pid_t pid = fork(); // create child process
    if ( pid > 0 ) // parent process
    {
      printf("I am the parent-reciever\n");
      close(pipe_fds[1]); // will not send

      // wait - read message from child when it arives
      read(pipe_fds[0], buffer, BUFFER_SIZE);
      // echo message to the screen
      printf("I just recieved a message from my child :\n\t");
      printf("%s", buffer);

      close(pipe_fds[0]); // done listening to child
    }
    else if ( pid == 0 ) // child process
    {
      printf("I am the child-sender\n");
      close(pipe_fds[0]); // will not recieve

      // create the message "Im alive and doing fine!"
      strcpy(buffer, "Im alive and doing fine!");
      // send the message back to parent
      write(pipe_fds[1], buffer, strlen(buffer) + 1);

      close(pipe_fds[1]); // done talking back to parent
    }
    else // ( pid == -1 ) ->  fork failed
    {
      printf("Fork Error!\n");
      exit(2);
    }
  }
  else // ( psts == -1 ) -> pipe failed
  {
    printf("Pipe Error!\n");
    exit(1);
  }

  printf("\n");
  return 0;
}

int my_pipe(int fd[2]) {
  struct sockaddr name0 = {AF_UNIX, "Aaron"};
  struct sockaddr name1 = {AF_UNIX, "Max"};
  struct sockaddr name3 = {AF_UNIX, "Sophia"};
  //There is a problem with the copy because of the different lengths of names

  socklen_t namelen0 = sizeof(struct sockaddr) + 6;
  socklen_t namelen1 = sizeof(struct sockaddr) + 4;
  socklen_t namelen3 = sizeof(struct sockaddr) + 7;

  int s0, s1, s2;

  //create socket s0
  s0 = socket(AF_UNIX, SOCK_STREAM, 0);
  if(s0 == -1)
    return -1;

  //create socket s1
  s1 = socket(AF_UNIX, SOCK_STREAM, 0);
  if(s1 == -1)
    return -1;

  //bind sockets to names
  bind(s0, &name0, namelen0);
  bind(s1, &name1, namelen1);

  //copy s1's properties into name2 + namelen2
  getsockname(s1, &name3, &namelen3);
  //print to make sure it copied
  printf("Socket name = %s (%d)\n\n", name3.sa_data, namelen3);

  //set s1 to listen
  if ( listen(s1, 1) == -1 )
  {
    printf("listen() fail\n");
    return -1;
  }

  printf("%s (%d) is listening for connection requests\n\n", name1.sa_data, namelen1);

  //try to connet s0 to s1
  if(connect(s0, &name1, namelen1) == -1)
  {
    printf("connect() fail\n");
    return -1;
  }
  printf("%s (%d) is requesting a connection", name0.sa_data, namelen0);
  printf(" to %s (%d)\n\n", name3.sa_data, namelen3);

  //accept connection request from s0
  //s2 is a new socket with s1's properties connected to s0
  // s1 no longer needed
  if((s2 = accept(s1, &name3, &namelen3)) == -1)
  {
    printf("accept() fail\n");
    return -1;
  }
  else
  {
    printf("%s (%d) has accepted a connection request", name1.sa_data, namelen1);
    printf(" from %s (%d)\n\n", name3.sa_data, namelen3);
    close(s1);
  }

  //return socket pair
  fd[0] = s0; //for reads
  fd[1] = s2; // for writes

  //remove names for re-use
  unlink("Aaron");
  unlink("Max");

  return 0;
} // definition here

