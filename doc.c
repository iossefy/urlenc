#include <stdio.h>
#include <stdlib.h>
#include "doc.h"


void copyrights()
{
    printf("Copyright (c) 2019-2022 Youssef Hesham\n");
}

void version(const char *name)
{
    printf("%s version %s ( %s )\n", name, VERSION, HOMEPAGE);
    exit(EXIT_SUCCESS);
}

void help_enc(const char *name)
{
    printf("Usage: echo \"<data>\" | %s [<options>...]\n"
	   "Usage: %s [<options>...]\n\n"
	   "URL encode or decode FILE, or standard input, to standard output.\n\n"
	   "<Options>\n"
	   "-d : decode data\n"
	   "-a : ignore alphanumeric characters\n"
	   "-s : use + instead of %%20 when encoding spaces\n"
	   "-i : input file to encode (must be the last argument)\n"
	   "-v : print version number\n"
	   "-h : display this help and exit\n\n", name, name);

    copyrights();
    exit(EXIT_SUCCESS);
}
