#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		write(STDOUT_FILENO, "$ ", 2);
		line = _getline();
		args = _splitline(line);
		status = _execute(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}
