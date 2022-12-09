#ifndef PRINTF_H
# define PRINTF_H

/*--------------Librairies----------------*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*--------------Prototypes----------------*/

int ft_putchar(char c);
int ft_forms(va_list args, const char form);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putnbr_unsigned(unsigned int n);
size_t	ft_strlen(const char *s);
void	ft_ptr_hex(unsigned long nb, char *base, int *len);
int	ft_print_ptr(unsigned long ptr);
int	ft_hex_len(unsigned	int nb);
int	ft_put_hex(long nb, char *base);
void	ft_print_hex(unsigned int nb, char *base, const char form);
void ft_conv_hex(long nb, char *base, int *len);

#endif
