#include <stdio.h>
#include "util.h"

void urlenc(char *s)
{
    size_t size;
    int i;

    size = count(s);
    for(i=0; i<size; ++i) {
        printf("%%%02x", (char)s[i]);
    }

}

int main(int argc, char **argv)
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
