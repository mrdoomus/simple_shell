#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int _execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{

		if (execve(args[0], args, NULL) == -1)
			perror("ERROR: Couldn't execute program");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("ERROR: Child couldn't be created");
	else
		wait(&status);
	return (1);
}
