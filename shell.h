#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getline();
void _fork(char *buff);
void handle_exit(int sig);

#endif
