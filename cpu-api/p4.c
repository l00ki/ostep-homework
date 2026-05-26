#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int getpid_int() {
  return (int) getpid();
}

int main(int argc, char* argv[]) {
  int rc_fork = fork();

  if (rc_fork < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }

  if (rc_fork != 0) {
    wait(NULL);
    return 0;
  }

  close(STDOUT_FILENO);
  open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

  char* argv_wc[3];
  argv_wc[0] = strdup("wc");
  argv_wc[1] = strdup("p4.c");
  argv_wc[2] = NULL;

  execvp(argv_wc[0], argv_wc);

  return 1;
}
