#include "ft_printf.h"
#include <unistd.h>
int	ft_whatisit(char str, va_list *arg);
void				ft_putchar_fd(char c, int fd);


int	ft_printf(char *str, ...)
{
	va_list	arg;
	size_t	i;
	int	count;
	int	protect;

	if (!str)
		return (-1);	
	va_start(arg, str);
	i = 0;
	count = 0; 
	while (str[i])
	{
		if (str[i] != '%')
		{
			if(ft_putchar(str[i], 1) == 1)
				return (-1);
			count++;
		}
		if (str[i] == '%')
		{
			i++;
			protect = ft_whatisit(str[i], &arg);
			if (protect == -1)
				return (-1);
			count = count + protect;
		}
		i++;
	}
	return (count);
}

int	ft_whatisit(char str, va_list *arg)
{
	size_t	count;

	count = 0;
	if (str == '%')
		count = ft_putchar('%', -1);
	if (str == 'c')
	{
		count = ft_putchar(va_arg(*arg, int), 1);
	}
	if (str == 's')
 		count = ft_putstr(va_arg(*arg, char *), 1);
	if (str == 'i' || str == 'd')
		count = ft_print_putnbr(va_arg(*arg, int));
	if (str == 'u')
		count = ft_print_putnbr(va_arg(*arg, unsigned int));
	if (str == 'x')
		count = ft_putnbr_hex_lower(va_arg(*arg, unsigned int));
	if (str == 'X')
		count = ft_putnbr_hex_upper(va_arg(*arg, unsigned int));
	return (count);
}

