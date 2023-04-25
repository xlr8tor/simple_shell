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

/**
 * _strcmp - compare two string
 * @s1: 1st arg
 * @s2: 2nd arg
 *
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, result = 0;

	while (s2[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			result = (s1[i] - s2[i]);
			break;
		}
		else if (s1[i] < s2[i])
		{
			result = (s1[i] - s2[i]);
			break;
		}
		i++;
	}
	return (result);
}

/**
 * _strncmp - compare to strings up to the specified index
 * @s1: 1st arg
 * @s2: 2nd arg
 * @n: index
 *
 * Return: int
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
