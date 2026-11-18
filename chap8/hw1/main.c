#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && argv[i+1][0] != '-') {
                char *ptr;
                
                ptr = getenv(argv[i+1]);
                if (ptr != NULL)
                    printf("%s = %s\n", argv[i+1], ptr);
                
                i++;
            } else {
                char **ptr;
                extern char **environ;

                for (ptr = environ; *ptr != 0; ptr++)
                    printf("%s\n", *ptr);
            }
        }
        else if (strcmp(argv[i], "-u") == 0) {
            struct passwd *pw = getpwuid(getuid());
            struct passwd *epw = getpwuid(geteuid());
            printf("My Realistic User ID : %d(%s)\n", getuid(), pw->pw_name);
            printf("My Valid User ID : %d(%s)\n", geteuid(), epw->pw_name);
        }
        else if (strcmp(argv[i], "-g") == 0) {
            struct group *gr = getgrgid(getgid());
            struct group *egr = getgrgid(getegid());
            printf("My Realistic Group ID : %d(%s)\n", getgid(), gr->gr_name);
            printf("My Valid Group ID : %d(%s)\n", getegid(), egr->gr_name);
        }
        else if (strcmp(argv[i], "-i") == 0) {
            printf("my process number : [%d]\n", getpid());
        }
        else if (strcmp(argv[i], "-p") == 0) {
            printf("my parent's process number : [%d]\n", getppid());
        }
    }

    exit(0);
}
