#include "shell.h"

char *_pathfinder(char *command)
{
	int i = 0;
	char *env;
	char *token;

	env = malloc(sizeof(char) * 1024);
	if (env == NULL)
		return (NULL);

	while (environ[i])
	{
		if ((_strstr(environ[i], "PATH=") != NULL))
			break;
		i++;
	}
	token = strtok(environ[i], "=\n\r");
	while (token != NULL)
	{
		_strcpy(env, token);
		_strcat(env, "/");
	      	_strcat(env, command);
		if (access(env, F_OK) != -1)
			break;
		token = strtok(NULL, ":\n\r");
	}
return (env);
}
