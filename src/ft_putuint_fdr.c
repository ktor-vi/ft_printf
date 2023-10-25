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

#include <unistd.h>

int	ft_putuint_fdr(unsigned int n,int i, int fd)
{
	char	placeholder;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n > 9)
		ft_putuint_fdr(n / 10, i, fd);
	placeholder = (char)(n % 10) + '0';
	write(fd, &placeholder, 1);
	i++;
	return (i);
}
