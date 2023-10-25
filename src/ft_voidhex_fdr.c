/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhex_fdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:50 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 19:50:08 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int	ft_putui_base_fdr(unsigned int nbr, int i, char *base, int fd)
{
	unsigned int	result;
	unsigned int	base_len;

	result = nbr;
	base_len = ft_strllen(base);
	if (base_len > 1 && !find_dupc(base) && !ft_strstr_bool(base, "+")
		&& !ft_strstr_bool(base, "-") && !ft_strstr_bool(base, "\t"))
	{
		if (result <= 0)
			return (write(fd, "0", 1));
		else if (result >= base_len)
		{
			i = ft_putui_base_fdr(result / base_len, i++, base, fd);
			if (i < 0)
				return (-1);
		}
		if (write(fd, &base[result % base_len], 1) < 0)
			return (-1);
		else
			i++;
	}
	if (i > 0)
		return (i);
	else
		return (-1);
}

int	ft_putul_base_fdr(unsigned long nbr, int i, char *base, int fd)
{
	unsigned long	result;
	unsigned long	base_len;

	result = nbr;
	base_len = ft_strllen(base);
	if (base_len > 1 && !find_dupc(base) && !ft_strstr_bool(base, "+")
		&& !ft_strstr_bool(base, "-") && !ft_strstr_bool(base, "\t"))
	{
		if (result <= 0)
			return (write(fd, "0", 1));
		else if (result >= base_len)
			i = ft_putul_base_fdr(result / base_len, i++, base, fd);
		if (write(fd, &base[result % base_len], 1) < 0)
			return (-1);
		i++;
	}
	if (i > 0)
		return (i);
	else
		return (-1);
}

int	ft_voidhex_fdr(void *ptr, int i, int fd)
{
	long long	nbr;

	nbr = (long long)ptr;
	if (write(fd, "0x", 2) < 0)
		return (-1);
	if (ptr == NULL)
	{
		if (write(fd, "0", 1) < 0)
			return (-1);
		else
			return (3);
	}
	else
		return (2 + ft_putul_base_fdr(nbr, i, "0123456789abcdef", fd));
}
