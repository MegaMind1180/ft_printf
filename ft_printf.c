#include "ft_printf.h"
#include <unistd.h>
int	ft_whatisit(char str, va_list *arg);
void				ft_putchar_fd(char c, int fd);

int     ft_printf(char *str, ...)
{
        va_list arg;
        int     count;
        int     protect;

        if (!str)
                return (-1);
        va_start(arg, str);
        count = 0;
        while (*str)
        {
                if (*str++ == '%')
                        protect = ft_whatisit(*str, &arg);
                else
                        protect = ft_putchar(*--str, 1);
                if (protect == -1)
                {
                        va_end(arg);
                        return (-1);
                }
                count += protect;
                str++;
        }
        va_end(arg);
        return (count);
}

int	ft_whatisit(char str, va_list *arg)
{
	if (str == '%')
		return (ft_putchar('%', 1));
	if (str == 'c')
		return (ft_putchar(va_arg(*arg, int), 1));
	if (str == 's')
 		return (ft_putstr(va_arg(*arg, char *), 1));
	if (str == 'i' || str == 'd')
		return (ft_print_putnbr(va_arg(*arg, int)));
	if (str == 'u')
		return (ft_print_putnbr(va_arg(*arg, unsigned int)));
	if (str == 'x')
		return (ft_putnbr_hex_lower(va_arg(*arg, unsigned int)));
	if (str == 'X')
		return (ft_putnbr_hex_upper(va_arg(*arg, unsigned int)));
	if (str == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (ft_putnbr_hex_lower((unsigned long)va_arg(*arg, void *)) + 2);
	}
	return (0);
}

