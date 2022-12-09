#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_forms(va_list args, const char form)
{
	int	len;
	char *base;
	
	len = 0;
	if (form == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (form == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (form == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	else if (form == 'd' || form == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (form == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
	{
		if (form == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
		len += ft_put_hex(va_arg(args, unsigned int),base);
	}
	else if (form == '%')
		len += ft_putchar(form);
	return(len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_forms(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}