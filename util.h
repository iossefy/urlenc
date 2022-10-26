#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>

#define BUFFER_SIZE 10000

char *stdin_recv(size_t buffsz);
long hextodecimal(char *sbase16);

#endif
