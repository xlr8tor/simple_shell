#include "main.h"
/**
 * trim_input - removes trailing and leading whitespace from string
 * @line: input string
 *
 * Return: pointer to trimmed string
 */
char *trim_input(char *line)
{
	size_t start = 0, end = _strlen(line) - 1;
	char *substr;

	if (line == NULL || *line == '\0')
		return (NULL);

	while (isspace(line[start]))
		start++;

	while (end > start && isspace(line[end]))
		end--;
	substr = malloc(end - start + 2);

	if (substr == NULL)
	{
		_putserr("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	memcpy(substr, line + start, end - start + 1);
	substr[end - start + 1] = '\0';

	return (substr);
}
