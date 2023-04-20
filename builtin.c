#include "main.h"
/**
 * _myexit - exits the shell
 * @argv: argument vector
 *
 * Return: exit status of program
 */
int _myexit(char **argv)
{
	if (argv[1] != NULL)
		exit(_atoi(argv[1]));
	else
		return (0);
}
