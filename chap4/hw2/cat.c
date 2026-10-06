#include <stdio.h>
#include <string.h>

void print_file(FILE *fp1, int n_flag, int *line) {
    int c;
    int new_line = 1;

    while ((c = fgetc(fp1)) != EOF) {
        if (n_flag == 1 && new_line == 1) {
            printf("%6d ", *line);
            (*line)++;
            new_line = 0;
        }
        putchar(c);
        if (c == '\n') {
            new_line = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    int n_flag = 0;
    int start = 1;
    int line = 1;
    FILE *fp1;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        n_flag = 1;
        start = 2;
    }

    if (start == argc) {
        print_file(stdin, n_flag, &line);
        return 0;
    }

    for (int i = start; i < argc; i++) {
        fp1 = fopen(argv[i], "r");
        if (fp1 == NULL) {
            continue;
        }
        print_file(fp1, n_flag, &line);
        fclose(fp1);
    }

    return 0;
}
