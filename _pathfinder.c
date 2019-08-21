#include "shell.h"
#include <string.h>
/**
 *_strcpy - program thisgs
 *Result: always return 0
 *@dest: variable de entrada
 *@src: entrada source
 *Return: value depending on function
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *_pathfinder(char *command)
{
	int i = 0;
	char *env;
	char *token;
	char *file;
	char *aux;
	int size = 0;
	char *auxcat;
	char *auxtok;

	aux = malloc(sizeof(char) * 1024);
	if (file == NULL)
		return (NULL);

	auxtok = malloc(sizeof(char) * 1024);
	if (file == NULL)
		return (NULL);


	env = malloc(sizeof(char) * 1024);
	if (env == NULL)
		return (NULL);

	file = malloc(sizeof(char) * 1024);
	if (file == NULL)
		return (NULL);
	auxcat  = malloc(sizeof(char) * 1024);
	if (file == NULL)
		return (NULL);

	while (environ[i])
	{
	        env = strstr(environ[i], "PATH=");
		if (env != NULL)
		{
			aux = strcpy(aux, env);
			break;
		}
		i++;
	}
	aux = aux + 5;
	token = strtok(aux, ":\n\r");
	while (token != NULL)
	{
		auxcat = strcpy(auxcat, token);
		auxcat = strcat(auxcat, "/");
	       	file = strcat(auxcat, command);
		if (access(file, F_OK) != -1)
			auxtok = strcpy(auxtok, file);
		token = strtok(NULL, ":\n\r");
	}
	printf("%s\n", auxtok);
/*	free(env);
	free(token);
	free(auxcat);
//	free(aux);
	free(file);
	printf("%s\n", auxtok);
*/
return (auxtok);
}

int main(void)
{
	char *path;
	char command[] = "ls";

	path = _pathfinder(command);
//	printf("%s\n", path);
	free (path);
	return (0);
}
