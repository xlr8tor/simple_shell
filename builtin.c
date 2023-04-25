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
 * _setenv - Initialize a new environment variable, or modify an existing one.
 * @name: The environment variable name to be initialized or modified.
 * @value: The value of the environment variable.
 * @overwrite: Specifies if the existing environmental variable should be
 *             overwritten or not (If non-zero, it overwrites & if 0 otherwise)
 *
 * Return: -1 on error and 0 otherwise.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int namelen = _strlen(name), vallen = _strlen(value);
	int i, var_len;
	char *newvar;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, namelen) == 0 && environ[i][namelen] == '=')
		{
			if (!overwrite)
			return (-1);
		}
		else
		{
			var_len = namelen + vallen + 1;
			newvar = malloc(var_len);
			_strncpy(newvar, name, namelen);
			newvar[namelen] = '=';
			_strncpy(newvar + namelen + 1, value, vallen);
			newvar[var_len - 1] = '\0';
			environ[i] = newvar;

			free(newvar);

			return (0);
		}
	}

	var_len = namelen + vallen + 1;
	newvar = malloc(var_len);
	_strncpy(newvar, name, namelen);
	newvar[namelen] = '=';
	_strncpy(newvar + namelen + 1, value, vallen);
	newvar[var_len - 1] = '\0';
	environ[i] = newvar;
	environ[i + 1] = NULL;

	free(newvar);

	return (0);
}

/**
 * _unsetenv - Remove an environment variable.
 * @name: The environmental variable to be removed.
 *
 * Return: 0 on success, -1 otherwise.
 */
int _unsetenv(const char *name)
{
	int i, j, k;
	char **new_env;

	if (name == NULL || strlen(name) == 0)
		return (-1);

	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (name[j] != '\0' && name[j] == environ[i][j])
			j++;

		if (name[j] == '\0' && environ[i][j] == '=')
			break;
		i++;
	}

	if (environ[i] == NULL)
		return (-1);

	new_env = malloc(sizeof(char *) * (environ_size + 1));
	if (new_env == NULL)
		return (-1);

	j = 0;
	for (k = 0; k < environ_size; k++)
	{
		if (k != i)
			new_env[j++] = environ[k];
	}
	new_env[j] = NULL;

	environ = new_env;
	environ_size = j;
	free(new_env);

	return (0);
}