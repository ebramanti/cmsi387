#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS_LENGTH 256
#define DELIMITER "\x20\n"
#define WAIT_CHARACTER "&"
#define SHELL_INDICATOR "$ "

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */

int parseCommand(char* command, char* args[]) {
    // Loop help found from: http://stackoverflow.com/questions/3889992/how-does-strtok-split-the-string-into-tokens-in-c/3890186#3890186
    int i = 0;
    char* a;
    for (a = strtok(command, DELIMITER); a != NULL; a = strtok(NULL, DELIMITER)) {
        args[i] = a;
        i++;
    }
    args[i] = '\0';
}

int main() {
    /* String to hold the command to run. */
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS_LENGTH];
    printf("CUSTOM SHELL => Enter the command to run:\n");

    while(!feof(stdin)) {
        fputs(SHELL_INDICATOR, stdout);
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        // Terminating null for end of command.
        command[strlen(command) - 1] = '\0';
        int commandLength = strlen(command);

        if (commandLength > 0) {
            // Delete trailing whitespace.
            while(strcmp(&command[commandLength - 2], DELIMITER) == 0) {
                command[commandLength - 2] = '\0';
                commandLength--;
            }
            // A check for the concurrency command.
            int waitCheck = 0;
            while(strcmp(&command[commandLength - 2], WAIT_CHARACTER) == 0) {
                command[commandLength - 2] = '\0';
                waitCheck = 1;
            }

            parseCommand(command, args);
            if (strcmp(args[0], "exit") == 0) {
                return; // Exit the shell.
            } else if (strcmp(args[0], "cd") == 0) {
                //http://www.tutorialspoint.com/unix_system_calls/chdir.htm
                chdir(args[1]);
            } else if (strcmp(args[0], "secret-system-call") == 0) {
                // Since my kernel was designed for a phone, this will just print a message.
                // An example of what I would call is shown below.
                // syscall(378);
                char* androidMessage = "This would normally print my secret system call on a Nexus 4 running my custom-built Android kernel.\n";
                fputs(androidMessage, stdout);
            } else {
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
                    execvp(args[0], args);
                } else {
                    /* Parent process. */
                    int result;
                    //  Do not stop process if wait command is used.
                    if (!waitCheck) {
                        wait(&result);
                    }
                }
            }
        }
    }

    return 0;
}
