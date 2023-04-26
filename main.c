#include "main.h"
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
	lsh_loop(prgname);
	return (EXIT_SUCCESS);
}
