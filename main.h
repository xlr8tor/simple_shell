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

/* MAIN LOOP FUNCTION */
void lsh_loop(void);

/* STRING FUNCTIONS */
int _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strconcat(char *dest, const char *src);
char *_strdup(const char *str);
char *begins_with(const char *str, const char *substr);
int _putchar(char c);
void _puts(const char *str);

/* READ LINE FUNCTIONS */
char *read_line(void);

/* PARSE ARGUMENTS */
char **parse_args(char *line);

/* EXECUTE COMMAND */
int launch_cmd(char **argv);
int execcmd(char **argv);

/* GET FULL PATH */
char *get_location(char *command);

#endif /* MAIN_H */
