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

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
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
	if (argv[0] == NULL)
		return (1);

	return (launch_cmd(argv));
}
