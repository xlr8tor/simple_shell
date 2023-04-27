#include "main.h"
/**
 * lsh_loop - main shell loop
 * @prgname: name of program
 */
void lsh_loop(char *prgname)
{
	char *line;
	char **args;
	int status = 1;

	do {
		if (isatty(0))
			_puts("#cisfun$ ");
		fflush(stdout);

		line = read_line();
		args = parse_args(line);
		status = execcmd(args, prgname);

		free(line);
		free(args);
		line = NULL;
		args = NULL;
	} while (status);
}
