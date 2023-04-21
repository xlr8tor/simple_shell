#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DELIM " \n"
#define UNUSED(x) ((void) (x))

extern char **environ;

/**
 * struct builtin - user defined type
 * @cmd: builtin command name
 * @fn: function to execute
 */
struct builtin
{
	char *cmd;
	int (*fn)(char **);
};

/**
 * builtin_t - typedef for struct builtin
 */
typedef struct builtin builtin_t;

/* MAIN LOOP FUNCTION */
void lsh_loop(void);

/* BUILTIN FUNCTIONS */
int _myexit(char **argv);
int _printenv(char **argv);

/* STRING FUNCTIONS */
int _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strconcat(char *dest, const char *src);
char *_strdup(const char *str);
char *begins_with(const char *str, const char *substr);
int _putchar(char c);
void _puts(const char *str);
int _strcmp(char *s1, char *s2);

/* READ LINE FUNCTIONS */
char *read_line(void);

/* PARSE ARGUMENTS */
char **parse_args(char *line);

/* EXECUTE COMMAND */
int launch_cmd(char **argv);
int execcmd(char **argv);

/* GET FULL PATH */
char *get_location(char *command);

/* CONVERT CHAR POINTER TO INT */
int _atoi(char *s);

#endif /* MAIN_H */
