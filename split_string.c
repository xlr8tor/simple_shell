#include "main.h"
/**
 * split_string - splits a string by a delimiter
 * @string: string to split
 * @delimiter: delimiter
 * @num_tokens: number of tokens
 *
 * Return: array of strings
 */
char **split_string(const char *string, const char *delimiter, int *num_tokens)
{
	char **tokens;
	char *token;
	char *mutable_string = strdup(string);
	int i = 0, j;

	tokens = malloc(MAX_TOKENS * sizeof(char *));
	if (!tokens || !mutable_string)
	{
		perror("Error: memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < MAX_TOKENS; j++)
		tokens[j] = NULL;

	token = strtok(mutable_string, delimiter);
	while (token != NULL)
	{
		while (isspace(*token))
			token++;
		if (*token == '\0')
			break;
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			perror("Error: memory allocation failed");
			exit(EXIT_FAILURE);
		}
		i++;
		if (i >= MAX_TOKENS)
		{
			fprintf(stderr, "Error: too many tokens\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delimiter);
	}
	*num_tokens = i;
	free(mutable_string);
	return (tokens);
}
