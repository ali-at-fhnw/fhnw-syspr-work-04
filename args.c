#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void printPID() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("PID = %d, parent PID = %d\n", pid, ppid);
}

int main(int argc, char *argv[]) {
    // check each arg, except program name
    for (int i = 1; i < argc; i++) {
        for (char *p = argv[i]; *p != '\0'; p++) {
            if (*p < 'a' || *p > 'z') {
                printf("error: args must contain [a-z]* only\n");
                return -1;
            }
        }
    }
	printPID();
    // print all args
    for (int i = 0; i < argc; i++) {
        printf("%d: %s\n", i, argv[i]);
    }
	while(1);
    return 0;
}
