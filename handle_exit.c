#include "shell.h"
/**
  * handle_exit - handle exit signal ctrl + C in the command line
  * @sig: parameter that repre signal received
  * Return: void
  */
void handle_exit(int sig)
{
	char *newline;

	(void)sig;
	/* print a new line for formatting when you ctrl + C */

	newline = "\n";
	write(STDOUT_FILENO, newline, _strlen(newline));
	/* terminate the program */
	exit(0);

}
