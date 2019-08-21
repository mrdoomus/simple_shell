#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status = 1;
	int j = 0;

	do {
		j = 0;
		write(STDOUT_FILENO, "$ ", 2);;
		line = _getline();
		args = _splitline(line);
		if (args[0] != NULL)
			status = _execute(args, &j);
		free(line);
		if (j == 1)
			free(args[0]);
		free(args);
	} while (status);

	return (0);
}
