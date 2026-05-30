#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_putchar(char c, int fd);
int	ft_printf(char *str, ...);
int    ft_putstr(char *s, int fd);
int     ft_print_putnbr(long long n);
int ft_putnbr_hex_lower(unsigned long n);
int ft_putnbr_hex_upper(unsigned int n);
int hexer_pointer(unsigned int n);

#endif
