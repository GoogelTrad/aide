#include "ft_printf.h"

int	ft_put_hex(long nb, char *base)
{
	int len;

	len = 0;
	ft_conv_hex(nb, base, &len);
	return (len);
}

void ft_conv_hex(long nb, char *base, int *len)
{
	if (nb >= 16)
		ft_conv_hex(nb / 16, base, len);
	ft_putchar(base[nb % 16]);
	(*len)++;
}