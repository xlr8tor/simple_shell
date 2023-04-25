#include "main.h"

/**
 * _getenv - get the environment variable for a property name
 * @path: name of the property
 *
 * Return: pointer to the property value
 */
char *_getenv(const char *path)
{
	char **p = environ;
	size_t len = _strlen(path);

	while (*p != NULL)
	{
		if (_strncmp(path, *p, len) == 0 && (*p)[len] == '=')
			return (*p + len + 1);
		++p;
	}
	return (NULL);
}
