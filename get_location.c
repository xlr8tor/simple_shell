#include "main.h"
/**
 * get_location - searches for the command in the PATH variable
 * @command: command inputed
 *
 * Return: file path of command || NULL
 */

char *get_location(char *command)
{
	char *path, *path_cpy, *token, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		cmd_len = _strlen(command);
		path_cpy = _strdup(path);
		token = _strtok(path_cpy, ":");

		while (token != NULL)
		{
			dir_len = _strlen(token);
			file_path = malloc(cmd_len + dir_len + 2);
			if (!file_path)
				return (NULL);
			_strcpy(file_path, token);
			_strconcat(file_path, "/");
			_strconcat(file_path, command);
			_strconcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = _strtok(NULL, ":");
			}
		}
		free(path_cpy);
		file_path = NULL;
		if (stat(command, &buffer) == 0)
			file_path = _strdup(command);
		return (file_path);
	}
	return (NULL);
}
