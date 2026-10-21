#include <stdio.h>
#define MAXLINE 100
void copy(char from[], char to[]);

void copy(char from[], char to[]){
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
