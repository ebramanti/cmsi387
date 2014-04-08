#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS_LENGTH 256
#define DELIMITER "\x20\n"

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */

int parseCommand(char* command, char* args) {

}

int main() {
    /* String to hold the command to run. */
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS_LENGTH];


    printf("Enter the command to run: ");

    while(!feof(stdin)) {
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        int commandLength = strlen(command);

        // Terminating null for end of command.
        command[commandLength - 1] = '\0';

        // Delete trailing whitespace.
        while(strcmp(&command[commandLength - 2], DELIMITER) == 0){
            command[commandLength - 2] = 0;
            commandLength--;
        }

        printf("%s\n", command);

        /* Variable that will store the fork result. */
        pid_t pid;

        /* Perform the actual fork. */
        pid = fork();
        if (pid < 0) {
            /* Error condition. */
            fprintf(stderr, "Fork failed\n");
            return -1;
        } else if (pid == 0) {
            /* Child process. */
            printf("Running...\n");
            args[0] = "ls";
            execvp(args[0], args);
        } else {
            /* Parent process. */
            int result;
            wait(&result);
            printf("All done; result = %d\n", result);
        }
    }

    return 0;
}
