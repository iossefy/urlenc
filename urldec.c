#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"
#include "doc.h"

#define NAME "urldec"

void urldec(char *s)
{

    size_t i;
    size_t size;

    char mod = '%';

    char tmp[4];

    size = strnlen(s, BUFFER_SIZE-1);

    /* hex delimter */
    tmp[0]='0';
    tmp[1]='x';

    /* printf("%c => %c",mod, s[0]); */

    long tmp_ret;

    for(i = 0; i < size; ++i){
	if (s[i] == mod){
	    /* printf("%c%c%c ", s[i], s[i+1], s[i+2]); */
	    tmp[2]=s[i+1];
	    tmp[3]=s[i+2];

	    tmp_ret = hextodecimal(tmp);
	    printf("%c", (int)tmp_ret);

	    memmove(s+i, s+i+2, strnlen(s, BUFFER_SIZE-1) - i+1);
	    /* memmove(s+i, s+i+3, strlen(s) - i+2); */

	} else {
	    printf("%c", s[i]);
	}
    }
}

int main(int argc, char **argv)
{

    bool in_file = false;
    char *filename = NULL;

    /* parse arguments */
    if (argc > 1) {
	size_t optind;
	for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
	    switch (argv[optind][1]) {
	    case 'i':
		in_file = true;
		if (optind + 1 > argc-1) {
		    fprintf(stderr, "no file input\n");
		    break;
		}

		if (check_fname_len(argv[optind+1]) == 0)
		    filename = argv[optind+1];
		break;
	    case 'h':
		help_dec(NAME);
		break;
	    }
	}
    }

    char *buffer;
    int err = 0;

    if (in_file) {
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	err = prepare_read(&buffer, BUFFER_SIZE, filename);
	handle_readall_errors(err);
	if (err != 0)
	    return err;
    } else
	buffer = stdin_recv(BUFFER_SIZE);


    if(buffer == NULL){
	free(buffer);
	return 1;
    }

    urldec(buffer);
    free(buffer);

    if (!in_file)
	printf("\n");

    return 0;
}
