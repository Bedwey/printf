#include "main.h"

/**
 * print_reverse - print string in reverse.
 *
 * @ap: List of arguments passed to this function
 *
 * Return: The amount of characters printed
 */

int print_reverse(va_list ap)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(ap, char *);

	if (str == NULL)
		return (-1);
	ptr = rev_string(str);

	if (ptr == NULL)
		return (-1);

	for (len = 0; ptr[len] != '\0'; len++)
	{
		_write_char(ptr[len]);
	}

	free(ptr);
	return (len);
}
