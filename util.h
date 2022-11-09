#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10000
#define FILENAME_MAX_LENGTH 1024*2

/* Size of each input chunk to be
   read and allocate for. */
#ifndef  READALL_CHUNK
#define  READALL_CHUNK  262144
#endif

#define  READALL_OK          0  /* Success */
#define  READALL_INVALID    -1  /* Invalid parameters */
#define  READALL_ERROR      -2  /* Stream error */
#define  READALL_TOOMUCH    -3  /* Too much input */
#define  READALL_NOMEM      -4  /* Out of memory */

char *stdin_recv(size_t buffsz);
long hextodecimal(char *sbase16);

size_t check_fname_len(const char *fname);
int prepare_read(char **buff, size_t sz, char *filename);

int readall(FILE *in, char **dataptr, size_t *sizeptr);
void handle_readall_errors(int err);

#endif
