#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int result = syscall (37, atoi(argv[1]), atoi(argv[2]));
}