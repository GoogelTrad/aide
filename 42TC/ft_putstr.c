#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	e;

	e = 0 ;
	while (s[e] != '\0')
	{
		e++;
	}
	return (e);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;
	
	i = 0;
	if (!str)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	len = ft_strlen(str);
	while (str[i])
		write(1, &str[i++], 1);
	return (len);
}