#include "main.h"
/**
 * _strtok - tokenize a given string
 * @str: string to tokenize
 * @delim: delimiter
 *
 * Return: string tokens
 */

char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token;

	if (str != NULL)
		last_token = str;
	else if (last_token == NULL)
		return (NULL);
	token = last_token;
	while (*last_token != '\0')
	{
		const char *d = delim;

		while (*d != '\0')
		{
			if (*last_token == *d)
			{
				*last_token = '\0';
				last_token++;
				if (token != last_token - 1)
				{
					return (token);
				}
				else
				{
					token = last_token;
					break;
				}
			}
			d++;
		}
		if (*last_token == '\0')
		{
			if (token != last_token)
				return (token);
			else
				return (NULL);
		}
		last_token++;
	}
	return (NULL);
}

/**
  * _strncpy - Copy a string
  * @dest: The destination value
  * @src: The source value
  * @n: The copy limit
  *
  * Return: char value
  */
char *_strncpy(char *dest, const char *src, int n)
{
	int i = 0, j = 0;

	while (src[j])
	{
		j++;
	}

	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
