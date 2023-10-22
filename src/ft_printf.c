#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		c;
	double	d;
	
	i = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*str == 'c')
			{
				// A 'char' variable will be promoted to 'int'
				// A character literal in C is already 'int' by itself
				c = va_arg(args, int);
				printf("%c\n", c);
			}
			else if (*str == 'f')
			{
				d = va_arg(args, double);
				printf("%f\n", d);
			}
			else
			{
			}
			++str;
		}
		else 
		{
			ft_putchar_fd(1, *str);
			i++;
}
	}
	va_end(args);
	return (i);
}
