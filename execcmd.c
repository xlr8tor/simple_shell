#include "main.h"
/**
 * launch_cmd - creates a new process and executes a command
 * @argv: argument vector
 *
 * Return: 1 || -1
 */
int launch_cmd(char **argv)
{
	pid_t pid;
	int status;
	char *command;

	command = get_location(argv[0]);
	if (!command)
	{
		perror("Error:");
		return (EXIT_FAILURE);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
			perror("Error:");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error:");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(command);
	return (1);
}

/**
 * execcmd - executes the command inputed into stdin
 * @argv: a pointer to array of string arguments
 *
 * Return: 1 on SUCCESS || -1 on FAILURE
 */
int execcmd(char **argv)
{
	int i;
	builtin_t builtin_list[] = {
		{"exit", _myexit},
		{"env", _printenv},
		{"cd", _mycd},
		{"\0", NULL}
	};

	if (argv[0] == NULL)
		return (1);

	for (i = 0; builtin_list[i].fn != NULL; i++)
	{
		if (_strcmp(argv[0], builtin_list[i].cmd) == 0)
			return (builtin_list[i].fn(argv));
	}
	return (launch_cmd(argv));
}
