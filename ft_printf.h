#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../ft_libft/libft.h"
# include <stdarg.h>





int	ft_putchar(char c, int fd);
int	ft_printf(char *str, ...);
size_t    ft_putstr(char *s, int fd);
int     ft_print_putnbr(long long n);

#endif
