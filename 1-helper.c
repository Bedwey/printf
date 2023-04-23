#include "main.h"

/**
 * print_integer - Prints an integer
 *
 * @ap: ap of arguments
 *
 * Return: the lenght of characters printed.
 */

int print_integer(va_list ap)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(ap, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _write_char('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
