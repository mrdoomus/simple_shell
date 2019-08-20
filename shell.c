#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status;
	int i = 0;

	do {
		i = 0;
		write(STDOUT_FILENO, "$ ", 2);
		line = _getline();
		args = _splitline(line);
		status = _execute(args);
		while (args[i])
		{
			printf("%s\n", args[i]);
			i++;
		}

		free(line);
		free(args);
	} while (status);

	return (0);
}
