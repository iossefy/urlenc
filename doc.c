#include <stdio.h>
#include <stdlib.h>
#include "doc.h"


void copyrights()
{
    printf("Copyright (c) 2019-2022 Youssef Hesham\n");
}


void help_enc(const char *name)
{
    printf("Usage: echo \"<data>\" | %s [<options>...]\n"
	   "Usage: %s -i [<FILE>]\n\n"
	   "URL encode FILE, or standard input to standard output.\n\n"
	   "<Options>\n"
	   "-a : ignore alphanumeric characters\n"
	   "-s : use + instead of %%20 when encoding spaces\n"
	   "-i : input file to encode (must be the last argument)\n"
	   "-h : display this help and exit\n\n", name, name);

    copyrights();
    exit(EXIT_SUCCESS);
}

void help_dec(const char *name)
{

    printf("Usage: echo \"<data>\" | %s\n"
	   "Usage: %s -i [<FILE>]\n\n"
	   "URL decode FILE, or standard input to standard output.\n\n"
	   "<Options>\n"
	   "-i : input file to decode (must be the last argument)\n"
	   "-h : display this help and exit\n\n", name, name);
    copyrights();
    exit(EXIT_SUCCESS);
}
