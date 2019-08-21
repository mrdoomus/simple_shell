#include "shell.h"

char *_getline(void)
{
	char *line = NULL;
	ssize_t len = 0;
	if (getline(&line, &len, stdin) != -1)
	{
		if(line == "\n")
			return (NULL);		
		return (line);
	}

	return (NULL);
}
