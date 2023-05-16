#include <stdio.h>
#include <stdlib.h>
extern char **environ;

int _environ(int argc, char *argv[])
{
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
