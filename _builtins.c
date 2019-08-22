#include "shell.h"

int _builtins(char **args)
{
	int i = 0, j = 0, k = 0;
	char *builts[] = {"exit", "cd", "help", "env"};

	while (builts[i])
	{
		if (strcmp(args[0], builts[i] ) == 0)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		return (0);
	case 1:
		return (1);
	case 2:
		return (1);
	case 3:
		while (*environ[j])
		{
			k = _strlen(environ[j]);
			write(STDOUT_FILENO, environ[j], k);
			write(STDOUT_FILENO, "\n", 1);
			j++;
		}
		return (1);
	default:
		return (2);
	}
}
