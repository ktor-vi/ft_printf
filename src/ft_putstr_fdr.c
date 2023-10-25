/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:46:50 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 19:49:16 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr_fdr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i += write(fd, "(null)", 6);
		if (i < 6)
			return (-1);
		else
			return (6);
	}
	while (i < ft_strlen(s))
	{
		if (write(fd, &s[i], 1) < 0)
			return (-1);
		else
			i++;
	}
	return (ft_strlen(s));
}
