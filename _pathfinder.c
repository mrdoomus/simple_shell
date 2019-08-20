#include "shell.h"

char *_pathfinder(char *command)
{
	int i = 0;
	char *env;
	char *token;
	char *file;

	env = malloc(sizeof(char) * 6);
	if (env == NULL)
		return (NULL);

	file = malloc(sizeof(char) * 1024);
	if (file == NULL)
		return (NULL);

	while (environ[i])
	{
		if ((env = _strstr(environ[i], "PATH=")) == "PATH=")
			break;
		i++;
	}
	token = strtok(environ[i], ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		file = _strcat(token, command);
		if (access(file, F_OK) != -1)
			break;
		token = strtok(NULL, ":");
	}
return (token);
}

int main(void)
{
	char *path;

	path = _pathfinder("ls");
	printf("%s\n", path);
	return (0);
}
