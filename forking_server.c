#include "pipe_networking.h"
#include <signal.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

// currently just his previous main he showed on the board
int main(){
  signal(SIGINT, sighandler);

  int to_client;
  int from_client;
  from_client = server_setup();
  printf("%d\n", from_client);
  char buffer[BUFFER_SIZE];
  
  return 0;
}


void subserver(int from_client) {
  
}

void process(char * s) {
  s[0] = 'B';
}
