//  open.c, an implementation of a system call in C.
//  Man page: http://linux.die.net/man/3/open

#include <sys/stat.h> // was listed on man page, testing to see if necessary.
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    
    int result = syscall (5, argv[1], argv[2]);
    
}