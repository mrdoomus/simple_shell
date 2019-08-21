#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status;
	int i = 0, j = 0;

	do {
		i = 0;
		j = 0;
		write(STDOUT_FILENO, "$ ", 2);
		line = _getline();
		args = _splitline(line);
		status = _execute(args, &j);
		free(line);
		if (j == 1)
			free(args[0]);
		free(args);
	} while (status);

	return (0);
}
