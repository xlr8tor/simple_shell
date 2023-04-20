#include "main.h"
/**
 * _atoi - coverts string to integer
 * @s: string to covert
 *
 * Return: (int) s
 */
int _atoi(char *s)
{
	unsigned int num;
	int sign;
	int i;

	num = 0;
	sign = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
			if (s[i + 1] < 48 || s[i + 1] > 57)
				break;
		}
	}
	return (num * sign);
}
