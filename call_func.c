#include "main.h"

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
