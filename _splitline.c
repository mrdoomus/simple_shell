#include "shell.h"

/**
 * createArgs - split a char * into char **
 * @line_buf: pointer to be splited
 * Description: split a pointer to char
 * Return: double pointer with split pointer
 * for Holberton project
 */

char **_splitline(char *line_buf)
{
       char **args = NULL;
       int i = 0;
       /*int j = 0, k = 0;*/
       char *token = NULL;

       if (line_buf == NULL)
		return (NULL);
/*      Do malloc to allocate the necesary memory to char**  */
	args = (char **)malloc(sizeof(char**) * 1024);
/*      If malloc cant allocate memory just return NULL   */
	if (args == NULL)
		return (NULL);
/*	for (j = 0; j < 1024; j++)
		for (k = 0; k < 1024; k++)
			args[j][k] = '\0';
*/
/*      Do if the arguments is not NULL */
        token = strtok(line_buf, "\t\r\n ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, "\t\r\n ");
	}
	args[i] = NULL;
	free(token);
	return (args);
}
