#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	/*parent procss ID */
	pid_t ppid;
	/* child process ID */
	pid_t pid;
	/*buff store user input */
	char *buff = *lineptr;

	/* command to be executed by the child process */
	char *argv[] = {"/bin/ls", NULL};

	/* loop continous until the user enters exit command */
	while (1)
	{
		/* prompt displayed to the user */
		printf("#cisfun$ ");
		/**
		  * buff store the address of the buffer
		  * stdin : read a line of text from the standard input (keyboard) and store it in the buffer buff.
		  */

		getline(&buff, n, stdin);

		/* remove the newline at the end line and replaces it with \0*/
		buff[strcspn(buff, "\n")] = '\0';
		/* if input is /bin/ls,, a child process is created  and execute the command specified in argv using execve system call */
		if (strcmp(buff, "/bin/ls") == 0)
		{
			pid = fork();

			if (pid == -1)
			{
				perror("error\n");
				return (1);
			}
			else if (pid == 0)
			{
				/* on success execve does not return */
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error:");
					return (1);
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
	return (0);
}
