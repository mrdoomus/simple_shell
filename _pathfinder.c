#include "shell.h"

char *_pathfinder(char *command)
{
	int i = 0;
	char *env, *envcpy, *token;

	env = malloc(sizeof(char) * 1024);
	if (env == NULL)
		return (NULL);

	while (environ[i])
	{
		if ((_strstr(environ[i], "PATH=") != NULL))
			break;
		i++;
	}
	envcpy = malloc(sizeof(char) * _strlen(environ[i]));
	if (envcpy == NULL)
		return (NULL);
	_strcpy(envcpy, environ[i]);
	token = strtok(envcpy, "=\n\r");
	while (token != NULL)
	{
		_strcpy(env, token);
		_strcat(env, "/");
		_strcat(env, command);
		if (access(env, F_OK) != -1)
			break;
		token = strtok(NULL, ":\n\r");
	}
	free(envcpy);
return (env);
}
