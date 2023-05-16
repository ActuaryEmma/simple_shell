#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"
void _fork(char *buff)
{
	/* child process ID */
	pid_t pid;;

	/* command to be executed by the child process */
	char *argv[] = {"/bin/ls", NULL};

	/* loop continous until the user enters exit command */
	if (strcmp(buff, "/bin/ls") == 0)
		{
			pid = fork();

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
				wait(NULL);
			}
		}
		else
		{
			printf("./shell: No such filr or directory\n");
		}
}
