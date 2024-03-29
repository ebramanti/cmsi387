//  open.c, an implementation of a system call in C.
//  Man page: http://linux.die.net/man/3/open

//  Included header files listed on man page.
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // JD: A quick null check with accompanying error message would have
    //     been nice here, to remind me that your version of open also
    //     requires the mode (i.e., it does not default to a specific one).
    int result = syscall (5, argv[1], atoi(argv[2]));
    // JD: This is technically correct, though in the end is not the best choice
    //     because open does not do much by itself.  Ultimately this is more
    //     useful in tandem with other related system calls.

    //  If result is -1, an error message is thrown.
    if (result == -1) {
        printf("open: %s: %s\n", argv[1], "Error opening path.");
    }
}