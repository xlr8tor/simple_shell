#include "main.h"
/**
 * read_line - reads line from stdin
 *
 * Return: number of characters read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;

	linelen = getline(&line, &linecap, stdin);
	if (linelen == -1)
		exit(EXIT_SUCCESS);

	return (line);
}