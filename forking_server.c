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
	signal(SIGNIT, sighandler);

	int to_client;
	int from_client;
	char buffer[BUFFER_SIZE];

	while (1){
		from_client = server_handshake(&to_client);
	   while (read(from_client, buffer, sizeof(buffer))){//this can be a wrapped function for the subserver
		printf("received: [%s] \n", buffer);
		process(buffer);
		write(to_client, buffer, sizeof(buffer));
	   }
	}
	return 0;

}


void subserver(int from_client) {
}

void process(char * s) {
  s[0] = 'B'
}
