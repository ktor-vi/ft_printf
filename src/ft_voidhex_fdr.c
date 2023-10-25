#include "../includes/ft_printf.h"
#include <unistd.h>

int	ft_putul_base_fdr(unsigned long nbr, int i, char *base, int fd)
{
	unsigned long	result;
	unsigned long	base_len;

	result = nbr;
	base_len = ft_strllen(base);
	if (base_len > 1 && !find_dupc(base) && !ft_strstr_bool(base, "+")
		&& !ft_strstr_bool(base, "-") && !ft_strstr_bool(base, "\t"))
	{
		if (result == 0)
			 return (i += write(fd, "0", 1));
		if (result < 0 )
			return(-1);
		else if (result >= base_len)
			i = ft_putul_base_fdr(result / base_len, i++, base, fd);
		write(fd, &base[result % base_len], 1);
		i++;
	}
	return (i);
}

int	ft_voidhex_fdr(void *ptr, int i, int fd)
{
	long long	nbr;

	nbr = (long long)ptr;
	write(fd, "0x", 2);
	if (ptr == NULL)
		return (2 + write(fd, "0", 1));
	else
		return (2 + ft_putul_base_fdr(nbr, i, "0123456789abcdef", fd));
}
