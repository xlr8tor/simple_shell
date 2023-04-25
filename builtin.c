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

	_setenv("PWD", dest, 1);
	_setenv("OLDPWD", pwd, 1);

	return (1);
}

/**
 * _setenv - Changes or adds an environmental variable to the PATH.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int _setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size;
	int index;

	if (!args[0] || !args[1])
		return (create_error(args, -1));

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
		return (create_error(args, -1));
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return (create_error(args, -1));
	}

	for (index = 0; environ[index]; index++)
		new_environ[index] = environ[index];

	free(environ);
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;

	return (0);
}
