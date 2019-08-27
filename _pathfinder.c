#include "shell.h"

/**
 *  _pathfinder - Searches the execution path of command.
 * @command: Command issued by the user
 * Return: Returns the unconcatenated path for execution
**/

char *_pathfinder(char *command, int mode)
{
	int i = 0, j = 0;
	char *completepath = NULL, *envcpy = NULL, *token = NULL;
	char **tokens = NULL;

	tokens = (char **)malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (NULL);

	while (environ[i])
	{
		if (_strcmp(environ[i], "PATH=") == 0)
			break;
		i++;
	}
	envcpy = malloc(sizeof(char) * _strlen(environ[i]) + 1);
	if (envcpy == NULL)
		return (NULL);

	_strcpy(envcpy, environ[i]);
	token = strtok(envcpy, "=\n\r");
	while (token != NULL)
	{
		token = strtok(NULL, ":\n\r");
		tokens[j] = token;
		j++;
	}

	completepath = _catpath(tokens, command);
	free(tokens);
	free(token);
	free(envcpy);
	if (mode == 0)
		free(command);

return (completepath);
}

/**
 *  _catpath - Concatenates path of command.
 * @uncatpath: Uncocatenated path
 * @command: Command issued by the user
 * Return: Returns the concatenated path for execution
**/
char *_catpath(char **uncatpath, char *command)
{
	int i = 0;
	char *path = NULL;

	path = malloc(sizeof(char) * 1024);
	if (path == NULL)
		return (NULL);

	for (i = 0; i < 1024; i++)
		path[i] = '\0';

	i = 0;
	while (uncatpath[i] != NULL)
	{
		_strcpy(path, uncatpath[i]);
		_strcat(path, "/");
		_strcat(path, command);
		if (access(path, F_OK & X_OK) != -1)
			break;
		i++;
	}
return (path);
}
