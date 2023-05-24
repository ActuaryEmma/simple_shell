#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *_getline();
void _fork(char *buff);
void handle_exit(int sig);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
size_t _strcspn(char *str, char *reject);
char *_getline_a();
void print_env();
#endif
