#include "main.h"
/**
 * lsh_loop - main shell loop
 * @prgname: name of program
 */
void lsh_loop(char *prgname)
{
	char *line;
	char **args;
	int status, i;

	do {
		if (isatty(0))
			_puts("#cisfun$ ");
		fflush(stdout);

		line = read_line();
		args = parse_args(line);
		status = execcmd(args, prgname);

		free(line);
		if (isatty(0))
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
		}
		free(args);
	} while (status);
}
