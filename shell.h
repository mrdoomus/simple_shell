#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
char **_splitline(char *line_buf);
char *_getline(void);
int _execute(char **args);
#endif
