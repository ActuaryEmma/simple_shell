#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"
#define PATH_DELIMITER ":"

extern char **environ;

void display_prompt(void);
char *read_command(void);
char **parse_command(char *command);
char *find_command(char *command);
void execute_command(char **args);
int is_exit_builtin(char *command);
void exit_shell(void);
void print_environment(void);

int main(void)
{
        char *command;
        char **args;

        while (1)
        {
                display_prompt();
                command = read_command();

                if (command == NULL)
                {
                        printf("\n");
                        break;
                }

                args = parse_command(command);

                if (is_exit_builtin(args[0]))
                {
                        exit_shell();
                }
                else if (strcmp(args[0], "env") == 0)
                {
                        print_environment();
                }
                else
                {
                        execute_command(args);
                }
                free(command);
                free(args);
        }
        return (0);
}

void display_prompt(void)
{
        printf("$ ");
}

char *read_command(void)
{
        char *command = NULL;
        size_t bufsize = 0;
        ssize_t characters_read;

        characters_read = getline(&command, &bufsize, stdin);
        if (characters_read == -1)
        {
                free(command);
                return (NULL);
        }
        if (command[characters_read - 1] == '\n')
        {
                command[characters_read - 1] = '\0';  /* Remove trailing newline */
        }

        return (command);
}

char **parse_command(char *command)
{
        int bufsize = BUFFER_SIZE;
        int position = 0;
        char **args = malloc(bufsize * sizeof(char *));
        char *token;

        if (!args)
        {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
        }
        token = strtok(command, TOKEN_DELIMITERS);
        while (token != NULL)
        {
                args[position] = token;
                position++;

                if (position >= bufsize)
                {
                        bufsize += BUFFER_SIZE;
                        args = realloc(args, bufsize * sizeof(char *));
                        if (!args)
                        {
                                fprintf(stderr, "Allocation error\n");
                                exit(EXIT_FAILURE);
                        }
                }
                token = strtok(NULL, TOKEN_DELIMITERS);
        }
        args[position] = NULL;
        return (args);
}

char *find_command(char *command)
{
        char *path = getenv("PATH");
        char *path_token;
        char *command_path = malloc(BUFFER_SIZE * sizeof(char));

        if (!command_path)
        {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
        }
        path_token = strtok(path, PATH_DELIMITER);
        while (path_token != NULL)
        {
                strcpy(command_path, path_token);
                strcat(command_path, "/");
                strcat(command_path, command);

                if (access(command_path, X_OK) == 0)
                {
                        return (command_path);
                }
                path_token = strtok(NULL, PATH_DELIMITER);
        }
        free(command_path);
        return (NULL);
}

void execute_command(char **args)
{
        char *command_path;
        pid_t pid;
        int status;

        command_path = find_command(args[0]);

        if (command_path == NULL)
        {
                fprintf(stderr, "%s: command not found\n", args[0]);
                return;
        }
        pid = fork();
        if (pid == 0)
        {
                /* Child process */
                if (execve(command_path, args, environ) == -1)
                {
                        fprintf(stderr, "Execution error\n");
                        exit(EXIT_FAILURE);
                }
        }
        else if (pid < 0)
        {
                /* Forking error */
                fprintf(stderr, "Forking error\n");
        }
        else
        {
                /* Parent process */
                do {
                        if (waitpid(pid, &status, WUNTRACED) == -1)
                        {
                                perror("waitpid");
                                exit(EXIT_FAILURE);
                        }
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        free(command_path);
}

int is_exit_builtin(char *command)
{
        return (strcmp(command, "exit") == 0);
}

void exit_shell(void)
{
        exit(EXIT_SUCCESS);
}

void print_environment(void)
{
        char **env = environ;

        while (*env)
        {
                printf("%s\n", *env);
                env++;
        }
}
