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
       char **args;
       int i = 0;
       char *token;

/*      Do malloc to allocate the necesary memory to char**  */
	args = (char **)malloc(sizeof(char) * 1024);
/*      If malloc cant allocate memory just return NULL   */
	if (args == NULL)
		return (NULL);
/*      Do if the arguments is not NULL */
	if (line_buf == NULL)
		return (NULL);
        token = strtok(line_buf, " \n\t");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	args[i] = NULL;
	return (args);
}
