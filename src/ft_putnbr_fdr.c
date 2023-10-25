/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:36 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 19:50:46 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_edge(long long n, int i, int fd)
{
	if (n == LONG_MIN)
	{
		i = write(fd, "−9223372036854775808", 11);
		if (i < 0)
			return (-1);
		else
			return (11);
	}
	else
	{
		if (write(fd, "0", 1) < 0)
			return (-1);
		else
			return (1);
	}
}

int	ft_putnbr_fdr(long long n, int i, int fd)
{
	char	placeholder;

	if (n == 0 || n == LONG_MIN)
		return (ft_edge(n, i, fd));
	if (n < 0)
	{
		n = -n;
		if (write(fd, "-", 1) < 0)
			return (-1);
		else
			i++;
	}
	if (n > 9)
	{
		i = ft_putnbr_fdr(n / 10, i++, fd);
		if (i < 0)
			return (-1);
	}
	placeholder = (char)(n % 10) + '0';
	if (write(fd, &placeholder, 1) < 0)
		return (-1);
	else
		i++;
	return (i);
}
