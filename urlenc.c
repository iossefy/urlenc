#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "util.h"
#include "urldec.h"
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

    bool decode         = false; /* decode mode */
    bool plus           = false; /* use + instead of %20 */
    bool ignore_ascii   = false; /* example: hello%20world */
    bool in_file        = false;

    char *filename      = NULL;  /* read input file */

    /* parse arguments */
    if (argc > 1) {
	size_t optind;
	for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
	    switch (argv[optind][1]) {
	    case 's': plus = true; break;
	    case 'a': ignore_ascii = true; break;
	    case 'd': decode = true; break;
	    case 'i':
		in_file = true;
		if (optind + 1 > argc-1) {
		    fprintf(stderr, "no file input\n");
		    break;
		}

		if (check_fname_len(argv[optind+1]) == 0)
		    filename = argv[optind+1];
		break;
	    case 'v':
		version(NAME);
		break;
	    case 'h':
		help_enc(NAME);
		break;
	    default:
		fprintf(stderr, "%s: Unrecognised option '%s'\n"
			"try' %s -h' for more information\n",
			NAME, argv[optind], NAME);
		return 1;
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


    if (!decode)
	urlenc(buffer, plus, ignore_ascii);
    else
	urldec(buffer);

    free(buffer);

    if (!in_file)
	printf("\n");

    return err;
}
