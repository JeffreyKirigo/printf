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

	if (!format)
	{
		return (-1);
	}
	va_start(argl, format);
	str = format;
	cont = loop(argl, str);
	va_end(argl);
	return (count);
}
/**
 * loop - loop format
 * @arg: va_list arg
 * @string: pointer from format
 * Description: This loops string pointer
 * Return: number of characteres printed
 */
int loop(va_list arg, const char *string)
{
	int i = 0, flags = 0, count_fm = 0, count = 0, check_per = 0;

	while (i < _strlen((char *)string) && *string != '\0')
	{
		char str = string[i];

		if (str == '%')
		{
			i++, flags++;
			str = string[i];
			if (str == '\0' && _strlen((char *)string) == 1)
				return (-1);
			if (str == '\0')
				return (count);
			if (str == '%')
			{
				flags++;
			} else
			{
				count_fm = function_manager(str, arg);
				if (count_fm >= 0 && count_fm != -1)
				{
					i++;
					str = string[i];
					if (str == '%')
						flags--;
					count = count + count_fm;
				} else if (count_fm == -1 && str != '\n')
				{
					count += _putchar('%');
				}
			}
		}
		check_per = check_percent(&flags, str);
		count += check_per;
		if (check_per == 0 && str != '\0' && str != '%')
			count += _putchar(str), i++;
		check_per = 0;
	}
	return (count);
}

/**
 * check_percent - check for % sign
 * @flag: value by reference
 * @temp: character
 * Description: This function print %
 * Return: 1 if % is printed
 */
int check_percent(int *flag, char temp)
{
	int temp_flag;
	int cont = 0;

	temp_flag = *flag;
	if (temp_flag == 2 && temp == '%')
	{
		_putchar('%');
		temp_flag = 0;
		cont = 1;
	}
	return (cont);
}

/**
 * call_func - call function manager
 * @temp: character parameter
 * @argl: va_list argl
 * Description: This function call function manager
 * Return: num of characteres printed
 */

int call_func(char temp, va_list argl)
{
	int cont = 0;

	cont = function_manager(temp, argl);
	return (cont);
}
