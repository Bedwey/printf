#include "main.h"

/**
 * hexa_converter - changes number base
 *
 * @num: input number
 * @base: base to convert
 *
 * Return: pointer to array - with the number converted
*/

char *hexa_converter(unsigned int num, int base)
{
	char symbols[] = "0123456789ABCDEF";
	static char array[100];
	char *ptr;

	ptr = &array[99];
	*ptr = '\0';

	do {
		*--ptr = symbols[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * hexa_replacer - replace no printable characters by \x + hexa value
 *
 * @s: pointer to char
 *
 * Return: pointer to char
*/

char *hexa_replacer(char *s)
{
	int i = 0;
	int j = 0;
	char buffer[10000];
	char *ptr;
	char *ptr2;

	ptr = &buffer[0];
	while (s[i])
	{
		if (s[i] < 32)
		{
			ptr[j] = 92;
			ptr[j + 1] = 120;
			ptr2 = hexa_converter(s[i], 16);
			if (s[i] < 17)
			{
				ptr[j + 2] = 48;
				ptr[j + 3] = ptr2[0];
			}
			else
			{
				ptr[j + 2] = ptr2[0];
				ptr[j + 3] = ptr2[1];
			}
			j += 4;
		}
		else
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

/**
 * non_printable - prints an octal number.
 *
 * @ap: arguments to print.
 *
 * Return: number of characters printed.
*/

int non_printable(va_list ap)
{
	char *s;
	int len;

	len = 0;
	s = va_arg(ap, char*);

	if (*s == 0)
		return (_write_char('0'));

	if (*s < 1)
		return (-1);

	len = helper_len(*s, 2);

	if (s)
	{
		s = hexa_replacer(s);
		helper_write(s);
	}

	return (len);
}
