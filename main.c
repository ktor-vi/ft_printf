#include "./includes/ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char			*suc;
	long			nbr;
	int				smol;
	unsigned int	uint;
	void			*ptr;

	uint = 4294967295;
	suc = "Success";
	ptr = (void *)suc;
	smol = 42;
	nbr = 7748484204820392;
	// ft_printf("c : %c\ns : %s = Success\np : %p\nd : %d \ni : %i\nu : %u\nx,	%x\nX :%X\n%%", 'z', suc, ptr, nbr, smol,uint, nbr, nbr);
	ft_printf("--------------|%%P FLAG|--------------\n");
	   printf("OG    (empty): %p                     \n", (void *)"");
	ft_printf("|     (empty): %p                     \n", (void *)"");
	ft_printf("|        NULL: %p                     \n", (void *)NULL);
	   printf("OG       NULL: %p                     \n", (void *)NULL);
	ft_printf("|       LLMAX: %p                     \n", (void *)LLONG_MAX);
       printf("OG      LLMAX: %p                     \n", (void *)LLONG_MAX);
	ft_printf("|        LMAX: %p                     \n", (void *)LONG_MAX);
	   printf("OG       LMAX: %p                     \n", (void *)LONG_MAX);
	ft_printf("|        LMAX: %p                     \n", (void *)LONG_MAX);
	   printf("OG       LMAX: %p                     \n", (void *)LONG_MAX);
	ft_printf("|       ULMAX: %p                     \n", (void *)ULONG_MAX);
	   printf("OG      ULMAX: %p                     \n", (void *)ULONG_MAX);
	ft_printf("|      -ULMAX: %p                     \n", (void *)-ULONG_MAX);
	   printf("OG     -ULMAX: %p                     \n", (void *)-ULONG_MAX);
	ft_printf("|        LMIN: %p                     \n", (void *)LONG_MIN);
	   printf("OG       LMIN: %p                     \n", (void *)LONG_MIN);
	ft_printf("|      UI_MAX: %p                     \n", (void *)UINT_MAX);
	   printf("OG     UI_MAX: %p                     \n", (void *)UINT_MAX);
	ft_printf("|       I_MIN: %p                     \n", (void *)INT_MIN);
	   printf("OG      I_MIN: %p                     \n", (void *)INT_MIN);
	ft_printf("|        -val: %p                    \n", (void *)-14523);
	   printf("OG       -val: %p                    \n", (void *)-14523);
	ft_printf("|          -1: %p                     \n", (void *)-1);
	   printf("OG         -1: %p                     \n", (void *)-1);
	ft_printf("|          42: %p                     \n", (void *)42);
	   printf("OG         42: %p                     \n", (void *)42);
	ft_printf("--------------|%%d FLAG|--------------\n");
	ft_printf("|      UI_MAX: %d                     \n", INT_MAX);
	   printf("OG     UI_MAX: %d                     \n", INT_MAX);
    ft_printf("|       I_MIN: %d                     \n", INT_MIN);
	   printf("OG      I_MIN: %d                     \n", INT_MIN);
	   printf("OG         -1: %d                     \n", -1);
	ft_printf("|          42: %d                     \n", 42);
	   printf("OG         42: %d                     \n", 42);
	ft_printf("|         -42: %d                     \n", -42);
	   printf("OG        -42: %d                    \n", -42);

	ft_printf("--------------|%%i FLAG|--------------\n");
	ft_printf("|      UI_MAX: %i                     \n", INT_MAX);
	   printf("OG     UI_MAX: %i                     \n", INT_MAX);
	ft_printf("|       I_MIN: %i                     \n", INT_MIN);
	   printf("OG      I_MIN: %i                     \n", INT_MIN);
	ft_printf("|        -val: %i                    \n", -14523);
	   printf("OG       -val: %i                    \n", -14523);
	ft_printf("|          -1: %i                     \n", -1);
	   printf("OG         -1: %i                     \n", -1);
	ft_printf("|          42: %i                     \n", 42);
	   printf("OG         42: %i                     \n", 42);
	ft_printf("|         -42: %i                     \n", -42);
	   printf("OG        -42: %i                     \n", -42);	

	ft_printf("--------------|%%u FLAG|--------------\n");
	ft_printf("|      UI_MAX: %u                     \n", UINT_MAX);
	   printf("OG     UI_MAX: %u                     \n", UINT_MAX);
       printf("|      UI_MAX: %u                     \n", UINT_MAX);
	   printf("OG     UI_MAX: %u                     \n", UINT_MAX);
	ft_printf("|      UL_MAX: %u                     \n", UINT_MAX);
	   printf("OG     UL_MAX: %u                     \n", UINT_MAX);
       printf("|       L_MAX: %u                     \n", UINT_MAX);
	   printf("OG      L_MAX: %u                     \n", UINT_MAX);

	ft_printf("|           0: %u                     \n", 0);
	   printf("OG          0: %u                     \n", 0);
	ft_printf("|          42: %u                     \n", 42);
	   printf("OG         42: %u                     \n", 42);

	ft_printf("--------------|%%x FLAG|--------------\n");
	
	ft_printf("|       UIMAX: %x                     \n", UINT_MAX);
	   printf("OG      UIMAX: %x                     \n", UINT_MAX);
	ft_printf("|       ULMAX: %x                     \n", ULONG_MAX);
	   printf("OG      ULMAX: %x                     \n", ULONG_MAX);
	ft_printf("|    LONG_MIN: %x                     \n", LONG_MIN);
	   printf("OG   LONG_MIN: %x                     \n", LONG_MIN);
	ft_printf("|    LONG_MAX: %x                     \n", LONG_MAX);
	   printf("OG   LONG_MAX: %x                     \n", LONG_MAX);
	ft_printf("|        -val: %x                    \n", -14523);
	   printf("OG       -val: %x                    \n", -14523);
	ft_printf("|          -1: %x                     \n", -1);
	   printf("OG         -1: %x                     \n", -1);
	ft_printf("|          42: %x                     \n", 42);
	   printf("OG         42: %x                     \n", 42);
	ft_printf("|         -42: %x                     \n", -42);
	   printf("OG        -42: %x                     \n", -42);
    	ft_printf("--------------|%%X FLAG|--------------\n");
	
	ft_printf("|        LMAX: %X                     \n", UINT_MAX);
	   printf("OG       LMAX: %X                     \n", UINT_MAX);
	ft_printf("|        -val: %X                    \n", -14523);
	   printf("OG       -val: %X                    \n", -14523);
	ft_printf("|           1: %X                     \n",1);
	   printf("OG          1: %X                     \n", 1);
	ft_printf("|          42: %X                     \n", 42);
	   printf("OG         42: %X                     \n", 42);
	ft_printf("|          42: %X                     \n", 42);
	   printf("OG         42: %X                     \n", 42);
	return (0);
}
