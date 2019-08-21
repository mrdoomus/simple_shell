#include "shell.h"

char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;
	if ((getline(&line, &len, stdin)) != -1)
	{
		return (line);
	}

	return (NULL);
}
