#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
  int tube[2] = {0};
  char buffer_out[256] = "bonjour";
  char buffer_int[256]  = {0};
  
  assert(pipe(tube) == 0);

  switch(fork()) {
  case -1:
    perror("fork()");
    exit(EXIT_FAILURE);
    break; // pas besoin, nan ?
  case 0:
    close(tube[1]);
    assert(read(tube[0], buffer_int, 256) == 256);
    printf("Dans le fils : %s\n", buffer_int);
    break;
  default:
    close(tube[0]);
    assert(write(tube[1], buffer_out, 256) == 256);
    puts("Dans le père : j'ai écrit dans le tube");
    break;
  }
  
  return 0;
}
