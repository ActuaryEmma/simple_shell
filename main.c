#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(void)
{
	signal(SIGINT, handle_exit);
	char *buff;

	while (1)
	{
		buff = _getline();

		if (buff == NULL)
		{
			printf("\n");
			break;
		}
		_fork(buff);
		free(buff);
	}
	return (0);
}

