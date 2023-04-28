#include "main.h"

int _alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);

/**
 * _alias - Builtin command that either prints all aliases, specific
 * aliases, or sets an alias.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int _alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *tmp = aliases;
	int i, ret = 0;
	char *value;

	if (!args[0])
	{
		while (tmp)
		{
			print_alias(tmp);
			tmp = tmp->next;
		}
		return (ret);
	}
	for (i = 0; args[i]; i++)
	{
		tmp = aliases;
		value = _strchr(args[i], '=');
		if (!value)
		{
			while (tmp)
			{
				if (_strcmp(args[i], tmp->name) == 0)
				{
					print_alias(tmp);
					break;
				}
				tmp = tmp->next;
			}
			if (!tmp)
				ret = create_error(args + i, 1);
		}
		else
			set_alias(args[i], value);
	}
	return (ret);
}

/**
 * set_alias - Will either set an existing alias 'name' with a new value,
 * 'value' or creates a new alias with 'name' and 'value'.
 * @var_name: Name of the alias.
 * @value: Value of the alias. First character is a '='.
 */
void set_alias(char *var_name, char *value)
{
	alias_t *tmp = aliases;
	int len, j, k;
	char *new_val;

	*value = '\0';
	value++;
	len = _strlen(value) - _strspn(value, "'\"");
	new_val = malloc(sizeof(char) * (len + 1));
	if (!new_val)
		return;
	for (j = 0, k = 0; value[j]; j++)
	{
		if (value[j] != '\'' && value[j] != '"')
			new_val[k++] = value[j];
	}
	new_val[k] = '\0';
	while (tmp)
	{
		if (_strcmp(var_name, tmp->name) == 0)
		{
			free(tmp->value);
			tmp->value = new_val;
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		add_alias_end(&aliases, var_name, new_val);
}

/**
 * print_alias - Prints the alias in the format name='value'.
 * @alias: Pointer to an alias.
 */
void print_alias(alias_t *alias)
{
	char *alias_string;
	int len = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, len);
	free(alias_string);
}
/**
 * replace_aliases - Goes through the arguments and replace any matching alias
 * with their value.
 * @args: 2D pointer to the arguments.
 *
 * Return: 2D pointer to the arguments.
 */
char **replace_aliases(char **args)
{
	alias_t *tmp;
	int i;
	char *new_val;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		tmp = aliases;
		while (tmp)
		{
			if (_strcmp(args[i], tmp->name) == 0)
			{
				new_val = malloc(sizeof(char) * (_strlen(tmp->value) + 1));
				if (!new_val)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_val, tmp->value);
				free(args[i]);
				args[i] = new_val;
				i--;
				break;
			}
			tmp = tmp->next;
		}
	}

	return (args);
}
