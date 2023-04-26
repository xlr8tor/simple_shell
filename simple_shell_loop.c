#include "main.h"
/**
 * lsh_loop - main shell loop
 * @prgname: name of program
 */
void lsh_loop(char *prgname)
{
	char *line;
	char **args;
	int status;

	do {
		_puts("#cisfun: ");
		line = read_line();
		args = parse_args(line);
		status = execcmd(args, prgname);

		free(line);
		free(args);
	} while (status);
}
