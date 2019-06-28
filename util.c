#include <stdio.h>
#include <stdlib.h>

/*
 * count how many characters are there
 * i know strlen() and strnlen() exists but
 * i will do it manually anyway
 * */
size_t count(char *s)
{
    size_t count = 0;

    int i;
    for(i=0; s[i]; ++i)
        ++count;
    return count;
}

char *stdin_recv(size_t buffsz)
{
 /* i know that sizeof(char) is 1. C sometimes treats chars as inegers.
    https://stackoverflow.com/questions/2172943/size-of-character-a-in-c-c */
    char *buffer = (char *)malloc(sizeof(char) * buffsz);

	int i = 0;
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
