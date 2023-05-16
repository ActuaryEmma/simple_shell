#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"
/**
  * _getline - display a prompt that a user input
  * getline - read a line of input from the user and store it in the buff
  * Return: buff on success
  */
char *_getline()
{
	ssize_t buffer;
	/*buff store user input */
	char *buff = NULL;

	size_t n = 0;

	/* prompt displayed to the user */
	printf("#cisfun$ ");
	/**
	 * buff store the address of the buffer
	 * stdin : read a line of text from the standard input (keyboard) \
	 and store it in the buffer buff.
	 */
	buffer = getline(&buff, &n, stdin);
	/* check for error */
	if (buffer == -1)
	{
		free(buff);
		exit(1);
	}
	/* remove the newline at the end line and replaces it with \0*/
	buff[strcspn(buff, "\n")] = '\0';
	return (buff);
}
