#include "shell.h"

/**
  * _strcspn - calculate the length of *str 
  * @str: pointer to the string to be searched for
  * @reject : pointer to teh character to be rejected
  * Return: count
  */
size_t _strcspn(char *str, char *reject)
{
    size_t count = 0;
    char *ptr;

    for (; *str != '\0'; str++)
    {
        for (ptr = reject; *ptr != '\0'; ptr++)
        {
            if (*str == *ptr)
            {
                return count;
            }
        }
        count++;
    }

    return count;
}

