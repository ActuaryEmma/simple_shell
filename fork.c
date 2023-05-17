#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
  * _fork - create a child process takes no arguments
  * @buff: pointer to the input by the user
  * Return: void
  */
void _fork(char *buff)
{
	/* child process ID */
	pid_t pid;
	char *args[1024];
	int i = 0;
	char *delim = " ";
	char *token;

	/* strtok split buff into tokens separated by spaces */
	token = strtok(buff, delim);

	while (token != NULL)
	{
		args[i++] = token;
		/* update to next token */
		token = strtok(NULL, delim);
	}
	args[i] = NULL;

	/*create a new child process */
	pid = fork();

	/*checks for error */
	if (pid == -1)
	{
		perror("error\n");
		exit(1);
	}
	else if (pid == 0)
	{
		/* on success execve does not return */
		if (execvp(args[0], args) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		/* parent process is executed after cild terminates*/
		wait(NULL);
	}
}
