#include "main.h"

/**
 * print_unsgined_number - Prints an unsigned number
 *
 * @ap: List of all the arguments passed to the program
 *
 * Return: The amount of numbers printed
 */

int print_unsgined_number(va_list ap)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = va_arg(ap, unsigned int);

	if (num < 1)
		return (-1);

	for (; num / div > 9;)
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_octal - Prints the numeric representation of a number in octal base
 *
 *  @ap: List of all the arguments passed to the program
 *
 *  Return: Number of symbols printed to stdout
 */

int print_octal(va_list ap)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_write_char('0'));
	if (num < 1)
		return (-1);
	len = helper_len(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);

	if (octal_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';

	rev_str = rev_string(octal_rep);

	if (rev_str == NULL)
		return (-1);

	helper_write(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}


/**
 * print_hex - Prints a representation of a decimal number lowercase
 *
 * @ap: List of the arguments passed to the function
 * @lc: Is Lower Case
 * Return: Number of characters printed
 */

int print_hex(va_list ap, bool lc)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_write_char('0'));
	if (num < 1)
		return (-1);
	len = helper_len(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, lc);
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	helper_write(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * print_LHex - Prints a representation of a decimal number lowercase
 *
 * @ap: List of the arguments passed to the function
 * Return: Number of characters printed
 */

int print_LHex(va_list ap)
{
	return (print_hex(ap, true));
}

/**
 * print_UHex - Prints a representation of a decimal number uppercase
 *
 * @ap: List of the arguments passed to the function
 * Return: Number of characters printed
 */

int print_UHex(va_list ap)
{
	return (print_hex(ap, false));
}
