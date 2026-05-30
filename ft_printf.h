#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c, int fd);
int	ft_printf(const char *str, ...);
int    ft_putstr(char *s, int fd);
int     ft_print_putnbr(long long n);
int ft_putnbr_hex_lower(unsigned long n);
int ft_putnbr_hex_upper(unsigned long n);

#endif
