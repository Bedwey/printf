#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/**
* struct args_handle - defines a structure
* for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/

struct args_handle
{
	char *sym;
	int (*f)(va_list);
};
typedef struct args_handle args_handle_t;

int manager(const char *format, va_list ap, args_handle_t args_list[]);
int _write_char(char);
int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list);
int print_integer(va_list ap);
int print_binary(va_list);
int unsigned_integer(va_list);
int print_octal(va_list ap);
int print_hex(va_list ap, bool lc);
int print_LHex(va_list ap);
int print_UHex(va_list ap);
int non_printable(va_list ap);
int print_reverse(va_list ap);
int rot13(va_list ap);
int print_pointer(va_list ap);

/*Helper Functions*/
unsigned int helper_len(unsigned int, int);
char *rev_string(char *);
int helper_write(char *str);
int hex_check(int num, bool lc);
int print_unsgined_number(unsigned int);
char *hexa_converter(unsigned int num, int base);
char *hexa_replacer(char *s);
int flager(const char *format, int *i);

int _printf(const char *format, ...);

#endif
