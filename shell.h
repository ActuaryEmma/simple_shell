#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void handle_exit(int sig);

#endif
