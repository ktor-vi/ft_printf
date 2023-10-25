#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				i += ft_putchar_fdr(va_arg(args, int), 1);
			else if (*str == 's')
				i += ft_putstr_fdr(va_arg(args, char *), 1);
			else if (*str == 'p')
				i += ft_voidhex_fdr(va_arg(args, void *), 0, 1);
			else if (*str == 'd')
				i += ft_putnbr_fdr(va_arg(args, int), 0, 1);
			else if (*str == 'i')
				i += ft_putnbr_fdr(va_arg(args, int), 0, 1);
			else if (*str == 'u')
				i += ft_putul_base_fdr(va_arg(args, unsigned long), 0,
					"0123456789", 1);
			else if (*str == 'x')
				i += ft_putnbr_base_fdr(va_arg(args, long long), 0,
					"0123456789abcdef", 1);
			else if (*str == 'X')
				i += ft_putnbr_base_fdr(va_arg(args, long long), 0,
					"0123456789ABCDEF", 1);
			else if (*str == '%')
				i += ft_putchar_fdr('%', 1);
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
