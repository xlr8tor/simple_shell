#include "main.h"
/**
 * lsh_loop - main shell loop
 * @prgname: name of program
 */
void lsh_loop(char *prgname)
{
	char *line, *trimmed_line;
	char **args;
	int status, i, num_tokens;

	do {
		if (isatty(0))
			_puts("#cisfun$ ");
		fflush(stdout);

		line = read_line();
		trimmed_line = trim_input(line);
		args = split_string(trimmed_line, DELIM, &num_tokens);
		status = execcmd(args, prgname);

		free(line);
		free(trimmed_line);

		for (i = 0; i < num_tokens; i++)
			free(args[i]);
		free(args);
	} while (status);
}
