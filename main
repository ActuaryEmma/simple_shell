#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
/**
  * main - main entry
  * Return: 0 on success
  */
int main(void)
{
	char *newline;
	/* invoke handle_exit function when Ctrl + c is received */
	signal(SIGINT, handle_exit);
	/* store user input */

	/* loop runs until loop breaks */
	while (1)
	{
		char *buff;

		buff = _getline();

		if (buff == NULL)
		{
			newline = "\n";
			write(STDOUT_FILENO, newline, _strlen(newline));
			break;
		}
		if (_strcmp(buff, "env") == 0)
		{
			print_env();
			free(buff);
			continue;
		}
		else if (_strcmp(buff, "exit") == 0)
		{
			/* release the memory */
			free(buff);
			/*break the loop */
			exit(0);
		}
		_fork(buff);
		free(buff);
	}
	return (0);
}
