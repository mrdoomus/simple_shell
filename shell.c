#include "shell.h"
void handler(int error)
{
	switch(error)
	{
		/*SIGINT*/
	case 2:
		write(1, "\n", 1);
		write(STDOUT_FILENO, "$ ", 2);
		break;
		/*NO COMMAND*/
	default:
		write(2, "Issued command \n", 15);
		break;
	}
}

int main(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;
	int j = 0;

	signal(SIGINT, handler);

/*	if (isatty(STDIN_FILENO) != 1)
	{
		line = _getline();
		if (line == NULL)
			return (0);
		args = _splitline(line);
		if (args[0] != NULL)
			status =_execute(args, &j);
		if (status == 0)
			free(line);
		if (j == 1)
			free(args[0]);
		free(args);
		return (status);
	}
*/	do {
		j = 0;
		write(STDOUT_FILENO, "$ ", 2);
		line = _getline();
		if (line == NULL)
			break;
		args = _splitline(line);
		if (args[0] != NULL)
			status = _execute(args, &j);
		if (status == 0)
			free(line);
		if (j == 1)
			free(args[0]);
		free(args);
	} while (status);

	return (0);
}
