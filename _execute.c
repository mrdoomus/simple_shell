#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int _execute(char **args, int *flag)
{
	pid_t pid;
	int status;
	int builtstatus = 0;

	if (args == NULL)
		return (1);
	if ((builtstatus = _builtins(args)) < 2)
		return (builtstatus);
	if ((_strstr(args[0], "bin/")) == NULL)
	{
		args[0] = _pathfinder(args[0]);
		*flag = 1;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("ERROR: Couldn't execute program");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("ERROR: Child couldn't be created");
	}
	else
	{
		wait(&status);
	}
	return (1);
}
