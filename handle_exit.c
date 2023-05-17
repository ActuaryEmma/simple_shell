#include "shell.h"
/**
  * handle_exit - handle exit signal ctrl + C in the command line
  * @sig: parameter that repre signal received
  * Return: void
  */
void handle_exit(int sig)
{
	(void)sig;
	/* print a new line for formatting when you ctrl + C */
	printf("\n");
	/* terminate the program */
	exit(0);

}
