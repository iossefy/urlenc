#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void urldec(char *s)
{

    size_t i;
    size_t size;
    char tmp[4];

    char mod = '%';

    size = strnlen(s, BUFFER_SIZE-1);

    int nm = 0;
    for (i = 0; i < size; ++i) {
	if(s[i] == mod)
	    nm++;
    }

    /* string size + ((% char + 2 hex chars) * num of %) + null byte */
    char buf[sizeof(char) * size + (3 * nm) + 1];

    for(i = 0; i < size; ++i){
	if (s[i] != mod) {
	    buf[i] = s[i];
	    continue;
	}

	tmp[0]=s[i+1];
	tmp[1]=s[i+2];

	buf[i] = (char)hextodecimal(tmp);

	memmove(s+i, s+i+2, size-i+1); /* BUG: NOT SAFE */

    }

    buf[i] = 0;
    printf("%s", buf);
}
