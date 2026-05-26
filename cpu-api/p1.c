#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int getpid_int() {
  return (int) getpid();
}

int main(int argc, char* argv[]) {
  printf("hello (pid: %d)\n", getpid_int());

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }

  if (rc == 0) {
    printf("child (pid: %d)\n", getpid_int());
    return 0;
  }

  printf("parent of %d (pid: %d)\n", rc, getpid_int());
}

