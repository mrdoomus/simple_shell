#include "shell.h"

char *_getline(void)
{
	char *line = NULL;
	ssize_t len = 0;
	getline(&line, &len, stdin);

	return(line);
}
