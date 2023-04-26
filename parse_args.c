#include "main.h"
/**
 * parse_args - tokenize arguments supplied to stdin
 * @line: sequence of characters inputed in stdin
 *
 * Return: an array of arguments from the input string
 */
char **parse_args(char *line)
{
	char *line_cpy = NULL, *token, **argv;
	int i, len = 0, num_tokens = 0;

	while (*line == ' ' || *line == '\t')
		line++;
	len = _strlen(line);
	line_cpy = malloc(sizeof(char) * len + 1);
	if (!line_cpy)
	{
		perror("tsh: memory allocation error");
		exit(EXIT_FAILURE);
	}

	_strcpy(line_cpy, line);
	token = _strtok(line, DELIM);
	while (token != NULL)
	{
		num_tokens++;
		token = _strtok(NULL, DELIM);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens);
	if (!argv)
	{
		free(line_cpy);
		perror("tsh: memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = _strtok(line_cpy, DELIM);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
		_strcpy(argv[i], token);
		token = _strtok(NULL, DELIM);
	}
	argv[i] = '\0';
	free(line_cpy);
	return (argv);
}
