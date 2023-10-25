/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:29 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:41:34 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putint_fdr(int n, int i, int fd)
{
	char	placeholder;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n > 9)
		ft_putint_fdr(n / 10, i, fd);
	placeholder = (char)(n % 10) + '0';
	write(fd, &placeholder, 1);
	i++;
	return (i);
}
