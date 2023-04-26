#include "main.h"
/**
 * handle_signal - handles control C
 * @signal: signal
 */
void handle_signal(int signal)
{
	(void) (signal);
}

/**
 * main - Entry point of the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *prgname = argv[0];

	(void) (argc);

	signal(SIGINT, handle_signal);
	lsh_loop(prgname);
	return (EXIT_SUCCESS);
}
