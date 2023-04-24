#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	len = _printf("%S\n", "Best\nSchool");
	_printf("Length:[%d, %i]\n", len, len);
	return (0);
}
