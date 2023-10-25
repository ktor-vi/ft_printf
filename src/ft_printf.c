/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:15 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:40:27 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_dispatch(char flag, int i, va_list args)
{
	if (flag == 'c')
		i += ft_putchar_fdr(va_arg(args, int), 1);
	else if (flag == 's')
		i += ft_putstr_fdr(va_arg(args, char *), 1);
	else if (flag == 'p')
		i += ft_voidhex_fdr(va_arg(args, void *), 0, 1);
	else if (flag == 'd')
		i += ft_putnbr_fdr(va_arg(args, int), 0, 1);
	else if (flag == 'i')
		i += ft_putnbr_fdr(va_arg(args, int), 0, 1);
	else if (flag == 'u')
		i += ft_putui_base_fdr(va_arg(args, unsigned int), 0, "0123456789", 1);
	else if (flag == 'x')
		i += ft_putui_base_fdr(va_arg(args, unsigned int), 0,
				"0123456789abcdef", 1);
	else if (flag == 'X')
		i += ft_putui_base_fdr(va_arg(args, unsigned int), 0,
				"0123456789ABCDEF", 1);
	else if (flag == '%')
		i += ft_putchar_fdr('%', 1);
	else
		return (-1);
	return (i);
}

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
			i = ft_dispatch(*str, i++, args);
			if (i < 0)
				return (-1);
		}
		else
		{
			i += ft_putchar_fdr(*str, 1);
			if (i < 0)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (i);
}
