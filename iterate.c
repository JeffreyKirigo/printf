#include "main.h"

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
