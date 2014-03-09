//  kill.c, an implementation of a system call in C.
//  Man page: http://linux.die.net/man/2/kill

//  Included by recommendation of man page.
#include <sys/types.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // JD: A quick null check with accompanying error message would have
    //     been nice here, to remind the user that your version of kill
    //     also requires the signal.
    int result = syscall (37, atoi(argv[1]), atoi(argv[2]));
    
    //  If result is equal to -1, man says this is an error.
    //  Therefore, we output an error message.
    if (result == -1) {
        printf("kill: %s: %s\n", argv[1], "Error killing process.");
    }
}