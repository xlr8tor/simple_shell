#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: string to print
 */
void _puts(const char *str)
{
	int i  = 0;

	if (!str)
		return;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
