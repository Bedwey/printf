#include "main.h"

/**
 * rot13 - Converts string to rot13
 *
 * @ap: List a of arguments
 *
 * Return: converted string
 */

int rot13(va_list ap)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ap, char *);
	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_write_char(u[x]);
				break;
			}
		}

		if (x == 53)
			_write_char(str[i]);
	}

	return (i);
}
