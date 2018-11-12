#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


static void signalhandler (int signalNumber) {
    if (signalNumber == SIGINT) {
      char message []= "Quitting the program due to SIGINT2";
      printf("%s\n", message);
      int file = open("errormsg.txt", O_CREAT | O_APPEND | O_WRONLY);
      write(file, message, strlen(message));
      close(file);
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
