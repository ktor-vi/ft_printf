#include <unistd.h>
#include "../libft/ft_strlen.c"

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

void	ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd)
{
	unsigned long long	result;
	size_t		base_len;

	result = nbr;
	base_len = ft_strlen(base);
	if (base_len > 1 && !find_dupc(base) && !ft_strstr_bool(base, "+")
		&& !ft_strstr_bool(base, "-") && !ft_strstr_bool(base, "\t"))
	{
		if (result < 0)
		{
			write(1, "-", 1);
			result = -result;
		}
		if (result == 0)
		{
			write(1, "0", 1);
			return ;
		}
		if (result >= (unsigned long long)base_len)
		{
			ft_putnbr_base_fd(result / (unsigned long long)base_len, base, fd);
		}
		write(fd, &base[result % base_len], 1);
	}
}

void ft_voidhex_fd(void *ptr, int fd)
{
  unsigned long long nbr;
  nbr = (unsigned long long)ptr;
  ft_putnbr_base_fd(nbr, "0123456789ABCDEF", fd);
}
