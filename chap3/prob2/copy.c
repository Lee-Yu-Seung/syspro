#include <stdio.h>

void copy(char from[], char to[]){
	int i;
	i = 0;
	printf("longest line!\n");
	while((to[i] = from[i]) != '\0')
		++i;
}
