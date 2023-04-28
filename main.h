#ifndef _MAIN_H_
#define _MAIN_H_

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;

/* Main Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
int exec_cmd(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

/* Input Helpers */
void handle_line(char **line, ssize_t read);
int parse_args(char **args, char **front, int *exec_ret);
int handle_args(int *exec_ret);
void variable_replacement(char **args, int *exec_ret);
char *get_args(char *line, int *exec_ret);
int run_args(char **args, char **front, int *exec_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);

/* String functions */
char *_strcat(char *dest, const char *src);
int _strlen(const char *s);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);

/* Builtins */
int (*get_builtin(char *command))(char **args, char **front);
int sh_exit(char **args, char **front);
int _env(char **args, char __attribute__((__unused__)) **front);
int _setenv(char **args, char __attribute__((__unused__)) **front);
int _unsetenv(char **args, char __attribute__((__unused__)) **front);
int _cd(char **args, char __attribute__((__unused__)) **front);
int _alias(char **args, char __attribute__((__unused__)) **front);
int _help(char **args, char __attribute__((__unused__)) **front);

/* Builtin Helpers */
char **_getenv(const char *var);
char **_copyenv(void);
void free_env(void);

/* Error Handling */
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* Linkedlist Helpers */
void free_alias_list(alias_t *head);
void free_list(list_t *head);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
list_t *add_node_end(list_t **head, char *dir);

void hlp_exit(void);
void hlp_alias(void);
void hlp_cd(void);
void hlp_all(void);
void hlp_help(void);
void hlp_env(void);
void hlp_setenv(void);
void hlp_unsetenv(void);
void hlp_history(void);

int proc_file_commands(char *file_path, int *exec_ret);

#endif /* _MAIN_H_ */
