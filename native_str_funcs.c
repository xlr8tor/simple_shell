#include "main.h"
/**
 * _strlen - finds the length of a string
 * @str: a pointer to the string
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcpy - copies a string pointed to by src to dest
 * @dest: pointer to the destination string
 * @src: pointer to the src string
 *
 * Return: pointer to destionation string
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;
	dest[i] = '\0';

	return (dest);
}

/**
 * _strconcat - appends the src string to the dest string
 * @dest: string to append to
 * @src: string to append
 *
 * Return: dest
 */
char *_strconcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';

	return (dest);
}

/**
 * begins_with - checks if str starts with a substring
 * @str: string to search
 * @substr: string to find
 *
 * Return: str || NULL
 */
char *begins_with(const char *str, const char *substr)
{

	while (*substr)
	{
		if (*substr++ != *str++)
			return (NULL);
	}

	return ((char *) str);
}

/**
 * _strdup - duplicates a given string
 * @str: string to duplicate
 *
 * Return: pointer to new string
 */
char *_strdup(const char *str)
{
	int i, len;
	char *ptr;

	if (!str)
		return (NULL);
	len = _strlen(str);

	ptr = malloc(sizeof(char) * (len + 1));

	if (!ptr)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';

	return (ptr);
}
