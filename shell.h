#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
extern char **environ;
char **_splitline(char *line_buf);
char *_getline(void);
int _execute(char **args);
char *_strstr(char *haystack, char *needle);
char *_pathfinderTest(char *command);
//char *_pathfinder(char *command);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
#endif
