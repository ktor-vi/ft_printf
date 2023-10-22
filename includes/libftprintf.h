#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_printf(const char *str,
				...);
void	ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd);
void	ft_voidhex_fd(void *ptr, int fd);
#endif
