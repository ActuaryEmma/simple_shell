Simple Shell Project

TASK 0:
Write a beautiful code that passes the Betty checks

TASK 1:
Write a UNIX command line interpreter.

    Usage: simple_shell

Your Shell should:

    Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    The command lines are made only of one word. No arguments will be passed to programs.
    If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
    You have to handle the "end of file" condition (Ctrl+D)

You don't have to:

    use the PATH
    implement built-ins
    handle special characters : ", ', `, \, *, &, #
    be able to move the cursor
    handle commands with arguments

execve will be the core part of your Shell, don't forget to pass the environ to it..

TASK 2:
Simple shell 0.1 +

    Handle command lines with arguments


TASK 3:
Simple shell 0.2 +

    Handle the PATH
    fork must not be called if the command doesn't exist


TASK 4:
Simple shell 0.3 +

    Implement the exit built-in, that exits the shell
    Usage: exit
    You don't have to handle any argument to the built-in exit


TASK 5:
Simple shell 0.4 +

    Implement the env built-in, that prints the current environment

TASK 6:
Simple shell 0.1 +

	Write your own getline function
	Use a buffer to read many chars at once and call the least possible the read system call
	You will need to use static variables
	You are not allowed to use getline
You dont have to:
	be able to move the cursor

TASK 7:
Simple shell 0.2 +

	You are not allowed to use strtok

TASK 8:
Simple shell 0.4 +

	handle arguments for the built-in exit
	Usage: exit status, where status is an integer used to exit the shell

TASK 9:
Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands

	setenv
		Initialize a new environment variable, or modify an existing one
		Command syntax: setenv VARIABLE VALUE
		Should print something on stderr on failure
	unsetenv
		Remove an environment variable
		Command syntax: unsetenv VARIABLE
		Should print something on stderr on failure

TASK 10:
Simple shell 1.0 +

Implement the builtin command cd:

	Changes the current directory of the process.
	Command syntax: cd [DIRECTORY]
	If no argument is given to cd the command must be interpreted like cd $HOME
	You have to handle the command cd -
	You have to update the environment variable PWD when you change directory

TASK 11:
Simple shell 1.0 +

	Handle the commands separator ;

TASK 12:
Simple shell 1.0 +

	Handle the && and || shell logical operators
