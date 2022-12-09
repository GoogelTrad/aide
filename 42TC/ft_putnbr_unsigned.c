#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;
	
	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_unsigned(n / 10);
		i += ft_putnbr_unsigned(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
