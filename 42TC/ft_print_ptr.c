#include "ft_printf.h"

void ft_ptr_hex(unsigned long nb, char *base, int *len)
{
	if (nb >= 16)
		ft_ptr_hex(nb / 16, base, len);
	ft_putchar(base[nb % 16]);
	(*len)++;
}

int ft_print_ptr(unsigned long ptr)
{
	int len;

	len = 0;
	len += ft_putstr("0x");
	ft_ptr_hex(ptr, "0123456789abcdef", &len);
	return (len);
}