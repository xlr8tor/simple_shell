#include "main.h"
/**
 * _myexit - exits the shell
 * @argv: argument vector
 *
 * Return: exit status of program
 */
int _myexit(char **argv)
{
	if (argv[1] != NULL)
		exit(_atoi(argv[1]));
	else
		return (0);
}

/**
 * _printenv - prints shell environment variables
 * @argv: argument vector
 *
 * Return: exit status of program
 */
int _printenv(char **argv)
{
	int i;

	UNUSED(argv);

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	return (1);
}
