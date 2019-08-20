#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	while ((read = getline(&line, &len, stdin)) != EOF)
		printf("Size of line: %u\n", (unsigned int)read);

	/*free(line);*/
	exit(EXIT_SUCCESS);
}
