#define _GNU_SOURCE

#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>


int main() {
  int fd = open("p-670.data", O_RDWR | O_CREAT);
  assert(fd > 0);
  close(STDOUT_FILENO);

  dup(fd);
  close(fd);
  
  execlp("ls", "ls", NULL);

  puts("bonour");

  fcloseall();
  return 0;
}
