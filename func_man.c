#include "main.h"
#include <stdarg.h>
/**
 * function_manager - function manager
 * @c: character to find
 * @arg: va_list type
 *Return: count of printed characters
 */
int function_manager(char c, va_list arg)
{
	int conts = 0;

	conts = _switch(c, arg);
	if (c == 'p')
		conts = print_ptr(arg);
	return (conts);
}
/**
 * _switch - switch
 * @c: character to find
 * @arg: va_list type
 * Description: This function evaluate cases
 * Return: count of printed characters
 */
int _switch(char c, va_list arg)
{
	int conts = 0;

	switch (c)
	{
		case 'b':
			conts += print_unsign(arg, 2);
			break;
		case 'c':
			conts += print_character(arg);
			break;
		case 'd':
		case 'i':
			conts += print_sign(arg, 10);
			break;
		case 'o':
			conts += print_unsign(arg, 8);
			break;
		case 'r':
			conts += print_rev(arg);
			break;
		case 'R':
			conts += print_rot13(arg);
			break;
		case 's':
			conts += print_string(arg);
			break;
		case 'u':
			conts += print_unsign(arg, 10);
			break;
		case 'x':
			conts += print_base16_upper_lower(arg, "0123456789abcdef");
			break;
		case 'X':
			conts += print_base16_upper_lower(arg, "0123456789ABCDEF");
			break;
		default:
			conts = -1;
	}
	return (conts);
}
