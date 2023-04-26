#include "main.h"
/**
 * lsh_loop - main shell loop
 */
void lsh_loop(void)
{
	char *line;
	char **args;
	int status, i;

	do {
		_puts("#cisfun: ");
		line = read_line();
		args = parse_args(line);
		status = execcmd(args);

		free(line);
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	} while (status);
}
