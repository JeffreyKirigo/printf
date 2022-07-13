#include "main.h"

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
