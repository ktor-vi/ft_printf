/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:55:11 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/16 17:55:15 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int	ft_putnbr_fdr(long long n, int i, int fd)
{
	char	placeholder;

	if (n == LONG_MIN)
		return (i += write(fd, "−9223372036854775808", 11));
	else if (n < 0)
	{
		n = -n;
		i += write(fd, "-", 1);
	}
	else if (n == 0)
		return (i += write(fd, "0", 1));
	if (n > 9)
		i = ft_putnbr_fdr(n / 10, i++, fd);
	placeholder = (char)(n % 10) + '0';
	i += write(fd, &placeholder, 1);
	return (i);
}
