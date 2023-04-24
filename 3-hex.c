#include "main.h"

/**
 * hex_check - Checks which hex function is calling it
 *
 * @num: Number to convert into letter
 * @lc: Is Lower Case
 *
 * Return: Ascii value for a letter
 */

int hex_check(int num, bool lc)
{
        char *hex = "abcdef";
        char *Hex = "ABCDEF";

        num = num - 10;
        if (lc)
                return (hex[num]);
        else
                return (Hex[num]);
        return (0);
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
