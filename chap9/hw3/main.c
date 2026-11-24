#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    char line[1024];
    char *cmds[20];
    char *args[20];
    char *tok, *infile, *outfile, *p;
    int pid, status, fd, i, j, n, bg;

    while (1) {
        printf("[shell] ");
        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        n = 0;
        tok = strtok(line, ";\n");
        while (tok != NULL) {
            cmds[n++] = tok;
            tok = strtok(NULL, ";\n");
        }

        for (i = 0; i < n; i++) {
            bg = 0;
            p = strchr(cmds[i], '&');
            if (p != NULL) {
                *p = '\0';
                bg = 1;
            }

            j = 0;
            infile = NULL;
            outfile = NULL;
            tok = strtok(cmds[i], " \t");
            while (tok != NULL) {
                if (strcmp(tok, "<") == 0) {
                    infile = strtok(NULL, " \t");
                } else if (strcmp(tok, ">") == 0) {
                    outfile = strtok(NULL, " \t");
                } else {
                    args[j++] = tok;
                }
                tok = strtok(NULL, " \t");
            }
            args[j] = NULL;

            if (j == 0)
                continue;

            pid = fork();
            if (pid == 0) {
                if (infile != NULL) {
                    fd = open(infile, O_RDONLY);
                    dup2(fd, 0);
                    close(fd);
                }
                if (outfile != NULL) {
                    fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
                    dup2(fd, 1);
                    close(fd);
                }
                execvp(args[0], args);
                exit(1);
            } else {
                if (bg == 0) {
                    waitpid(pid, &status, 0);
                }
            }
        }
    }
    return 0;
}
