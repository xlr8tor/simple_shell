#include "main.h"
/**
 * lsh_loop - shell loop
 */
void lsh_loop(void)
{
	char *line;
	char **args;
	int i = 0;

	do {
		_puts("#cisfun: ");
		line = read_line();
		args = parse_args(line);

		while (args[i])
		{
			printf("%s\n", args[i]);
			i++;
		}
		free(line);
		free(args);
	}
	while (1);
}
