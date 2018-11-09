#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


static void signalhandler (int signalNumber) {
    if (signalNumber == SIGINT) {
      printf("Quitting the program due to SIGINT\n");
      exit(0);
    } else if (signalNumber == SIGUSR1) {
      printf("This is my parent id: %d\n", getppid());
    }
}

int main () {
  signal(SIGINT, signalhandler);
  signal(SIGUSR1, signalhandler);
  while (1) {
    printf("This is my id: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
