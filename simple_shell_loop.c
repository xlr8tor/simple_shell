#include "main.h"
/**
 * lsh_loop - main shell loop
 */
void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		_puts("#cisfun: ");
		line = read_line();
		args = parse_args(line);

		if (_strcmp(args[0], "exit") == 0)
			exit_shell();

		status = execcmd(args);

		free(line);
		free(args);
	} while (status);
}
