#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
char **createArgs(void)
{
       char *line_buf = NULL;
       size_t line_buf_size = 0;
       int line_count = 0;
       ssize_t line_size;
       char **args;
       int i = 0;
       char *token;

	args = (char **)malloc(sizeof(char) * 1024);
       write(STDOUT_FILENO, "$ ", 2);
       while((line_size = getline(&line_buf, &line_buf_size, stdin)) != EOF)
       {
               if (line_buf != NULL)
               {
                       token = strtok(line_buf, " ");
                       while (token != NULL)
                       {
                               args[i] = token;
                               //printf("%s\n%s\n", token, args[i]);
				i++;
                               token = strtok(NULL, " ");
                       }
                       args[i] = NULL;
               }
		break;
               write(STDOUT_FILENO, "$ ", 2);
       }
       //free(line_buf);
       return (args);
}
int main(void)
{
       char **args;
       int i = 0;
       args = createArgs();
       while (args[i])
       {
               printf("%s\n", args[i]);
               i++;
       }
}
