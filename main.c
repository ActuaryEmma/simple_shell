#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"

int main(void)
{
    signal(SIGINT, handle_exit);
    char *buff = NULL;
    size_t *n;
    _getline(&buff, n, stdin);
    free(buff);
    return (0);
}
