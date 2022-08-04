#include <stdio.h>
#include "util.h"

void urlenc(char *s)
{
    size_t size;
    size_t i;

    size = count(s);
    for(i=0; i<size; ++i) {
        printf("%%%02hhx", (char)s[i]);
    }

}

int main()
{
    char *buffer = stdin_recv(BUFFER_SIZE);

    if(buffer == NULL){
        free(buffer);
        return 1;
    }

    urlenc(buffer);

    free(buffer);

    printf("\n");

    return 0;
}
