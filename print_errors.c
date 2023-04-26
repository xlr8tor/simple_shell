#include "main.h"
/**
 * _puterrchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puterrchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * _putserr - prints a string to stdout
 * @str: string to print
 */
void _putserr(const char *str)
{
	int i  = 0;

	if (!str)
		return;
	while (str[i])
	{
		_puterrchar(str[i]);
		i++;
	}
}
