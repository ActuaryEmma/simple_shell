#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

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
                return (count);
            }
        }
        count++;
    }
    return (count);
}

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

char *_getline()
{
    ssize_t buffer;

    char *commandPrompt;
    char *buff = NULL;
    size_t n = 0;

    if (isatty(STDIN_FILENO))
    {
        commandPrompt = "$ ";
        write(STDOUT_FILENO, commandPrompt, _strlen(commandPrompt));
        fflush(stdout);
    }

    buffer = getline(&buff, &n, stdin);

    if (buffer == -1)
    {
        free(buff);
        exit(1);
    }

    buff[_strlen(buff) - 1] = '\0'; /*remove the newline at the end*/

    return buff;
}

char **split_line(char *line, char *delimiter)
{
    int buffer_size = 64;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }

    token = strtok(line, delimiter);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= buffer_size)
        {
            buffer_size += 64;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "Allocation error\n");
                exit(1);
            }
        }

        token = strtok(NULL, delimiter);
    }
    tokens[position] = NULL;
    return tokens;
}

int is_builtin(char *command)
{
    if (_strcmp(command, "exit") == 0 || _strcmp(command, "env") == 0)
    {
        return 1;
    }
    return 0;
}

/*void execute_command(char *command)
{
    char *args[2];
    args[0] = command;
    args[1] = NULL;

    execve(command, args, NULL);
     execve only returns if an error occurs 
    perror("execve");
    exit(EXIT_FAILURE);
}*/
void execute_command(char *command)
{
    char *args[2];
    args[0] = command;
    args[1] = NULL;

    if (execvp(args[0], args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

void execute_child_process(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        return;
    }
    if (child_pid == 0)
    {
        /* child process */
        if (is_builtin(command))
        {
            /* handle built-in commands */
            if (_strcmp(command, "exit") == 0)
            {
                exit(EXIT_SUCCESS);
            }
            else if (_strcmp(command, "env") == 0)
            {
                /*Print environment variables or implement desired behavior*/
                print_env();
                exit(EXIT_SUCCESS);
            }
        }
        else
        {
            /* execute non-built-in commands */
            execute_command(command);
        }
    }
    else
    {
        /* parent process */
        waitpid(child_pid, &status, 0);
    }
}

void shell(void)
{
    char *line;
    char **commands;
    int i;

    while (1)
    {
        line = _getline();
        commands = split_line(line, ";");
        i = 0;
        while (commands[i] != NULL)
        {
            execute_child_process(commands[i]);
            i++;
        }
        free(line);
        free(commands);
    }
}

int main()
{
    shell();
    return 0;
}

