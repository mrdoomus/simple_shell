#include "shell.h"

int _builtins(char **args)
{
	int i = 0;
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
		return (1);
	default:
		return (2);
	}
}
