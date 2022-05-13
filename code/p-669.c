#define _GNU_SOURCE

#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>


int main() {
  int fd = open("p-669.data", O_RDWR | O_CREAT);
  assert(fd > 0);
  close(STDOUT_FILENO);

  dup(fd);

  puts("bonour");

  fcloseall();
  return 0;
}
