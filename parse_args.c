#include "main.h"

char **parse_args(char *line)
{
	char *line_cpy = NULL, *token;
	int i, len = 0, num_tokens = 0;
	char **argv;

	len = _strlen(line);
	line_cpy = malloc(sizeof(char) * len);

	if (!line_cpy)
	{
		perror("tsh: memory allocation error");
		exit(EXIT_FAILURE);
	}

	_strcpy(line_cpy, line);

	token = strtok(line, DELIM);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, DELIM);
	}

	num_tokens++;

	argv = malloc(sizeof(char *) *num_tokens);
	if (!argv)
	{
		free(line_cpy);
		perror("tsh: memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_cpy, DELIM);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, DELIM);
	}
	argv[i] = '\0';

	return (argv);
}
