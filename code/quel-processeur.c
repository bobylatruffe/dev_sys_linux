#define _GNU_SOURCE
#include<sched.h>
#include<limits.h>
#include<stdio.h>

int main(void) {
  int cpu;

  for(int i=0; i<INT_MAX; i++) {
    cpu = sched_getcpu();
    printf("%d\n", cpu);
  }
  

  return 0;
}
