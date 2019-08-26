#include "shell.h"

/**
 * _execute - Executes the given command and certain flags
 * @args: The issued command
 * @flag: Flags out if the command was fully written or needs pathfinding
 * Return: Returns a status, 1 to continue and 0 to stop
**/
int _execute(char **args, int *flag)
{
	pid_t pid;
	int status;
	int builtstatus = 0;

	if (args == NULL)
		return (1);
	builtstatus = _builtins(args);
	if (builtstatus < 2)
		return (builtstatus);
	if (access(args[0], F_OK && X_OK) == -1)
	{
		args[0] = _pathfinder(args[0]);
		*flag = 1;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("ERROR: Couldn't execute program");
			free(args[0]);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("ERROR: Child couldn't be created");
	else
		wait(&status);
return (1);
}
