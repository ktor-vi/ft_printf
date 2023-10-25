/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fdr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:22:33 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:28:57 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

long	ft_strllen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strstr_bool(char *str, char *to_find)
{
	char	*ptr_str;
	char	*ptr_find;

	if (*to_find == '\0')
		return (0);
	while (*str)
	{
		ptr_str = str;
		ptr_find = to_find;
		while (*ptr_find && *ptr_str == *ptr_find)
		{
			ptr_str++;
			ptr_find++;
		}
		if (*ptr_find == '\0')
			return (1);
		str++;
	}
	return (0);
}

int	find_dupc(char *str)
{
	char	c;
	char	*temp;

	while (*str)
	{
		c = *str;
		temp = str + 1;
		while (*temp)
		{
			if (*temp == c)
			{
				return (1);
			}
			temp++;
		}
		str++;
	}
	return (0);
}

int	ft_putnbr_base_fdr(long long nbr, int i, char *base, int fd)
{
	long long	result;
	long long	base_len;

	result = nbr;
	base_len = ft_strllen(base);
	if (!ft_strncmp(base, "", 1))
		return (11);
	if (base_len > 1 && !find_dupc(base) && !ft_strstr_bool(base, "+")
		&& !ft_strstr_bool(base, "-") && !ft_strstr_bool(base, "\t"))
	{
		if (result < INT_MIN)
			return (write(fd, "0", 1));
		if (result > LONG_MAX)
			result = LONG_MAX;
		else if (result < 0 && i++)
			result *= write(fd, "-", 1) * -1;
		else if (result == 0)
			return (i += write(fd, "0", 1));
		else if (result >= base_len)
			i = ft_putnbr_base_fdr(result / base_len, i++, base, fd);
		write(fd, &base[result % base_len], 1);
		i++;
	}
	return (i);
}
