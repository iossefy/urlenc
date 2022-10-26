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
	   "Usage: %s [<options>...]\n\n"
	   "URL encode standard input to standard output.\n\n"
	   "<Options>\n"
	   "-a : ignore alphanumeric characters\n"
	   "-s : use + instead of %%20 when encoding spaces\n"
	   "-h : display this help and exit\n\n", name, name);

    copyrights();
    exit(EXIT_SUCCESS);
}

void help_dec(const char *name)
{

  printf("Usage: echo \"<data>\" | %s\n"
         "Usage: %s [<options>...]\n\n"
	 "URL decode standard input to standard output.\n\n"
	 "<Options>\n"
         "-h : display this help and exit\n\n", name, name);
    copyrights();
    exit(EXIT_SUCCESS);
}
