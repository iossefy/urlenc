#include <stdio.h>
#include <stdlib.h>


char *stdin_recv(size_t buffsz)
{
 /* i know that sizeof(char) is 1. C sometimes treats chars as inegers.
    https://stackoverflow.com/questions/2172943/size-of-character-a-in-c-c */
    char *buffer = (char *)malloc(sizeof(char) * buffsz);

	size_t i = 0;
	register int cr;

	do {
		if ((cr = getchar()) == '\0' || cr == 0 || cr == EOF) /* if you have a better solution... */
			break;

		buffer[i] = cr;

	} while(++i != buffsz);

	if (i != buffsz) {
		buffer[i-1] = 0;
		return buffer; /* must free after use */
	} else {
		/* Buffer overflow detected */
		return NULL;
	}
}

long hextodecimal(char *sbase16)
{
    return strtol(sbase16, NULL, 16);
}
