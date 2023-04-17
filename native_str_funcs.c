#include "main.h"
/**
 * _strlen - finds the length of a string
 * @str: a pointer to the string
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * _strcpy - copies a string pointed to by src to dest
 * @dest: pointer to the destination string
 * @src: pointer to the src string
 *
 * Return: pointer to destionation string
 */
char * _strcpy(char *dest, const char *src)
{
	int i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;
	dest[i] = '\0';

	return (dest);	
}
