#include "shell.h"

char *_pathfinderTest(char *command)
{
	int i = 0, j = 0;
	char *env;
	char *token;
	char *file;
	char *aux;
	int size = 0;
	char *auxcat;
	char *auxtok;

	aux = malloc(sizeof(char) * 1024);
	if (aux == NULL)
	return (NULL);

	auxtok = malloc(sizeof(char) * 1024);
	if (auxtok == NULL)
		return (NULL);

	env = malloc(sizeof(char) * 1024);
	if (env == NULL)
		return (NULL);

	file = malloc(sizeof(char) * 1024);
	if (file == NULL)
		return (NULL);
	auxcat  = malloc(sizeof(char) * 1024);
	if (auxcat == NULL)
		return (NULL);

	while (environ[i])
	{
	        env = _strstr(environ[i], "PATH=");
		if (env != NULL)
		{
			aux = _strcpy(aux, env);
			break;
		}
		i++;
	}
	aux = aux + 5;
	token = strtok(aux, ":\n\r");
	while (token != NULL)
	{
		auxcat = _strcpy(auxcat, token);
		auxcat = _strcat(auxcat, "/");
	       	file = _strcat(auxcat, command);
		if (access(file, F_OK) != -1)
			auxtok = _strcpy(auxtok, file);
		token = strtok(NULL, ":\n\r");
	}
/*	printf("%s\n", auxtok);
	free(file);
	printf("free file\n");
//	free(auxcat);
//	printf("free auxcarn\n");
	free(token);
	printf("free token\n");
	free(aux);
	printf("free aux\n");
	free(env);
	printf("free env\n");
*///	printf("%s\n", auxtok);

return (auxtok);
}
