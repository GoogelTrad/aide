#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nbr < 0)
		{
			i += ft_putchar('-');
			nbr *= -1;
		}
		if (nbr >= 10)
		{
			i += ft_putnbr(nbr / 10);
			i += ft_putnbr(nbr % 10);
		}
		else
			i+= ft_putchar(nbr + '0');
	}
	return (i);

}
