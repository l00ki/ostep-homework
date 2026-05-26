#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int getpid_int() {
  return (int) getpid();
}

int main(int argc, char* argv[]) {
  printf("hello (pid: %d)\n", getpid_int());

  int rc_fork = fork();

  if (rc_fork < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }

  if (rc_fork == 0) {
    printf("child (pid: %d)\n", getpid_int());
    return 0;
  }

  int rc_wait = wait(NULL);
  printf("parent of %d (rc_wait: %d, pid: %d)\n", rc_fork, rc_wait, getpid_int());
}

