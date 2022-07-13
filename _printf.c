#include "main.h"

/**
 * _printf - custom printf
 * @format: poiner to const char
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	const char *str;
	int count = 0;
	va_list argl;

	if (format)
	{
		va_start(argl, format);
		str = format;

		cont = loop(argl, str);
		va_end(argl);
		return (count);
	}
	return (-1);
}
