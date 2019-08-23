#include "shell.h"

char *_pathfinder(char *command)
{
	int i = 0, j = 0;
	char *envcpy = NULL, *token = NULL;
	char **tokens = NULL;

	tokens = (char**)malloc(sizeof(char*) * 1024);
	if (tokens == NULL)
		return (NULL);
	/*path = malloc(sizeof(char) * 1024);
	if (path == NULL)
	{
		free(tokens);
		return (NULL);
	}
	for (k = 0; k < 1024; k++)
		path[k] = '\0';*/
	while (environ[i])
	{
		if ((_strstr(environ[i], "PATH=") != NULL))
			break;
		i++;
	}
	envcpy = malloc(sizeof(char) * _strlen(environ[i]) + 1);
	if (envcpy == NULL)
		return (NULL);

	_strcpy(envcpy, environ[i]);
	token = strtok(envcpy, ":\n\r");
	while (token != NULL)
	{
		token = strtok(NULL, ":\n\r");
		tokens[j] = token;
		j++;
	}
	tokens[j] = NULL;
	j = 0;
	while (tokens[j] != NULL)
	{
	/*	_strcpy(pat, tokens[j]);
		printf("%s 1\n", tokens[j]);*/
		_strcat(tokens[j], "/");
		/*printf("%s 2\n", tokens[j]);*/
		command = _strcat(tokens[j], command);
		/*printf("%s 3\n", command);
		printf("%s 4\n", tokens[j]);*/
		if (access(command, F_OK) != -1)
			break;
		j++;
	}
	/*printf("%s 4\n", command);*/
	free(tokens);
	free(envcpy);
	/*Temporal	free(command);*/
return (command);
}
