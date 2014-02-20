//	kill.c, an implementation of a system call in C/
//	Man page: http://linux.die.net/man/2/kill

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int result = syscall (37, atoi(argv[1]), atoi(argv[2]));
    printf("%d\n", result);
    if (result == -1) {
    	printf("kill: %s: %s\n", argv[1], "Error killing process.");
  	}
}