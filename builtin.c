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

/**
 * _mycd - change directory in shell
 * @argv: argument vector
 *
 * Return: int
 */
int _mycd(char **argv)
{
	char *home =  _getenv("HOME");
	char *pwd = _getenv("PWD");
	char *oldpwd = _getenv("OLDPWD");
	char *path = argv[1];
	char *dest;

	if (path == NULL)
	{
		dest = home;
	}
	else if (_strcmp(path, "-") == 0)
	{
		if (oldpwd == NULL)
		{
			perror("cd: OLDPWD not set");
			return (-1);
		}
		dest = oldpwd;
		_puts(dest);
	}
	else
	{
		dest = path;
	}

	if (chdir(dest) != 0)
	{
		perror("cd:");
		return (-1);
	}

	setenv("PWD", dest, 1);
	setenv("OLDPWD", pwd, 1);

	return (1);
}
