#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "util.h"
#include "doc.h"

#define NAME "urlenc"

void urlenc(char *s, bool plus, bool ignore_ascii)
{
    size_t size;
    size_t i;

    size = strnlen(s, BUFFER_SIZE-1);
    for(i = 0; i < size; i++) {
	if (plus && (char)s[i] == 0x20) {
	    printf("+");
	    continue;
	}

	if (ignore_ascii && isalnum(s[i])) {
	    printf("%c", s[i]);
	    continue;
	}
	/* do full conversion */
	printf("%%%02hhx", (char)s[i]);
    }
}

int main(int argc, char **argv)
{

    bool plus		= false; /* use + instead of %20 */
    bool ignore_ascii	= false; /* example: hello%20world */

    /* parse arguments */
    if (argc > 1) {
	size_t optind;
	for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
	    switch (argv[optind][1]) {
	    case 's': plus = true; break;
	    case 'a': ignore_ascii = true; break;
	    case 'h':
		help_enc(NAME);
		break;
	    }
	}
    }


    char *buffer = stdin_recv(BUFFER_SIZE);

    if(buffer == NULL){
	free(buffer);
	return 1;
    }

    urlenc(buffer, plus, ignore_ascii);
    free(buffer);
    printf("\n");

    return 0;
}
