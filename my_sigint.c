#include <stdio.h>
#include <signal.h>

void handle(int signal) {
	printf("Signal %d empfangen!\n", signal);
}

int main() {
	signal(SIGINT, SIG_DFL);
	while(1);
	return 0;
}
