#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <signal.h>

#define DELIM " \n"
#define UNUSED(x) ((void) (x))

extern char **environ;
int environ_size;

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
void lsh_loop(char *prgname);

/* BUILTIN FUNCTIONS */
int _myexit(char **argv);
int _printenv(char **argv);
int _mycd(char **argv);

/* STRING FUNCTIONS */
int _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strconcat(char *dest, const char *src);
char *_strdup(const char *str);
char *begins_with(const char *str, const char *substr);
int _putchar(char c);
void _puts(const char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, int n);

/* READ LINE FUNCTIONS */
char *read_line(void);

/* PARSE ARGUMENTS */
char **parse_args(char *line);

/* EXECUTE COMMAND */
int launch_cmd(char **argv, char *prgname);
int execcmd(char **argv, char *prgname);

/* GET FULL PATH */
char *get_location(char *command);

/* CONVERT CHAR POINTER TO INT */
int _atoi(char *s);

/* TOKENIZE STRING */
char *_strtok(char *str, const char *delim);

/* GETLINE FUNCTIONS */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* GET ENVIRONMENT VARIABLE */
char *_getenv(const char *path);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* PRINT ERRORS */
int _puterrchar(char c);
void _putserr(const char *str);

#endif /* MAIN_H */
