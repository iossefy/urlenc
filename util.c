#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#include "util.h"


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

/* check filename's length
   errors:
   0  : no errors returned
   -1 : filename length exceded

*/
size_t check_fname_len(const char *fname)
{
    if (strnlen(fname, FILENAME_MAX_LENGTH) == FILENAME_MAX_LENGTH)
	return -1;
    return 0;
}

/* This function returns one of the READALL_ constants above.
   If the return value is zero == READALL_OK, then:
   (*dataptr) points to a dynamically allocated buffer, with
   (*sizeptr) chars read from the file.
   The buffer is allocated for one extra char, which is NUL,
   and automatically appended after the data.
   Initial values of (*dataptr) and (*sizeptr) are ignored.
*/
int readall(FILE *in, char **dataptr, size_t *sizeptr)
{
    char  *data = NULL, *temp;
    size_t size = 0;
    size_t used = 0;
    size_t n;

    if (in == NULL || dataptr == NULL || sizeptr == NULL) {
        return READALL_INVALID;
    }

    /* A read error already occurred? */
    if (ferror(in)) {
        return READALL_ERROR;
    }

    while (1) {

        if (used + READALL_CHUNK + 1 > size) {
            size = used + READALL_CHUNK + 1;

            /* Overflow check. Some ANSI C compilers
               may optimize this away, though. */
            if (size <= used) {
                free(data);
                return READALL_TOOMUCH;
            }

            temp = realloc(data, size);
            if (temp == NULL) {
                free(data);
                return READALL_NOMEM;
            }
            data = temp;
        }

        n = fread(data + used, 1, READALL_CHUNK, in);
        if (n == 0)
            break;

        used += n;
    }

    if (ferror(in)) {
        free(data);
        return READALL_ERROR;
    }

    temp = realloc(data, used + 1);
    if (temp == NULL) {
        free(data);
        return READALL_NOMEM;
    }
    data = temp;
    data[used] = '\0';

    *dataptr = data;
    *sizeptr = used;

    return READALL_OK;
}


void handle_readall_errors(int err)
{
    switch (err) {
    case READALL_INVALID:
	fprintf(stderr, "error: invalid parameters\n");
	break;
    case READALL_ERROR:
	fprintf(stderr, "error: reading file\n");
	break;
    case READALL_NOMEM:
	fprintf(stderr, "error: out of memory\n");
	break;
    case READALL_TOOMUCH:
	fprintf(stderr, "error: overflow check");
	break;
    }
}


int prepare_read(char **buff, size_t sz, char *filename)
{
    FILE *f = fopen(filename, "rb");
    return readall(f, buff, &sz);
}
