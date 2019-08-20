#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "Camilo/Villegas";
	char *token = strtok(str, "/");
	
	while (token != NULL)
	{
		printf ("%s\n", token);
		token = strtok(NULL, "/");
	}

exit(EXIT_SUCCESS);
}
