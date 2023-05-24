#include "shell.h"
/**
  * print_env - prints current environment variables
  * Return: void
  */
void print_env(void)
{
	int i = 0;
	char *env_var;
	char *newline;

	while (environ[i] != NULL)
	{

		env_var = environ[i];
		newline = "\n";

		/* print the variable */
		write(STDOUT_FILENO, env_var, _strlen(env_var));
		/* add a new line */
		write(STDOUT_FILENO, newline, _strlen(newline));
		i++;
	}
}

