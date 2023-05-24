#include "shell.h"

/**
  * _strcmp - compare if two strings are equal
  * @s1: pointer to the first string
  * @s2: pointer to the second string
  * Return: less than, greater than zero . On success it returns 0
  */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
	}
	return (*s1 - *s2);
}

