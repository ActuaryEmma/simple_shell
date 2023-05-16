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

	/* command to be executed by the child process */
	char *argv[] = {"/bin/ls", NULL};

	/* strcmp compare if input by user is equal to /bin/ls */
	if (strcmp(buff, "/bin/ls") == 0)
	{
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
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				exit(1);
			}
		}
		else
		{
			/* parent process is executed after cild terminates*/
			wait(NULL);
		}
	}
	else
	{
		/* if a command is not recognized or does not exist */
		printf("./shell: No such filr or directory\n");
	}
}
