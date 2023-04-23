#include "main.h"

/**
 * _memcpy - copy memory area
 *
 * @dest: Destination for copying
 * @src: Source to copy from
 *
 * @n: The number of bytes to copy
 *
 * Return: a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * rev_string - reverses a string in place
 *
 * @s: string to reverse
 *
 * Return: A pointer to a character
 */

char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * helper_len - Calculates the length for an octal number
 *
 *  @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 *
 *  Return: An integer representing the length of a number
 */

unsigned int helper_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
		num = num / base;
	return (i);
}

/**
 * helper_write - sends characters to be
 * written on standard output.
 * @str: String to parse
 */

void helper_write(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
}

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
