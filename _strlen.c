#include "shell.h"
/**
  * _strlen - find the size of a string
  * @s: pointer to the string to find the length
  * Return: size of the string
  */
size_t _strlen(char *s)
{
	int i;
	size_t count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		count++;
	}
	return (count);
}
