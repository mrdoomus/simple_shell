#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
extern char **environ;
char **_splitline(char *line_buf);
char *_getline(void);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int _execute(char **args, int *flag, int mode);
char *_pathfinder(char *command, int mode);
char *_catpath(char **uncatpath, char *command);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _builtins(char **args);
void _cd(char **args);
void _env(void);
int _strcmp(char *s1, char *s2);
int _strcmp_path(char *s1, char *s2);
void _nonintmode(char *line, char **args);
int _strcspn(char *s, const char *delim);
int _strspn(char *s, const char *delim);
char *_strtok_r(char *s, const char *delim, char **save_str);
char *_strtok(char *s, const char *delim);
#endif
