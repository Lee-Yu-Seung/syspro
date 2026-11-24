#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXARG 20

int main() {
    char line[1024];
    char *args[MAXARG];
    char *tok, *saveptr;
    int pid, child, status, i, bg;

    while (1) {
        printf("Pls input cmd : ");
        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        i = 0;
        bg = 0;
        tok = strtok_r(line, " \t\n", &saveptr);
        while (tok != NULL && i < MAXARG - 1) {
            args[i++] = tok;
            tok = strtok_r(NULL, " \t\n", &saveptr);
        }
        args[i] = NULL;

        if (i == 0)
            continue;

        if (strcmp(args[i - 1], "&") == 0) {
            bg = 1;
            args[i - 1] = NULL;
        } else if (args[i - 1][strlen(args[i - 1]) - 1] == '&') {
            bg = 1;
            args[i - 1][strlen(args[i - 1]) - 1] = '\0';
        }

        printf("[%d] Parent process start\n", getpid());

        pid = fork();
        if (pid == 0) {
            if (bg == 1) {
                printf("[%d] child process start\n", getpid());
            }
            execvp(args[0], &args[0]);
            exit(1);
        } else {
            child = wait(&status);
            if (status == 0) {
                if (bg == 1) {
                    printf("[%d] child process end %d\n", getpid(), child);
                }
                printf("SUCCESS\n\n");
            } else {
                printf("Parent process end\n");
                printf("Exit\n");
                break;
            }
        }
    }
    return 0;
}
