#include "shell.h"

char *_pathfinder(char *command)
{
	int i = 0, j = 0, k = 0;
	char *path = NULL, *envcpy = NULL, *token = NULL;
	char **tokens = NULL;

	tokens = (char**)malloc(sizeof(char*) * 1024);
	if (tokens == NULL)
		return (NULL);
	path = malloc(sizeof(char) * 1024);
	if (path == NULL)
	{
		free(tokens);
		return (NULL);
	}
	for (k = 0; k < 1024; k++)
		path[k] = '\0';
	while (environ[i])
	{
		if ((_strstr(environ[i], "PATH=") != NULL))
			break;
		i++;
	}
	envcpy = malloc(sizeof(char) * _strlen(environ[i]) + 1);
	if (envcpy == NULL)
	{
		free(path);
		return (NULL);
	}
	_strcpy(envcpy, environ[i]);
	token = strtok(envcpy, "=\n\r");
	while (token != NULL)
	{
		token = strtok(NULL, ":\n\r");
		tokens[j] = token;
		j++;
	}
	k = 0;
	while (tokens[k] != NULL)
	{
		_strcpy(path, tokens[k]);
		_strcat(path, "/");
		_strcat(path, command);
		if (access(path, F_OK) != -1)
			break;
		k++;
	}


	free(tokens);
	free(token);
	/*tokens = NULL;*/
	free(envcpy);
	envcpy = NULL;
	free(command);
	command = NULL;
return (path);
}
