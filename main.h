#ifndef MAIN_FILE
#define MAIN_FILE
#include <stdarg.h>
int _printf(const char *format, ...);
int loop(va_list arg, const char *string);
int check_percent(int *flag, char temp);
int call_func(char temp, va_list argl);
int function_manager(char c, va_list arg);
int _switch(char c, va_list arg);
int _putchar(char c);
int _strlen(char *s);
void _puts(char *str);
char *convert_to(char representation[], unsigned int num, int base);
#endif
